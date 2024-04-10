#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
struct node
{
	int u,v,l,r;
	bool operator<(const node&t)const{return l>t.l;}
};
priority_queue<node> q;
vector<node> e[1000003][2];
int n,m,f[1000003][2];
void solve(int u,int v,int l,int r){
	bool op=l&1;
	if(f[u][op]>=l){
		if(v==n){printf("%lld\n",l+1);exit(0);}
		if(f[v][!op]<r)
		{
			f[v][!op]=r;
			for(node tmp:e[v][!op]) q.push((node){tmp.u,tmp.v,l+1,tmp.r});
			e[v][!op].clear();
		}
	}
	else e[u][op].push_back((node){u,v,l,r});
}
signed main(){
	n=read(),m=read();
	if(n==1) puts("0"),exit(0);
	for(int i=1;i<=m;++i){
		int u=read(),v=read(),l=read(),r=read()-1;
		if((l+r)&1)
			q.push((node){u,v,l,r}),
			q.push((node){u,v,l+1,r+1}),
			q.push((node){v,u,l,r}),
			q.push((node){v,u,l+1,r+1});
		else
			q.push((node){u,v,l,r+1}),
			q.push((node){u,v,l+1,r}),
			q.push((node){v,u,l,r+1}),
			q.push((node){v,u,l+1,r});
	}
	memset(f,0xc0,sizeof(f));
	f[1][0]=0;
	while(!q.empty()){
		node w=q.top();q.pop();
		if(w.l>w.r) continue;
		solve(w.u,w.v,w.l,w.r);
	}
	puts("-1");
	return 0;
}