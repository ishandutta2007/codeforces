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

const int N = 1e5+5;
int a[N],b[N];
unordered_map<int,int> loc;
vector<int> locs[N];

struct dsu {
	vector<int> uf,rnk;
	void init(int n) {
		uf.resize(n);
		rnk.resize(n);
		for(int i = 0; i < n; ++i)
			uf[i] = i;
	}

	dsu(){}
	dsu(int n){init(n);}

	int id(int u) {
		return (uf[u]==u)?u:uf[u]=id(uf[u]);
	}
	void merge(int u, int v) {
		if((u = id(u)) == (v = id(v))) return;
		if(rnk[v] < rnk[u]) swap(u,v);
		uf[u] = v, rnk[v] += rnk[u]==rnk[v];
	}
};

dsu U;

int main() {	
	int n;
	scanf("%d",&n);
	U.init(n);
	for(int i = 0; i < n; ++i) {
		scanf("%d",a+i);
		b[i] = a[i];
	}
	sort(b,b+n);
	for(int i = 0; i < n; ++i)
		loc[b[i]] = i;
	for(int i = 0; i < n; ++i)
		U.merge(i,loc[a[i]]);
	for(int i = 0; i < n; ++i) {
		locs[U.id(i)].push_back(i);
	}
	int ans = 0;
	for(int i = 0; i < n; ++i)
		ans += locs[i].size() != 0;
	printf("%d\n",ans);
	for(int i = 0; i < n; ++i) {
		if(locs[i].size()) {
			printf("%d",int(locs[i].size()));
			for(auto a : locs[i])
				printf(" %d",a+1);
			printf("\n");
		}
	}
}