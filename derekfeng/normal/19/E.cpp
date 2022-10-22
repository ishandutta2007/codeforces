#include<bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
using namespace std;
vector<int>g[10003],num[10003];
int n,m;
int rt,cnt,d[10003],fr[10003],a[10003];
int res[10003],ans;
void dfs(int x,int par){
	d[x]=d[par]+1;
	for(int i=0;i<g[x].size();i++){
		int to=g[x][i];
		if(to==par)fr[x]=num[x][i];
		else if(d[to]){
			if(d[to]<d[x]){
				if((d[x]-d[to])%2==1)a[x]--,a[to]++;
				else cnt++,res[1]=num[x][i],a[to]--,a[x]++;
			}
		}else dfs(to,x);
	}
}
void sol(int x,int par){
	d[x]=-1;
	for(int i=0;i<g[x].size();i++){
		int to=g[x][i];
		if(d[to]>0){
			sol(to,x);
			a[x]+=a[to];
		}
	}
    if(a[x]==cnt)res[++ans]=fr[x];
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v;scanf("%d%d",&u,&v);
		g[u].push_back(v),g[v].push_back(u);
		num[u].push_back(i),num[v].push_back(i);
	}
	for(int i=1;i<=n;i++){
		if(d[i])continue;
		cnt=0;
		dfs(i,0);
		if(cnt){
			if(rt){puts("0");return 0;}
			rt=i;
			if(cnt==1)ans=1;
			sol(i,0);
		}
	}
	if(!rt){
		printf("%d\n",m);
		for(int i=1;i<=m;i++)printf("%d ",i);
		return 0;
	}
	printf("%d\n",ans);
	if(ans>=1){
		sort(res+1,res+1+ans);
		for(int i=1;i<=ans;i++)printf("%d ",res[i]);
	}
}