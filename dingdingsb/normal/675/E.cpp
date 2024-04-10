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
mt19937 rnd(random_device{}());
int rint(int l,int r){return uniform_int_distribution<int>(l,r)(rnd);}
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
const int N=1e5+10,M=18;
int n,a[N],mx[N][M];ll s[N],ans=1;
int cmx(int x,int y){if(a[x]<a[y])return y;return x;}
int get(int l,int r){
	int i=__lg(r-l+1);
	return cmx(mx[l][i],mx[r-(1<<i)+1][i]);
}
signed main(){
	read(n);
	for(int i=1;i<n;i++)read(a[i]),mx[i][0]=i;
	s[n-1]=1;mx[n][0]=n;
	for(int j=1;j<M;j++)
		for(int i=1;i+(1<<j)-1<=n;i++)
			mx[i][j]=cmx(mx[i][j-1],mx[i+(1<<(j-1))][j-1]);
	for(int i=n-2;i>=1;i--){
		int u=get(i+1,a[i]);
		s[i]=s[u]+n+u-i-a[i];
		ans+=s[i];
	}
	writeln(ans);
	cerr<<"CF 1145141919810"<<endl;
}