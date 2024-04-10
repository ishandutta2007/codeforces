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
const int N=1e5+100;
mt19937 myrnd(random_device{}());
int n,a[N],rt;
int cnt,lc[N],rc[N],rnd[N],sz[N];
ll tk[N],tb[N],val[N];
void pushtag(int x,ll k,ll b){
	if(!x)return;
	tk[x]+=k,tb[x]+=b;
	val[x]+=k*(sz[lc[x]]+1)+b;
}
void pushdown(int x){
	pushtag(lc[x],tk[x],tb[x]),
	pushtag(rc[x],tk[x],tb[x]+tk[x]*(sz[lc[x]]+1)),
	tk[x]=tb[x]=0;
}
void pushup(int x){
	sz[x]=sz[lc[x]]+1+sz[rc[x]];
}
int newnode(ll v){
	int x=++cnt;
	val[x]=v;sz[x]=1;rnd[x]=myrnd();
	return x;
}
ll ask(int x,int k){
	pushdown(x);
	if(k<=sz[lc[x]])return ask(lc[x],k);
	else if(k==sz[lc[x]]+1)return val[x];
	else return ask(rc[x],k-sz[lc[x]]-1);
}
void split(int x,int k,int&a,int &b){
	if(!x)return a=b=0,void();
	pushdown(x);
	if(sz[lc[x]]+1<=k)a=x,split(rc[x],k-sz[lc[x]]-1,rc[a],b);
	else b=x,split(lc[x],k,a,lc[b]);
	pushup(x);
}
int merge(int x,int y){
	if(!x||!y)return x^y;
	pushdown(x);pushdown(y);
	if(rnd[x]<rnd[y]){
		rc[x]=merge(rc[x],y);
		pushup(x);return x;
	}else{
		lc[y]=merge(x,lc[y]);
		pushup(y);return y;
	}
}
void ins(int p,ll v){
	int a,b;split(rt,p,a,b);
	rt=merge(a,merge(newnode(v),b));
}
void mdf(int p,ll K,ll B){
	int a,b;
	split(rt,p,a,b);
	pushtag(b,K,B);
	rt=merge(a,b);
}
ll dfs(int x){
	if(!x)return -0x3f3f3f3f3f3f3f3f;
	pushdown(x);
	return max(dfs(lc[x]),max(val[x],dfs(rc[x])));
}
signed main(){
	read(n);for(int i=1;i<=n;i++)read(a[i]);rt=newnode(0);
	for(int i=1;i<=n;i++){
		int l=0,r=i-2,ans=i-1;
		while(l<=r){
			if(ask(rt,mid+1)+1ll*a[i]*(mid+1)>ask(rt,mid+2))
				ans=mid,r=mid-1;
			else l=mid+1;
		}
		ins(ans+1,ask(rt,ans+1));
		mdf(ans+1,a[i],1ll*a[i]*ans);
	}
	writeln(dfs(rt));
}