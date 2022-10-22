// Problem: CF1221G Graph And Numbers
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1221G
// Memory Limit: 500 MB
// Time Limit: 3500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
const int N=40;
int n,m;
long long e[N];int sum[1<<N/2];
int cnt,gu;int d[N];
long long ans=0;
bool flag=1;bool vis[N];
bool col[N];
void dfs(int u){
	vis[u]=1;
	for(int v=0;v<n;v++)if((e[u]>>v)&1){
		if(vis[v]){
			if(col[u]==col[v])flag=0;
		}else{
			col[v]=col[u]^1;
			dfs(v);
		}
	}
}
int up,lim;
void dfs1(int dep,long long st,long long used){
	if(dep==up)return void(sum[(~st)&(lim-1)]++);
	dfs1(dep-1,st,used);
	if((st>>dep)&1^1)dfs1(dep-1,st|e[dep],used|1<<dep);
}
void dfs2(int dep,long long st,long long used){
	if(dep==up+1)return void(ans-=2*sum[used]);
	dfs2(dep+1,st,used);
	if((st>>dep)&1^1)dfs2(dep+1,st|e[dep],used|1<<dep);
}
signed main(){
	read(n,m);
	if(m==0)return puts("0"),0;
	for(int i=1,x,y;i<=m;i++){
		read(x,y);x--,y--;
		d[x]=d[y]=1;
		e[x]|=1ll<<y;
		e[y]|=1ll<<x;
	}
	ans=1ll<<n;
	for(int i=0;i<n;i++){
		if(!vis[i])cnt++,dfs(i);
		if(d[i]==0)gu++;
	}
	//printf("%d %d\n",cnt,gu);
	ans-=1ll<<cnt;
	ans+=2ll<<gu;
	if(flag)ans+=1ll<<cnt;
	//printf("%lld\n",ans);
	up=(n-1)/2,lim=1<<up+1;
	dfs1(n-1,0,0);
	for(int i=1;i<lim;i<<=1)
		for(int j=0;j<lim;j+=i<<1)
			for(int k=0;k<i;k++)
				sum[j+k]+=sum[i+j+k];
	dfs2(0,0,0);
	write(ans);
}