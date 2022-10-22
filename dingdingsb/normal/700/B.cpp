#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
#define TP long long
#define int long long
inline TP read(){
	TP x=0;char c=getchar();bool k=false;
	for(;!isdigit(c);c=getchar())k|=c=='-';
	for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+c-'0';
	if(k)x=-x;return x;
}
void write(TP x){
	if(x<0)putchar('-'),x=-x;
	if(x>=10)write(x/10);
	putchar(x%10+'0');
}
const int maxn=2e5+100;
struct Graph{
	struct node{
		int v;
		int nxt;
	}e[2*maxn];
	int head[maxn],cnt;
	void add(int u,int v){
		cnt++;
		e[cnt].v=v;e[cnt].nxt=head[u];
		head[u]=cnt;
		
		swap(u,v);
		cnt++;
		e[cnt].v=v;e[cnt].nxt=head[u];
		head[u]=cnt;
		
	}
}G;
int n,k;
int fa[maxn];
int size[maxn];
int ans=0;
void dfs(int rt){
	for(int i=G.head[rt];i;i=G.e[i].nxt)
		if(G.e[i].v!=fa[rt])
			fa[G.e[i].v]=rt,dfs(G.e[i].v),size[rt]+=size[G.e[i].v];
}
signed main(){
	n=read();k=read();
	for(int i=1;i<=k*2;i++)
		size[read()]++;
	for(int i=1;i<n;i++)
		G.add(read(),read());
	dfs(1);
	for(int i=1;i<=n;i++)
		ans+=min(size[i],2*k-size[i]);
	write(ans);
}