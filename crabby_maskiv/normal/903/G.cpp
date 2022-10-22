#include<bits/stdc++.h>
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,ll> pil;
const ll inf=0x3f3f3f3f3f3f3f3fll;
const int N=2e5+5;
ll a[N],b[N];
int n,m,q;
struct sgt{
	int l,r,ls,rs;
	ll w,tag;
}s[3*N];
int rt,P;
ll t[N];
inline void upd(int p){
	s[p].w=min(s[s[p].ls].w,s[s[p].rs].w);
}
int build(int l,int r){
	int p=++P;
	s[p].l=l;s[p].r=r;
	s[p].ls=s[p].rs=0;
	s[p].tag=0;
	if(l==r){
		s[p].w=t[l];
		return p;
	}
	int mid=l+r>>1;
	s[p].ls=build(l,mid);
	s[p].rs=build(mid+1,r);
	upd(p);
	return p;
}
inline void pushd(int p){
	s[p].w+=s[p].tag;
	if(s[p].ls) s[s[p].ls].tag+=s[p].tag;
	if(s[p].rs) s[s[p].rs].tag+=s[p].tag;
	s[p].tag=0;
}
void chg(int p,int l,int r,ll w){
	if(s[p].l==l&&s[p].r==r){
		s[p].tag+=w;
		pushd(p);
		return;
	}
	pushd(p);
	int mid=s[p].l+s[p].r>>1;
	if(r<=mid){
		chg(s[p].ls,l,r,w);
		pushd(s[p].rs);
	}
	else if(l>mid){
		chg(s[p].rs,l,r,w);
		pushd(s[p].ls);
	}
	else{
		chg(s[p].ls,l,mid,w);
		chg(s[p].rs,mid+1,r,w);
	}
	upd(p);
}
vector<pil> va[N],vb[N];
ll w[N];
namespace nqio{const unsigned R=4e5,W=4e5;char*a,*b,i[R],o[W],*c=o,*d=o+W,h[40],*p=h,y;bool s;struct q{void r(char&x){x=a==b&&(b=(a=i)+fread(i,1,R,stdin),a==b)?-1:*a++;}void f(){fwrite(o,1,c-o,stdout);c=o;}~q(){f();}void w(char x){*c=x;if(++c==d)f();}q&operator>>(char&x){do r(x);while(x<=32);return*this;}q&operator>>(char*x){do r(*x);while(*x<=32);while(*x>32)r(*++x);*x=0;return*this;}template<typename t>q&operator>>(t&x){for(r(y),s=0;!isdigit(y);r(y))s|=y==45;if(s)for(x=0;isdigit(y);r(y))x=x*10-(y^48);else for(x=0;isdigit(y);r(y))x=x*10+(y^48);return*this;}q&operator<<(char x){w(x);return*this;}q&operator<<(char*x){while(*x)w(*x++);return*this;}q&operator<<(const char*x){while(*x)w(*x++);return*this;}template<typename t>q&operator<<(t x){if(!x)w(48);else if(x<0)for(w(45);x;x/=10)*p++=48|-(x%10);else for(;x;x/=10)*p++=48|x%10;while(p!=h)w(*--p);return*this;}}qio;}using nqio::qio;

int main(){
	int i,j;
	qio>>n>>m>>q;
	for(i=1;i<n;i++) qio>>a[i]>>b[i];
	ll tans=0;
	for(i=1;i<=m;i++){
		int x,y,z;qio>>x>>y>>z;
		va[x].push_back({y,z});
		vb[y].push_back({x,z});
		tans+=z;
	}
	ll sum=0;
	for(i=n-1;i;i--){
		for(auto x:vb[i+1]) sum+=x.sc;
		tans=min(tans,sum+b[i]);
	}
	memcpy(t,b,sizeof(b));
	rt=build(0,n-1);
	for(i=1;i<n;i++){
		for(auto x:va[i])
			chg(rt,0,x.fr-1,x.sc);
		pushd(rt);
		w[i]=s[rt].w;
	}
	for(i=1;i<n;i++) t[i]=w[i]+a[i];
	P=0;
	rt=build(1,n-1);
	qio<<min(tans,s[rt].w)<<'\n';
	while(q--){
		int x,y;qio>>x>>y;
		chg(rt,x,x,y-a[x]);
		a[x]=y;
		qio<<min(tans,s[rt].w)<<'\n';
	}
	return 0;
}