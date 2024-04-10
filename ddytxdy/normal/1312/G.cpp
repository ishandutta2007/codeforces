#include<bits/stdc++.h>
using namespace std;
const int N=1e6+50,inf=1e9;
int n,c[N][26],tot,id[N],f[N],m,sz[N],cnt[N],num,rk[N],q[N];char ch;bool fl[N];
int read(){
	int x=0,c;
	while(!isdigit(c=getchar()));
	while(isdigit(c))x=x*10+c-48,c=getchar();
	return x;
}
void dfs(int x){
	sz[x]=cnt[x];num+=cnt[x];rk[x]=num;
	for(int i=0,y;i<26;i++)
		if((y=c[x][i]))dfs(y),sz[x]+=sz[y];
}
void dfs2(int x,int now,int num){
	if(cnt[x])f[x]=min(f[x],rk[x]+now);
	now=min(now,f[x]-num);num+=cnt[x];
	for(int i=0,y;i<26;i++)if((y=c[x][i]))
		f[y]=f[x]+1,dfs2(y,now,num),num+=sz[y];
}
int main(){
	n=read();
	for(int i=1,p;i<=n;i++){
		p=read();scanf("%c",&ch);
		int &x=c[id[p]][ch-'a'];
		if(!x)x=++tot;id[i]=x;
	}
	m=read();
	for(int i=1,x;i<=m;i++)fl[q[i]=read()]=1;
	for(int i=1;i<=n;i++)if(fl[i])cnt[id[i]]++;
	dfs(0);dfs2(0,inf,0);
	for(int i=1;i<=m;i++)printf("%d ",f[id[q[i]]]);
	return 0;
}