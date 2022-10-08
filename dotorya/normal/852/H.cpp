#include<stdio.h>
#include<memory.h>
#include<map>
#include<cmath>
#include<stdlib.h>
#include<algorithm>
#include<set>
#include<vector>
#include<queue>

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int MX = 100005;
const int MM = 1000000007;

pii operator-(const pii &l, const pii &r){
	return pii(l.first - r.first, l.second - r.second);
}

ll operator/(const pii &l, const pii &r){
	return (ll)l.first * r.second - (ll)l.second * r.first;
}

pii D[MX];

int sign(pii x){ return x > pii(0, 0)? 0 : 1; }

auto cmp = [](pii l, pii r){
	return sign(l) != sign(r) ? sign(l) < sign(r) : l/r < 0;
};

struct EV{
	pii d;
	int a, b; // a -> b;
	EV(pii d, int a, int b):d(d), a(a), b(b){}
	bool operator<(const EV &l)const{
		return cmp(d, l.d);
	}
};

int N, K;
ll solve(vector<pii> &L){
	sort(L.begin()+1, L.end(), cmp);
	int N = L.size();

	vector<EV> E;
	E.reserve(N*N);
	for(int i = 1; i < N; i++){
		E.emplace_back(L[i] - L[0], 0, i);
		E.emplace_back(L[0] - L[i], i, 0);
	}
	for(int i = 1; i < N; i++){
		for(int j = i+1; j < N; j++){
			int ch = 1;
			for(int k = i+1; k < j; k++){
				if( (L[j] - L[i]) / (L[k] - L[i]) < 0 ){
					ch = 0;
					break;
				}
			}
			if( !ch ) continue;
			E.emplace_back(L[j] - L[i], i, j);
			E.emplace_back(L[i] - L[j], j, i);
		}
	}
	sort(E.begin(), E.end());
	static ll area[205][55] = {};
	memset(area, -1, sizeof(area));
	
	area[0][0] = 0;
	static int cnt = 0;
//	printf("%d\n", ++cnt);
//	for(pii c : L) printf("%d,%d\n", c.first, c.second);
	for(EV e : E){
//		printf("%d -> %d, (%d,%d)\n", e.a, e.b, e.d.first, e.d.second);
		int a = e.a, b = e.b;
		for(int i = 0; i < K; i++){
			if( area[a][i] == -1 ) continue;
			area[b][i+1] = max(area[b][i+1], area[a][i] + L[b] / L[a]);
		}
	}
	return area[0][K];
}

int main()
{
	scanf("%d%d", &N, &K);
	for(int i = 1; i <= N; i++){
		scanf("%d%d", &D[i].first, &D[i].second);
	}
	sort(D+1, D+N+1);
	ll ans = 0;
	for(int i = 1; i <= N; i++){
		vector<pii> L;
		L.push_back(pii(0, 0));
		for(int j = i+1; j <= N; j++) L.push_back(D[j] - D[i]);
		ans = max(ans, solve(L));
	}
	if( ans%2 == 0 ) printf("%lld.00\n", ans/2);
	else printf("%lld.50\n", ans/2);
}