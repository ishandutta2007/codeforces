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
const int N=1<<18;
int n,a[N],fa[N];ll ans=0;
struct node{
	pair<int,int>mx,se;// 
	node(){mx=se=mp(-1,-1);}
	node(int a,int b){mx=mp(a,b);se=mp(-1,-1);}
	friend node operator+(node a,node b){
		node c;
		c.mx=max(a.mx,b.mx);c.se=mp(-1,-1);
		if(a.mx.se!=c.mx.se)chkmx(c.se,a.mx);
		if(a.se.se!=c.mx.se)chkmx(c.se,a.se);
		if(b.mx.se!=c.mx.se)chkmx(c.se,b.mx);
		if(b.se.se!=c.mx.se)chkmx(c.se,b.se);
		return c;
	}
}f[N];
pair<int,int>mx[N];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
signed main(){
	read(n);
	for(int i=1;i<=n;i++)read(a[i]),ans-=a[i];
	++n;for(int i=1;i<=n;i++)fa[i]=i;
	int cnt=n;
	while(cnt>1){
		//B
		for(int i=0;i<N;i++)f[i]=node();
		for(int i=1;i<=n;i++)f[a[i]]=f[a[i]]+node(a[i],find(i));
		for(int i=1;i<N;i*=2)
			for(int j=0;j<N;j+=2*i)
				for(int k=0;k<i;k++)
					f[j+i+k]=f[j+i+k]+f[j+k];
		for(int i=1;i<=n;i++)mx[find(i)]=mp(-1,-1);
		for(int i=1;i<=n;i++){
			node tmp=f[(N-1)-a[i]];
			if(tmp.mx.se!=find(i)&&tmp.mx.se!=-1)chkmx(mx[find(i)],mp(a[i]+tmp.mx.fi,tmp.mx.se));
			if(tmp.se.se!=find(i)&&tmp.se.se!=-1)chkmx(mx[find(i)],mp(a[i]+tmp.se.fi,tmp.se.se));
		}
		//
		for(int i=1;i<=n;i++)
			if(mx[find(i)].fi!=-1&&find(i)!=find(mx[find(i)].se)){
				cnt--,ans+=mx[find(i)].fi;
				fa[find(i)]=find(mx[find(i)].se);
			}
	}
	writeln(ans);
}