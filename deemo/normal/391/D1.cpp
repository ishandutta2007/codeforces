#include<cstdio>
#include<algorithm>
#include<vector>
#include<numeric>
#include<utility>
#include<set>
#include<cstring>
#include<map>

using namespace std;

typedef long long ll;

#define F first
#define S second
#define X first.first
#define Y first.second

const int MAXN = 5e4 + 10;
const int ZZ = 1e8 + 100;

int n, m;
int x[MAXN], y[MAXN], d[MAXN];
int xx[MAXN], yy[MAXN], dd[MAXN];
map<int, int>	fen;
vector<pair<pair<int, int>, int>>	vec, sec;
multiset<pair<int, int>>	st;

bool cmp(int u, int v){return x[u] < x[v];}

void add(int v, int val){
	for (; v < 3 * ZZ; v += v&-v)
		fen[v] += val;
}

int get(int v){
	int ret = 0;
	for (; v; v-=v&-v)
		ret += fen[v];
	return ret;
}

bool ok(int mid){
	vec.clear();
	sec.clear();
	fen.clear();
	st.clear();
	for (int i = 0; i < n; i++)
		if (d[i] >= 2 * mid)
			vec.push_back({{x[i], y[i] + mid}, d[i] - 2 * mid});
	for (int i = 0; i < m; i++)
		if (dd[i] >= 2 * mid)
			sec.push_back({{xx[i] + mid, yy[i]}, dd[i] - 2 * mid});

	sort(vec.begin(), vec.end());
	sort(sec.begin(), sec.end());
	
	int cur = 0;
	for (int i = 0; i < vec.size(); i++){
		while (cur < sec.size() && sec[cur].X <= vec[i].X)
			st.insert({sec[cur].X + sec[cur].S, sec[cur].Y}), add(sec[cur].Y, 1), cur++;
		while (st.size() && st.begin()->F < vec[i].X)
			add(st.begin()->S, -1), st.erase(st.begin());
			
		if (get(vec[i].Y + vec[i].S) - get(vec[i].Y - 1))	return true;
	}
	return false;
}

int main(){
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)//y
		scanf("%d %d %d", &x[i], &y[i], &d[i]), x[i] += ZZ, y[i] += ZZ;
	
	for (int i = 0; i < m; i++)
		scanf("%d %d %d", &xx[i], &yy[i], &dd[i]), xx[i] += ZZ, yy[i] += ZZ;

	int b = 1, e = 2e8, ret = 0;
	while (b <= e){
		int mid = (b + e)/ 2;
		if (ok(mid))
			ret = mid, b = mid + 1;
		else
			e = mid - 1;
	}
	printf("%d\n", ret);
	return 0;
}