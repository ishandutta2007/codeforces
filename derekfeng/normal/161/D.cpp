#include<bits/stdc++.h>
using namespace std;
int n,K,l[50003],id[50003],ans;
vector<int>f[50003];
int cnt,nxt[100004],to[100004],head[50004];
inline void add(int f,int t){
	++cnt;
	to[cnt]=t,nxt[cnt]=head[f],head[f]=cnt;
}
int got(int i,int x){
	return l[i]-x>0?f[id[i]][l[i]-1-x]:0;
}
void dfs(int x,int p){
	int s=0;
	for(int i=head[x],y=to[i];i;i=nxt[i],y=to[i])if(y!=p){
		dfs(y,x);
		if(l[y]>l[s])s=y;
	}
	if(!s){
		id[x]=x,l[x]=1,f[x].push_back(1);
		return;
	}
	l[x]=l[s]+1,id[x]=id[s];
	f[id[x]].push_back(1);
	ans+=got(x,K);
	for(int i=head[x],y=to[i];i;i=nxt[i],y=to[i])if(y!=p&&y!=s){
		for(int i=0;i<l[y]&&i<K;i++)
			ans+=got(y,i)*got(x,K-i-1);
		for(int i=0;i<l[y]&&i<K;i++)f[id[x]][l[x]-i-2]+=got(y,i);
	}
}
int main(){
	scanf("%d%d",&n,&K);
	for(int i=1;i<n;i++){
		int u,v;scanf("%d%d",&u,&v);
		add(u,v),add(v,u);
	}
	dfs(1,0);
	printf("%d",ans);
}