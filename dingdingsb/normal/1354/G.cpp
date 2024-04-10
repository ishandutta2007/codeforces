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
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
int rint(int l,int r){return uniform_int_distribution<int>(l,r)(rnd);}
#define lowbit(x) ((x)&-(x))
#define mid ((l+r)>>1)
#define lc (x<<1)
#define rc (x<<1|1)
int T,n,k;string tmp;
int ask(int l1,int r1,int l2,int r2){
	cout<<"? "<<r1-l1+1<<" "<<r2-l2+1<<endl;
	for(int i=l1;i<=r1;i++)cout<<i<<" ",i==r1&&(cout<<endl,1);
	for(int i=l2;i<=r2;i++)cout<<i<<" ",i==r2&&(cout<<endl,1);
	cin>>tmp;
	if(tmp[0]=='F')return 1;
	if(tmp[0]=='S')return 2;
	return 3;
}
int solve(){
	cin>>n>>k;
	for(int i=1,x;i<=30;i++)if(x=rint(2,n),ask(1,1,x,x)==2)return 1;
	for(int x=1;;x*=2)if(ask(1,x,x+1,min(2*x,n))!=3){
		int l=x+1,r=min(2*x,n),ans;
		while(l<=r){
			if(ask(1,mid-l+1,l,mid)!=3)ans=mid,r=mid-1;
			else l=mid+1;
		}
		return ans;
	}
}
signed main(){
	cin>>T;
	while(T--)cout<<("! "+to_string(solve()))<<endl;
}