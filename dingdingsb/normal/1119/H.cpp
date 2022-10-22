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
	mint operator-(){return 0-*this;}
};
#define lowbit(x) ((x)&-(x))
#define mid ((l+r)>>1)
#define lc (x<<1)
#define rc (x<<1|1)
const int N=1e5+10,K=17;
int n,k,X;mint u,v,w;
int a[N],b[N],c[N];
mint A[1<<K],B[1<<K],C[1<<K],D[1<<K];
void fwt(mint*a,int n){
	for(int i=1;i<n;i*=2)
		for(int j=0;j<n;j+=2*i)
			for(int k=0;k<i;k++)
				a[j|k]+=a[i|j|k],a[i|j|k]=a[j|k]-2*a[i|j|k];
	
}
signed main(){
	read(n,k,u,v,w);
	for(int i=1;i<=n;i++)read(a[i],b[i],c[i]),a[i]^=c[i],b[i]^=c[i],X^=c[i],A[a[i]]+=1,B[b[i]]+=1,C[a[i]^b[i]]+=1;
	fwt(A,1<<k);fwt(B,1<<k);fwt(C,1<<k);
	for(int i=0;i<(1<<k);i++){
		//a->1/4 (n+x+y+z),b->1/4 (n+x-y-z),c->1/4 (n-x+y-z),d->1/4 (n-x-y+z)
		mint x=A[i],y=B[i],z=C[i];
		mint a=n+x+y+z,b=n+x-y-z,c=n-x+y-z,d=n-x-y+z;
		a/=4,b/=4,c/=4,d/=4;
		D[i]=((w+u+v)^a.x)*((w+u-v)^b.x)*((w-u+v)^c.x)*((w-u-v)^d.x);
	}
	fwt(D,1<<k);mint inv=mint((mod+1)/2)^k;
	for(int i=0;i<1<<k;i++)write((D[i^X]*inv).x),pc(' ');
}