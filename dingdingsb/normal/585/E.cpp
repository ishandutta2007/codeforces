#include<bits/stdc++.h>
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
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
const int mod=1e9+7;
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
const int N=1e7+100;
int n,a[N/20],pr[N/10],tot;
mint miu[N],s[N+1],g[N+1],f[N+1];
bitset<N>npr;
void init(){
	miu[1]=1;
	for(int i=2;i<N;i++){
		if(!npr[i])pr[++tot]=i,miu[i]=mod-1;
		for(int j=1;j<=tot&&i*pr[j]<N;j++){
			npr[i*pr[j]]=1;
			if(i%pr[j])miu[i*pr[j]]=0-miu[i];
			else{miu[i*pr[j]]=0;break;}
		}
	}
}
signed main(){
	init();
	read(n);
	for(int i=1;i<=n;i++)read(a[i]),s[a[i]]+=1;
	for(int i=1;i<=tot;i++)
		for(int j=N/pr[i];j;j--)
			s[j]+=s[j*pr[i]];
	for(int i=1;i<N;i++)
		f[i]=miu[i]*s[i];
	for(int i=1;i<=tot;i++)
		for(int j=1;j<=N/pr[i];j++)
			f[j*pr[i]]+=f[j];
	for(int i=1;i<N;i++)
		g[i]=(mint(2)^s[i].x)-1;
	for(int i=1;i<=tot;i++)
		for(int j=1;j<=N/pr[i];j++)
			g[j]-=g[j*pr[i]];
	mint ans=0;
	for(int i=2;i<N;i++)ans+=g[i]*f[i];
	writeln(ans.x);
}