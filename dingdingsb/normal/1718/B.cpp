// Problem: B. Fibonacci Strings
// Contest: Codeforces - Codeforces Round #814 (Div. 1)
// URL: https://codeforces.com/contest/1718/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize(2)
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
	mint&operator*=(mint a){return(x=1ll*x*a.x%mod),*this;}mint&operator^=( int b){mint a=*this;x=1;while(b)(b&1)&&(*this*=a,1),a*=a,b>>=1;return*this;}
	mint&operator/=(mint a){return*this*=(a^=mod-2);}friend mint operator+(mint a,mint b){return a+=b;}friend mint operator-(mint a,mint b){return a-=b;}
	friend mint operator*(mint a,mint b){return a*=b;}friend mint operator/(mint a,mint b){return a/=b;}friend mint operator^(mint a, int b){return a^=b;}
};
#define lowbit(x) ((x)&-(x))
#define mid ((l+r)>>1)
#define lc (x<<1)
#define rc (x<<1|1)
//#define int ll
int T,n,a[110];
int c,f[60];ll g[60],h[60];bool flag;
void dfs(int x,int lst){
	if(x==0)return flag=1,void();
	if(flag)return;
	for(int i=1;i<=n;i++)
		if(a[i]>h[x])return;
	for(int i=1;i<=n;i++)
		if(a[i]>=f[x]&&i!=lst)
			a[i]-=f[x],dfs(x-1,i),a[i]+=f[x];
}
signed main(){
	f[1]=f[2]=h[1]=h[2]=1;
	for(c=3;(f[c]=f[c-2]+f[c-1])<=1e9;c++);
	c--;for(int i=1;i<=c;i++)g[i]=g[i-1]+f[i];
	for(int i=3;i<=c;i++)h[i]=h[i-2]+f[i];
	read(T);
	while(T--){
		ll sum=0;
		read(n);for(int i=1;i<=n;i++)read(a[i]),sum+=a[i];
		if(n>50)puts("NO");
		else{
			flag=0;
			for(int i=1;i<=50;i++)if(g[i]==sum)
				dfs(i,0);
			puts(flag?"YES":"NO");
		}
	}
}