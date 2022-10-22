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
typedef double db;
const db eps=1e-10;
const int N=1.5e5+10;
int n;ll T;
struct node{
	ll p,t,mnt,mxt;
}a[N];
bool chk(double c){
	double mx=0,tmp=0;
	for(int i=1;i<=n;i++){
		if(a[i].p!=a[i-1].p)chkmx(mx,tmp);
		if((1-c*a[i].mxt/T)*a[i].p<mx)return 0;
		chkmx(tmp,(1-c*a[i].mnt/T)*a[i].p);
	}
	return 1;
}
signed main(){
	read(n);
	for(int i=1;i<=n;i++)read(a[i].p);
	for(int i=1;i<=n;i++)read(a[i].t),T+=a[i].t;
	sort(a+1,a+1+n,[&](node x,node y){return x.p*y.t>x.t*y.p;});
	ll now=0;
	for(int i=1;i<=n;i++){
		int j=i;while(j<n&&a[j+1].p*a[i].t==a[j+1].t*a[i].p)j++;
		for(int k=i;k<=j;k++)a[k].mnt=now+a[k].t;
		for(int k=i;k<=j;k++)now+=a[k].t;
		for(int k=i;k<=j;k++)a[k].mxt=now;
		i=j;
	}
	sort(a+1,a+1+n,[&](node x,node y){return x.p<y.p;});
	db l=0,r=1;
	for(int SJYAKIOI=0;SJYAKIOI<=50;SJYAKIOI++){
		db mid=(l+r)/2;
		if(chk(mid))l=mid;
		else r=mid;
	}
	printf("%.10lf",l);
	cerr<<"";
}