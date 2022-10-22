// Problem: CF1547G How Many Paths?
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1547G
// Memory Limit: 500 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define chkmx(a,b) ((a)=max((a),(b)))
#define chkmn(a,b) ((a)=min((a),(b)))
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
//#define int long long
typedef long long ll;
enum{N=400000+100};
int t,n,m;vector<int>e[N],circ,twice;
int vis[N],ins[N];bool Circ[N],Twice[N];
void dfs1(int u){
	if(ins[u])return circ.pb(u),void();
	if(vis[u])return twice.pb(u),void();
	ins[u]=vis[u]=1;
	for(auto v:e[u])dfs1(v);
	ins[u]=false;
}
void dfs2(int u,bool*arr){
	if(arr[u])return;
	arr[u]=1;
	for(auto v:e[u])dfs2(v,arr);
}
signed main(){
	read(t);while(t--){
		read(n,m);circ.clear(),twice.clear();
		for(int i=1;i<=n;i++)vis[i]=Circ[i]=Twice[i]=0,e[i].clear();
		for(int i=1,u,v;i<=m;i++)
			read(u,v),e[u].pb(v);
		dfs1(1);
		for(auto x:circ)dfs2(x,Circ);
		for(auto x:twice)dfs2(x,Twice);
		for(int i=1;i<=n;i++){
			if(!vis[i])write(0);
			else if(Circ[i])write(-1);
			else if(Twice[i])write(2);
			else write(1);
			putchar(' ');
		}
		puts("");
	}
}