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
const int N=1e5+100;
int n,m,a[N],b[N],ls[N],p[N],pp[N];multiset<int>s;
vector<int>as,bs;
int pre(int x){
	//<=x
	return upper_bound(bs.begin(),bs.end(),x)-bs.begin();
}
int c[N];//-1
struct BIT{
	pair<int,int> tree[N];
	BIT(){memset(tree,-0x3f,sizeof tree);}
	void upd(int x,pair<int,int>y){for(;x<=n+3;x+=lowbit(x))chkmx(tree[x],y);}
	pair<int,int>qry(int x){pair<int,int>res=mp(-0x3f3f3f3f,0);for(;x;x-=lowbit(x))chkmx(res,tree[x]);return res;}
	void clr(int x){for(;x<=n+3;x+=lowbit(x))tree[x]=mp(-0x3f3f3f3f,0);}
}T;
pair<int,int>dp[N];
void cdq(int l,int r){
	if(l==r)return;
	cdq(l,mid);
	// [l,mid] -> [mid+1,r]
	vector<pair<int,int>>L,R;
	for(int i=l;i<=mid;i++)if(~a[i])L.eb(p[i]-c[i],i);
	for(int i=mid+1;i<=r;i++)if(~a[i])R.eb(pp[i]-c[i-1],i);
	sort(L.begin(),L.end());sort(R.begin(),R.end());
	reverse(L.begin(),L.end());reverse(R.begin(),R.end());
	int i,j;
	for(i=j=0;i<(int)R.size();i++){
		while(j<(int)L.size()&&L[j].fi>=R[i].fi)
			T.upd(ls[L[j].se],mp(dp[L[j].se].fi-p[L[j].se],L[j].se)),j++;
		auto res=T.qry(ls[R[i].se]-1);res.fi+=pp[R[i].se]+1;
		chkmx(dp[R[i].se],res);
	}
	while(j--)T.clr(ls[L[j].se]);
	reverse(L.begin(),L.end());reverse(R.begin(),R.end());
	for(i=j=0;i<(int)R.size();i++){
		while(j<(int)L.size()&&L[j].fi<R[i].fi)
			T.upd(ls[L[j].se],mp(dp[L[j].se].fi-c[L[j].se],L[j].se)),j++;
		auto res=T.qry(ls[R[i].se]-1);res.fi+=c[R[i].se-1]+1;
		chkmx(dp[R[i].se],res);
	}
	while(j--)T.clr(ls[L[j].se]);
	cdq(mid+1,r);
}
signed main(){
	read(n);for(int i=1;i<=n;i++)read(a[i]),as.pb(a[i]);
	read(m);for(int i=1;i<=m;i++)read(b[i]),bs.pb(b[i]),s.insert(b[i]);
	as.pb(a[0]=-0x3f3f3f3f),as.pb(a[n+1]=0x3f3f3f3f);
	sort(as.begin(),as.end());as.resize(unique(as.begin(),as.end())-as.begin());
	sort(bs.begin(),bs.end());bs.resize(unique(bs.begin(),bs.end())-bs.begin());
	for(int i=1;i<=n+1;i++)c[i]=c[i-1]+(a[i]==-1);
	for(int i=0;i<=n+1;i++)p[i]=pre(a[i]),pp[i]=pre(a[i]-1);
	for(int i=0;i<=n+1;i++)ls[i]=lower_bound(as.begin(),as.end(),a[i])-as.begin()+1;
	memset(dp,-0x3f,sizeof dp);dp[0]=mp(1,0);cdq(0,n+1);
	//writeln(dp[n+1].fi);
	int now=n+1;
	while(now){
		int pre=dp[now].se;
		for(int i=pre,val=a[pre];i<=now;i++)if(a[i]==-1){
			auto it=s.upper_bound(val);
			if(it!=s.end()&&*it<a[now])a[i]=val=*it,s.erase(it);
		}
		now=pre;
	}
	for(int i=1;i<=n;i++)if(a[i]==-1)a[i]=*s.begin(),s.erase(s.begin());
	for(int i=1;i<=n;i++)write(a[i]),pc(' ');
	
}