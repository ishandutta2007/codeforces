// Problem: CF538H Summer Dichotomy
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF538H
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define pc putchar
#define chkmx(a,b) (a)=max((a),(b))
#define chkmn(a,b) (a)=min((a),(b))
#define fi first
#define se second
using namespace std;
template<class T>
void read(T&x){x=0;char c=getchar();bool f=0;for(;!isdigit(c);c=getchar())f^=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<class T,class ...ARK>void read(T&x,ARK&...ark){read(x);read(ark...);}
template<class T>void write(T x){if(x<0)pc('-'),x=-x;if(x>=10)write(x/10);pc(x%10+'0');}
template<class T,class ...ARK>void write(T x,ARK...ark){write(x);pc(' ');write(ark...);}
template<class ...ARK>void writeln(ARK...ark){write(ark...);pc('\n');}
typedef long long ll;
const int mod=998244353;
struct mint{
	int x;mint(int o=0){x=o;}mint&operator+=(mint a){return(x+=a.x)%=mod,*this;}mint&operator-=(mint a){return(x+=mod-a.x)%=mod,*this;}
	mint&operator*=(mint a){return(x=1ll*x*a.x%mod),*this;}mint&operator^=( int b){mint a=*this;x=1;while(b)(b&1)&&(*this*=a,1),a*=a,b>>=1;return*this;}mint&operator/=(mint a){return*this*=(a^=mod-2);}
	friend mint operator+(mint a,mint b){return a+=b;}friend mint operator-(mint a,mint b){return a-=b;}friend mint operator*(mint a,mint b){return a*=b;}friend mint operator/(mint a,mint b){return a/=b;}
	friend mint operator^(mint a, int b){return a^=b;}mint operator-(){return 0-*this;}
};
#define lowbit(x) ((x)&-(x))
#define mid ((l+r)>>1)
#define lc (x<<1)
#define rc (x<<1|1)
#define NO puts("IMPOSSIBLE"),exit(0)
const int N=1e5+10;
int n,m,L,R;
int l[N],r[N],n1,n2;
int col[N];
vector<int>e[N];
void dfs(int u){
	for(auto v:e[u])
		if(col[v]==col[u])NO;
		else if(col[v]==-1)col[v]=col[u]^1,dfs(v);
}
signed main(){
	memset(col,0xff,sizeof col);
	read(L,R,n,m);
	n1=1e9,n2=0;
	for(int i=1;i<=n;i++)
		read(l[i],r[i]),chkmn(n1,r[i]),chkmx(n2,l[i]);
	if(n1+n2<L)n2=L-n1;
	if(n1+n2>R)n1=R-n2;
	if(n1<0||n2<0)NO;
	for(int i=1;i<=n;i++){
		bool p1=l[i]<=n1&&n1<=r[i];
		bool p2=l[i]<=n2&&n2<=r[i];
		if(!p1&&!p2)NO;
		if(!p1)col[i]=1;
		if(!p2)col[i]=0;
	}
	for(int i=1,x,y;i<=m;i++)
		read(x,y),e[x].pb(y),e[y].pb(x);
	for(int i=1;i<=n;i++)if(~col[i])dfs(i);
	for(int i=1;i<=n;i++)if(col[i]==-1)col[i]=0,dfs(i);
	puts("POSSIBLE");
	writeln(n1,n2);
	for(int i=1;i<=n;i++)write(col[i]+1);
}