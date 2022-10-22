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
const int N=1e5+10;
int n,m,q,k,lst,a,b,c,u[N],v[N],w[N],p[N];
int sa1[N],sa2[N];
int fa[N];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
void merge(int x,int y){x=find(x),y=find(y);fa[x]=y;}
bool chk(int x,int i){
	//ix
	// m log m m (m)
	vector<pair<int,int>>e(m),a,b;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)if(w[sa1[i]]>=x)a.eb(w[sa1[i]]-x,sa1[i]);
	for(int i=1;i<=m;i++)if(w[sa2[i]]<x)b.eb(x-w[sa2[i]],sa2[i]);
	merge(a.begin(),a.end(),b.begin(),b.end(),e.begin());
	for(auto E:e){
		int id=E.se;
		if(find(u[id])^find(v[id])){
			merge(u[id],v[id]);
			if(id==i)return 1;
		}
		if(id==i)return 0;
	}
	exit(1);
}
tuple<int,int,int>kk[N];//
int cnt=0;
int pos[N];ll coef1[N],coef2[N];
ll calc(int x){
	int p=upper_bound(pos+1,pos+1+cnt,x)-pos-1;
	//writeln(coef1[p]*x+coef2[p]);
	return coef1[p]*x+coef2[p];
}
signed main(){
	read(n,m);
	for(int i=1;i<=m;i++)read(u[i],v[i],w[i]);
	iota(sa1+1,sa1+1+m,1);sort(sa1+1,sa1+1+m,[&](int i,int j){return w[i]==w[j]?i<j:w[i]<w[j];});
	iota(sa2+1,sa2+1+m,1);sort(sa2+1,sa2+1+m,[&](int i,int j){return w[i]==w[j]?i<j:w[i]>w[j];});
	read(q,k,a,b,c);
	for(int i=1;i<=m;i++){
		if(!chk(w[i],i))continue;
		int st=w[i],ed=w[i],l,r;
		l=0,r=w[i];while(l<=r)if(chk(mid,i))st=mid,r=mid-1;else l=mid+1;
		l=w[i],r=1e8;while(l<=r)if(chk(mid,i))ed=mid,l=mid+1;else r=mid-1;
		// [l,r]
		kk[++cnt]=mt(st,-1,w[i]);
		kk[++cnt]=mt(w[i]+1,2,-2*w[i]);
		kk[++cnt]=mt(ed+1,-1,w[i]);
	}
	sort(kk+1,kk+1+cnt);
	for(int i=1;i<=cnt;i++)
		pos[i]=get<0>(kk[i]),
		coef1[i]=coef1[i-1]+get<1>(kk[i]),
		coef2[i]=coef2[i-1]+get<2>(kk[i]);
	ll ans=0;int lst=0;
	for(int i=1;i<=q;i++)read(lst),ans^=calc(lst);
	for(int i=q+1;i<=k;i++)lst=(1ll*lst*a+b)%c,ans^=calc(lst);
	writeln(ans);
}