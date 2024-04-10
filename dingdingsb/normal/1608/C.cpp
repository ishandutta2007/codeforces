// Problem: C. Game Master
// Contest: Codeforces - Codeforces Round #758 (Div.1 + Div. 2)
// URL: https://codeforces.com/contest/1608/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define pb push_back
#define pc putchar
#define mp make_pair
#define fi first
#define se second
#define chkmx(a,b) ((a)=max((a),(b)))
#define chkmn(a,b) ((a)=min((a),(b)))
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
//#define int long long
#define lc (x<<1)
#define rc (x<<1|1)
#define mid (l+r>>1)
typedef long long ll;
const int N=1e5+100;
int t,n;
int a[N],b[N],id[N];
int dfn[N],low[N],col[N],deg[N],cnt,tot;bool ins[N];
stack<int>s;
vector<int>e[N];
void dfs(int u){
	dfn[u]=low[u]=++cnt;ins[u]=1;s.push(u);
	for(auto v:e[u]){
		if(!dfn[v])dfs(v),chkmn(low[u],low[v]);
		else if(ins[v])chkmn(low[u],dfn[v]);
	}
	if(dfn[u]==low[u]){
		int tmp=0;++tot;
		while(tmp!=u){
			tmp=s.top();s.pop();
			col[tmp]=tot,ins[tmp]=0;
		}
	}
}

signed main(){
	read(t);
	while(t--){
		read(n);
		for(int i=1;i<=n;i++)read(a[i]);
		for(int i=1;i<=n;i++)read(b[i]);
		for(int i=1;i<=n;i++)id[i]=i;
		for(int i=1;i<=n;i++)dfn[i]=low[i]=col[i]=ins[i]=deg[i]=0,e[i].clear();tot=cnt=0;
		sort(id+1,id+1+n,[&](int i,int j){return a[i]<a[j];});
		for(int i=2;i<=n;i++)e[id[i]].pb(id[i-1]);
		sort(id+1,id+1+n,[&](int i,int j){return b[i]<b[j];});
		for(int i=2;i<=n;i++)e[id[i]].pb(id[i-1]);
		for(int i=1;i<=n;i++)if(!dfn[i])
			dfs(i);
		for(int i=1;i<=n;i++)for(auto j:e[i])if(col[i]!=col[j])deg[col[j]]++;
		for(int i=1;i<=n;i++)
			if(deg[col[i]]==0)pc('1');
			else pc('0');
		pc('\n');
	}
}