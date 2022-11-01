//starusc
#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
const int N=1e5+4;
struct edge{
	int v,nxt;
}e[N*10];
int first[N],cnt=1;
inline void add(int u,int v){
	e[++cnt].v=v;e[cnt].nxt=first[u];first[u]=cnt;
}
int n,m,deg[N];
void dfs(int x){
	for(int &i=first[x],v;i;i=e[i].nxt){
		v=e[i].v;
		if(v==-1)continue;
		e[i].v=e[i^1].v=-1;
		dfs(v);
		m^=1;
		if(m)cout<<x<<" "<<v<<"\n";
		else cout<<v<<" "<<x<<"\n";
	}
}
int main(){
	n=read();m=read();
	for(int i=1,u,v;i<=m;i++){
		u=read();v=read();
		add(u,v);add(v,u);
		deg[u]^=1;deg[v]^=1;
	}
	for(int i=1,pre=0;i<=n;i++)if(deg[i]){
		if(pre){add(i,pre);add(pre,i);pre=0;m++;}
		else pre=i;
	}
	if(m&1){add(1,1);add(1,1);m++;}
	cout<<m<<"\n";
	m=0;
	dfs(1);
	return (0-0);
}