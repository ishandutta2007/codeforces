#pragma GCC optimize(2)
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
	mint operator-(){return 0-*this;}bool operator==(const mint b)const{return x==b.x;}
};
mt19937 rnd(random_device{}());
int rint(int l,int r){return uniform_int_distribution<int>(l,r)(rnd);}
#define lowbit(x) ((x)&-(x))
#define mid ((l+r)>>1)
#define lc (x<<1)
#define rc (x<<1|1)
const int N=2e5+10,M=1e6+10;
int n,tot,pr[N],ans=1e9;ll a[N];bool npr[M];
void init(){
	for(int i=2;i<M;i++){
		if(!npr[i])pr[++tot]=i;
		for(int j=2*i;j<M;j+=i)npr[j]=1;
	}
}
void test(ll pr){
	static set<ll>has;if(has.count(pr))return;
	ll sum=0;has.insert(pr);
	for(int i=1;i<=n;i++)
		sum+=(a[i]<=pr?pr-a[i]:min(a[i]%pr,pr-a[i]%pr));
	if(sum<ans)ans=sum;
}
void work(ll x){
	if(!x)return;
	for(int i=1;i<=tot;i++)if(x%pr[i]==0){test(pr[i]);while(x%pr[i]==0)x/=pr[i];}
	if(x>1)test(x);
}
signed main(){
	init();
	read(n);for(int i=1;i<=n;i++)read(a[i]);
	while(1.*clock()/CLOCKS_PER_SEC<2){
		int pos=rnd()%n+1;
		work(a[pos]);
		work(a[pos]-1);
		work(a[pos]+1);
	}
	writeln(ans);
}