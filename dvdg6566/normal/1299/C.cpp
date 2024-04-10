#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb emplace_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (int)x.size()
#define f first
#define s second
#define MAXN 1000010

ll N,Q,T,a,b,c,d,e;
vpi V;
int p[MAXN];

inline int readInt() {
	int x = 0;
	char ch = _getchar_nolock();
	while (ch < '0' || ch > '9') ch = _getchar_nolock();
	while (ch >= '0' && ch <= '9'){
	x = (x << 3) + (x << 1) + ch - '0';
	ch = _getchar_nolock();
	}
	return x;
}

ld wgt[MAXN];
int sz[MAXN];
int par(int x){return (x == p[x])?x:p[x] = par(p[x]);}
typedef pair<ld, int> pd;
priority_queue<pd, vector<pd>, greater<pd>>pq;

int main(){
	N = readInt();
	for (int i=1;i<=N;++i){
		a = readInt();
		wgt[i] = a;
	}
	for (int i=1;i<=N;++i){
		pq.emplace(wgt[i], i);
	}
	for (int i=1;i<=N;++i){p[i] = i;sz[i]=1;}

	while (SZ(pq)){
		pd t = pq.top();pq.pop();
		t.s = par(t.s);
		if (t.f != wgt[t.s])continue;
		if (t.s == 1)continue;
		int tar = par(t.s - 1);
		if (wgt[tar]<=wgt[t.s])continue;
		// Merging
		ld tot = sz[t.s] * wgt[t.s] + sz[tar] * wgt[tar];
		p[t.s] = tar;
		sz[tar] += sz[t.s];
		wgt[tar] = tot/sz[tar];
		pq.emplace(wgt[tar], tar);
	}
	for (int i=1;i<=N;++i)printf("%.9lf\n", (double)wgt[par(i)]);
}