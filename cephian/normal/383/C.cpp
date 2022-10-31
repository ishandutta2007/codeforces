#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define fio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

const int N = 2e5+5;
vi T[N];

//range ADD update, point VAL query
template <class T>
struct segt {
	int N;
	vector<T> t;
	segt(){}
	segt(int N):N(N),t(2*N){}

	constexpr static T NONE = 0;

	//add val to [l,r]
	inline void update(int l, int r, T val) {
		for(l+=N,r+=N+1;l<r;l>>=1,r>>=1) {
			if(l&1) t[l++] += val;
			if(r&1) t[--r] += val;
		}
	}

	//query point i
	inline T query(int i) const {
		T ans = NONE;
		for(i+=N;i;i>>=1) ans += t[i];
		return ans;
	}
};

int id[N],lst[N],depth[N],ctr = 0;
void dfs(int u, int v, int d = 0) {
	id[v] = ctr++;
	depth[v] = d;
	for(int w : T[v]) {
		if(w == u) continue;
		dfs(v,w,d+1);
	}
	lst[v] = ctr-1;
}

segt<int> seg;
int a[N];

int main() {	
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i = 1; i <= n; ++i)
		scanf("%d",a+i);
	seg = segt<int>(n);
	for(int i = 1; i < n; ++i) {
		int u,v;
		scanf("%d%d",&u,&v);
		T[u].pb(v), T[v].pb(u);
	}
	dfs(-1,1);
	for(int v = 1; v <= n; ++v) {
		if(depth[v]&1) seg.update(id[v],id[v],-a[v]);
		else seg.update(id[v],id[v],a[v]);
	}
	while(m--) {
		int t,v,val;
		scanf("%d%d",&t,&v);
		if(t == 1) {
			scanf("%d",&val);
			if(depth[v]&1) seg.update(id[v],lst[v],-val);
			else seg.update(id[v],lst[v],val);
		} else {
			if(depth[v]&1) printf("%d\n",-seg.query(id[v]));
			else printf("%d\n",seg.query(id[v]));
		}
	}

}