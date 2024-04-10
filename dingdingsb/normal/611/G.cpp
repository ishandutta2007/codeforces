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
typedef __int128 ll;
#define int ll
const int mod=1e9+7;
struct mint{
	int x;mint(ll o=0){x=(o%mod+mod)%mod;}mint&operator+=(mint a){return(x+=a.x)%=mod,*this;}mint&operator-=(mint a){return(x+=mod-a.x)%=mod,*this;}
	mint&operator*=(mint a){return(x=1ll*x*a.x%mod),*this;}mint&operator^=( int b){mint a=*this;x=1;while(b)(b&1)&&(*this*=a,1),a*=a,b>>=1;return*this;}
	mint&operator/=(mint a){return*this*=(a^=mod-2);}friend mint operator+(mint a,mint b){return a+=b;}friend mint operator-(mint a,mint b){return a-=b;}
	friend mint operator*(mint a,mint b){return a*=b;}friend mint operator/(mint a,mint b){return a/=b;}friend mint operator^(mint a, int b){return a^=b;}
};
#define lowbit(x) ((x)&-(x))
#define mid ((l+r)>>1)
#define lc (x<<1)
#define rc (x<<1|1)
const int N=1e6+100;
int n;ll All;
struct point{
	ll x,y;
	point(ll x=0,ll y=0):x(x),y(y){}
	point operator+(point b){return point(x+b.x,y+b.y);}
	point operator-(point b){return point(x-b.x,y-b.y);}
	ll operator*(point b){return x*b.y-y*b.x;}
}p[N],sum[N];
ll s[N];mint ss[N],ans;
signed main(){
	read(n);
	for(int i=1;i<=n;i++)read(p[i].x,p[i].y),p[i+n]=p[i];
	for(int i=1;i<=n;i++)All+=p[i%n+1]*p[i];
	s[1]=p[1]*p[n];
	for(int i=2;i<=2*n;i++)s[i]=s[i-1]+p[i]*p[i-1];
	for(int i=1;i<=2*n;i++)ss[i]=ss[i-1]+mint(s[i]);
	for(int i=1;i<=2*n;i++)sum[i]=sum[i-1]+p[i];
	for(int i=1,R=1;i<=n;i++){
		while(2*(s[R+1]-s[i]+p[i]*p[R+1])<=All)R++;
		// i-[i+2,R] 
		// i-[R+1,i+n-2] 
		ans-=ss[R]-ss[i+1]-mint(s[i])*(R-i-1)+mint(p[i]*(sum[R]-sum[i+1]));
		ans+=ss[i+n-2]-ss[R]-mint(s[i])*(i+n-2-R)+mint(p[i]*(sum[i+n-2]-sum[R]));
	}
	for(int i=1,R=1;i<=n;i++){
		while(2*(s[R+1]-s[i]+p[i]*p[R+1])<All)R++;
		// i-[i+2,R] 
		// i-[R+1,i+n-2] 
		ans-=ss[R]-ss[i+1]-mint(s[i])*(R-i-1)+mint(p[i]*(sum[R]-sum[i+1]));
		ans+=ss[i+n-2]-ss[R]-mint(s[i])*(i+n-2-R)+mint(p[i]*(sum[i+n-2]-sum[R]));
	}
	writeln((ans/2).x);
}