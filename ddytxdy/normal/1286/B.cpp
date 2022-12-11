#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N=2020;
int n,a[N],rt,b[N],sz[N];
vector<int>v[N],vv;
void dfs1(int x){
	sz[x]=1;
	for(int i=0,y;i<v[x].size();i++)
		dfs1(y=v[x][i]),sz[x]+=sz[y];
}
void dfs2(int x,vector<int>p){
	b[x]=p[a[x]];
	// for(int i=0;i<=a[x];i++)
	for(int i=0,y,pos=0;i<v[x].size();i++){
		y=v[x][i];
		vector<int>vv;
		for(int j=0;j<sz[y];j++){
			if(pos==a[x])pos++;
			vv.pb(p[pos]);pos++;
		}
		dfs2(y,vv);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1,f;i<=n;i++){
		scanf("%d%d",&f,&a[i]);
		if(f)v[f].pb(i);else rt=i;
	}
	for(int i=1;i<=n;i++)vv.pb(i);
	dfs1(rt);
	for(int i=1;i<=n;i++)
		if(a[i]>=sz[i])puts("NO"),exit(0);
	dfs2(rt,vv);puts("YES");
	for(int i=1;i<=n;i++)printf("%d ",b[i]);
	return 0;
}