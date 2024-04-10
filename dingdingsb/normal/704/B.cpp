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
const int N=5e3+100;
int n,s,e,x[N],a[N],b[N],c[N],d[N];
ll calc(int i,int j){
	if(i>j)return (ll)x[i]-x[j]+c[i]+b[j];
	else return (ll)x[j]-x[i]+d[i]+a[j];
}
int nxt[N];ll res;
signed main(){
	read(n,s,e);
	for(int i=1;i<=n;i++)read(x[i]);
	for(int i=1;i<=n;i++)read(a[i]);
	for(int i=1;i<=n;i++)read(b[i]);
	for(int i=1;i<=n;i++)read(c[i]);
	for(int i=1;i<=n;i++)read(d[i]);
	nxt[s]=e;res=calc(s,e);
	for(int i=1;i<=n;i++)if(i!=s&&i!=e){
		pair<ll,int>mn=mp(0x3f3f3f3f3f3f3f3fll,0);
		for(int j=s;j!=e;j=nxt[j])chkmn(mn,mp(calc(j,i)+calc(i,nxt[j])-calc(j,nxt[j]),j));
		nxt[i]=nxt[mn.se];nxt[mn.se]=i;res+=mn.fi;
	}
	writeln(res);
}