#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define ll long long
using namespace std;
const int N=1e6+6;
vector<int> G[N]; int d[N],cnt;
void dfs(int u,int f){
	d[u]=d[f]+1; int c=0;
	rep0(i,G[u].size()){
		int v=G[u][i]; if (v==f) continue;
		dfs(v,u);
		if (G[v].size()==1) cnt+=!c,++c;
		else ++cnt;		
	}
}
int main(){
	int n; scanf("%d",&n);
	rep(i,1,n-1){
		int u,v; scanf("%d%d",&u,&v);
		G[u].push_back(v),G[v].push_back(u);
	}
	rep(i,1,n)
		if (G[i].size()>1){ dfs(i,0); break; }
	bool f=false; int t=-1;
	rep(i,1,n)
		if (G[i].size()==1){
			if (t==-1) t=d[i]&1;
			else if (t!=(d[i]&1)) f=true;
		}
	printf("%d %d\n",f?3:1,cnt);
	return 0;
}