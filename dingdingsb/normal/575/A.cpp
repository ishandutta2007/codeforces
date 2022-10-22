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
int mod;
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
const int N=5e4+100;
ll k;int n,m,a[N];map<ll,int>b;vector<ll>keys;
ll s(ll i){return b.count(i)?b[i]:a[i%n];}
struct matrix{
	mint a00,a01,a10,a11;
	matrix(mint a00=0,mint a01=0,mint a10=0,mint a11=0):a00(a00),a01(a01),a10(a10),a11(a11){}
	matrix operator*(const matrix b)const{return matrix(a00*b.a00+a01*b.a10,a00*b.a01+a01*b.a11,a10*b.a00+a11*b.a10,a10*b.a01+a11*b.a11);}
};
matrix ksm(matrix a,ll b){
	matrix res(1,0,0,1);
	while(b){
		if(b&1)res=res*a;
		a=a*a;b>>=1;
	}
	return res;
}
matrix h(ll i){
	// [f_i-1,f_i-2]  [f_i,f_i-1] 
	return matrix(s(i-1),1,s(i-2),0);
}
struct SGT{
	matrix prod[N<<2];
	void build(int x,int l,int r){
		if(l==r){
			prod[x]=matrix(a[(l-1+n+n)%n],1,a[(l-2+n+n)%n],0);
			return;
		}
		build(lc,l,mid);build(rc,mid+1,r);
		prod[x]=prod[lc]*prod[rc];
	}
	matrix qry(int x,int l,int r,int ql,int qr){
		if(ql<=l&&r<=qr)return prod[x];
		if(r<ql||qr<l)return matrix(1,0,0,1);
		return qry(lc,l,mid,ql,qr)*qry(rc,mid+1,r,ql,qr);
	}
}T;
matrix calc(ll l,ll r){
	// l...r 
	if(l>r)return matrix(1,0,0,1);
	if(l/n==r/n)return T.qry(1,0,n-1,l%n,r%n);
	return T.qry(1,0,n-1,l%n,n-1)*ksm(T.prod[1],r/n-l/n-1)*T.qry(1,0,n-1,0,r%n);
}
signed main(){
	read(k,mod);
	read(n);for(ll i=0;i<n;i++)read(a[i]);
	read(m);for(ll i=1,x;i<=m;i++)read(x),read(b[x]),keys.pb(x+1),keys.pb(x+2);
	keys.pb(k);sort(keys.begin(),keys.end());
	keys.resize(unique(keys.begin(),keys.end())-keys.begin());
	while(keys.back()>k)keys.pop_back();
	T.build(1,0,n-1);
	ll now=1;matrix res(1,0,0,1);
	for(auto x:keys){
		//nowx
		res=res*calc(now+1,x-1)*h(x);
		now=x;
	}
	writeln(res.a00.x);
}