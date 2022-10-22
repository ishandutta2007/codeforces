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
#define orz puts("-1"),exit(0)
const int N=4e5+100;
int n,m,d,B,G;vector<int>b[N],g[N];
void exgcd(int a,int b,ll&x,ll&y){
	if(!b)return x=1,y=0,void();
	exgcd(b,a%b,x,y);
	tie(x,y)=mp(y,x-(a/b)*y);
}
int inv(int a,int mo){ll x,y;exgcd(a,mo,x,y);return (x%mo+mo)%mo;}
ll dis[N];vector<pair<int,ll>>e[N];bool vis[N];
ll calc(vector<int>&b,vector<int>&g){
	if(b.size()+g.size()==0)orz;
	map<int,int>c;
	for(auto x:b)c[x]++;
	for(auto x:g)c[x]++;
	if((int)c.size()==n){
		for(int i=m-1;~i;i--)if(c[i]==1)return i;
		return -1;
	}
	vector<int>s;
	for(auto x:b)s.pb(x),s.pb((x-m+n)%n);
	for(auto x:g)s.pb(x),s.pb((x-m+n)%n);
	int invm=inv(m,n);assert(1ll*invm*m%n==1);
	sort(s.begin(),s.end());s.resize(unique(s.begin(),s.end())-s.begin());
	sort(s.begin(),s.end(),[&](int i,int j){return 1ll*i*invm%n<1ll*j*invm%n;});
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>q;
	for(int i=0;i<(int)s.size();i++)e[i].clear(),dis[i]=0x3f3f3f3f3f3f3f3f,vis[i]=0;
	for(int i=0;i<(int)s.size();i++)if(c.count(s[i]))q.push(mp(dis[i]=s[i],i));
	for(int i=0;i<(int)s.size();i++)
		e[i].eb(mp((i+1)%s.size(),(1ll*s[(i+1)%s.size()]*invm%n-1ll*s[i]*invm%n+n)%n*m));
	while(q.size()){
		int u=q.top().se;q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto E:e[u]){
			int v;ll w;tie(v,w)=E;
			if(dis[v]>dis[u]+w)
				q.push(mp(dis[v]=dis[u]+w,v));
		}
	}
	ll res=0;
	for(int i=0;i<(int)s.size();i++)chkmx(res,dis[i]);
	return res;
}
signed main(){
	read(n,m);d=__gcd(n,m);n/=d,m/=d;
	if(d>2e5)orz;
	read(B);for(int i=1,x;i<=B;i++)read(x),b[x%d].pb(x/d);
	read(G);for(int i=1,x;i<=G;i++)read(x),g[x%d].pb(x/d);
	if(n<m)swap(n,m),swap(b,g);
	ll ans=0;
	for(int i=0;i<d;i++)chkmx(ans,d*calc(b[i],g[i])+i);
	writeln(ans);
	cerr<<"";
}