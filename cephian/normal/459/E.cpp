#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;

int n,m;
const int N = 3e5+5;
int ans[N]={};
map<int,vector<pii>> E; 
vector<pii> updates;

int main() {	
	scanf("%d%d",&n,&m);
	while(m--) {
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		E[w].emplace_back(u,v);
	}
	for(auto &p : E) {
		for(auto &q : p.se)
			updates.emplace_back(ans[q.fi]+1,q.se);
		while(updates.size()) {
			int v = updates.back().se, w = updates.back().fi;
			updates.pop_back();
			ans[v] = max(ans[v],w);
		}
	}
	int a=0;
	for(int v = 1; v <= n; ++v)
		a = max(a,ans[v]);
	printf("%d\n",a);
}