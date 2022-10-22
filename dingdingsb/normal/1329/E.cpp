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
#define int ll
const int N=6e5+100;
int n,m,k,a[N],b[N],f[N],g[N],pre[N],p[N];
void solve(){
	read(m,n,k);
	for(int i=1;i<=n;i++)read(a[i]);
	k+=n+1;
	for(int i=1;i<=n;i++)b[i]=a[i]-a[i-1];
	b[n+1]=m-a[n];n++;
	int l=1,r=m,L,R;
	while(l<=r){
		int sum=0;
		for(int i=1;i<=n;i++)sum+=(b[i]+mid-1)/mid;
		if(sum<=k)R=mid,r=mid-1;
		else l=mid+1;
	}
	l=1,r=m;
	for(int i=1;i<=n;i++)chkmn(r,b[i]);
	while(l<=r){
		int sum=0;
		for(int i=1;i<=n;i++)sum+=b[i]/mid;
		if(sum>=k)L=mid,l=mid+1;
		else r=mid-1;
	}
	for(int i=1,t;i<=n;i++){
		t=b[i]/L;g[i]=max(R,(b[i]+t-1)/t);
		t=(b[i]+R-1)/R;f[i]=min(L,b[i]/t);
		p[i]=i;
	}
	sort(p+1,p+1+n,[&](int i,int j){return f[i]<f[j];});
	pre[0]=R;for(int i=1;i<=n;i++)pre[i]=max(pre[i-1],g[p[i]]);
	int ans=pre[n]-L;
	for(int i=n;i;i--)chkmn(ans,pre[i-1]-f[p[i]]);
	writeln(ans);
}
signed main(){
	int T;read(T);
	while(T--)solve();
	cerr<<""<<endl;
}