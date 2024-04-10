#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

const int N=2000005,K=200000;
struct edge{int v,l,id;}e[N];
int ans[N],h[N],vis[N],deg[N],n,m,x,y,col;

void dfs(int u){
	while(~h[u]){
		int k=h[u];
		h[u]=e[k].l;
		if(vis[k])continue;
		vis[k^1]=1;
		dfs(e[k].v);
		ans[e[k].id]=(e[k].v>K);
	}
}

int main(){
	read(n);
	rep(i,1,2*K)h[i]=-1;
	rep(i,1,n){
		read(x),read(y);
		e[m]=(edge){y+K,h[x],i},h[x]=m++;
		e[m]=(edge){x,h[y+K],i},h[y+K]=m++;
		deg[x]++,deg[y+K]++;
	}
	int las=-1;
	rep(i,1,2*K)
		if(deg[i]&1)
			if(las==-1)las=i;
			else{
				e[m]=(edge){i,h[las],n+1},h[las]=m++;
				e[m]=(edge){las,h[i],n+1},h[i]=m++;
				las=-1;
			}
	rep(i,1,2*K)dfs(i);
	rep(i,1,n)putchar(ans[i]?'r':'b');
	return 0;
}