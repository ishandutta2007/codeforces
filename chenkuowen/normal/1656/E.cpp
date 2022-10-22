#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5+1e6;
int sz[N],a[N];
vector<int> e[N];
void dfs(int x,int pre,int sz_x,int sz_rt){
	a[x]=sz_x;
	for(auto y:e[x]){
		if(y!=pre){
			a[x]-=sz_rt-sz_x;
			dfs(y,x,sz_rt-sz_x,sz_rt);
		}
	}
}
int main(){
	int T; scanf("%d",&T);
	while(T--){
		int n; scanf("%d",&n);
		for(int i=1;i<=n;++i) e[i].clear();
		for(int i=1;i<n;++i){
			int x,y; scanf("%d%d",&x,&y);
			e[x].push_back(y);
			e[y].push_back(x);
		}
		int rt=1;
		for(int i=1;i<=n;++i)
			if(e[i].size()>e[rt].size()) rt=i;
		a[rt]=1; 
		for(auto x:e[rt]){
			a[rt]-=-1;
			dfs(x,rt,-1,1);
		}
		for(int i=1;i<=n;++i) printf("%d ",a[i]); puts("");
	}
	return 0;
}