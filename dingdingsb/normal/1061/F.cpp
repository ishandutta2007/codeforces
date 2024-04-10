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
int n,k;string tmp;
map<tuple<int,int,int>,bool>vis;
bool ask(int a,int b,int c){
	if(b==a||b==c)return 1;
	if(vis.count(mt(a,b,c)))return vis[mt(a,b,c)];
	cout<<"? "<<a<<" "<<b<<" "<<c<<endl;
	cin>>tmp;return vis[mt(a,b,c)]=(tmp=="Yes");
}
int ask(int x,int y){
	int ans=0;
	for(int i=1;i<=n;i++)ans+=ask(x,i,y);
	return ans;
}
signed main(){
	cin>>n>>k;
	int dep=0,now=1,sum=1;
	while(sum<n)now*=k,sum+=now,dep++;
	int px,py;
	while(1){
		px=rint(1,n),py=rint(1,n);
		if(px==py)continue;
		if(ask(px,py)==2*dep+1)break;
	}
	for(int i=1;i<=n;i++)if(ask(px,i,py))
		if(ask(i,px)==dep+1)return cout<<"! "<<i<<endl,0;
}