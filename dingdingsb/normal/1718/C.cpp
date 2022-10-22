// Problem: C. Tonya and Burenka-179
// Contest: Codeforces - Codeforces Round #814 (Div. 1)
// URL: https://codeforces.com/contest/1718/problem/C
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
const int N=2e5+100;
int T,n,m,a[N],tot,pr[N];
priority_queue<pair<ll,int>>q;
ll sum[N*30];int cnt,fac[30],st[30];
bool npr[N];
void out(){
	while(sum[q.top().se]!=q.top().fi)q.pop();
	writeln(q.top().fi);
}
signed main(){
	for(int i=2;i<N;i++){
		if(!npr[i])pr[++tot]=i;
		for(int j=1;i*pr[j]<N&&j<=tot;j++)
			npr[i*pr[j]]=1;
	}
	read(T);
	while(T--){
		read(n,m);cnt=0;while(q.size())q.pop();
		for(int i=2;i<=n;i++)if(n%i==0&&!npr[i])
			cnt++,fac[cnt]=n/i,st[cnt+1]=st[cnt]+fac[cnt];
		for(int j=0;j<st[cnt+1];j++)sum[j]=0;
		for(int i=1;i<=n;i++){
			read(a[i]);
			for(int j=1;j<=cnt;j++)
				sum[st[j]+(i%fac[j])]+=1ll*a[i]*fac[j];
		}
		for(int j=0;j<st[cnt+1];j++)q.emplace(sum[j],j);
		out();
		while(m--){
			int p,x;read(p,x);
			for(int j=1;j<=cnt;j++)sum[st[j]+(p%fac[j])]-=1ll*a[p]*fac[j];
			a[p]=x;
			for(int j=1;j<=cnt;j++)sum[st[j]+(p%fac[j])]+=1ll*a[p]*fac[j],q.emplace(sum[st[j]+(p%fac[j])],st[j]+(p%fac[j]));
			out();
		}
	}
}