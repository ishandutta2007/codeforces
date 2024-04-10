// Problem: D. Dominoes
// Contest: Codeforces - Codeforces Round #758 (Div.1 + Div. 2)
// URL: https://codeforces.com/contest/1608/problem/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define pb push_back
#define pc putchar
#define mp make_pair
#define fi first
#define se second
#define chkmx(a,b) ((a)=max((a),(b)))
#define chkmn(a,b) ((a)=min((a),(b)))
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
//#define int long long
#define lc (x<<1)
#define rc (x<<1|1)
#define mid (l+r>>1)
typedef long long ll;
template<const int mod>
struct modint{
    int x;
    modint<mod>(int o=0){x=o;}
    modint<mod> &operator = (int o){return x=o,*this;}
    modint<mod> &operator +=(modint<mod> o){return x=x+o.x>=mod?x+o.x-mod:x+o.x,*this;}
    modint<mod> &operator -=(modint<mod> o){return x=x-o.x<0?x-o.x+mod:x-o.x,*this;}
    modint<mod> &operator *=(modint<mod> o){return x=1ll*x*o.x%mod,*this;}
    modint<mod> &operator ^=(int b){
        modint<mod> a=*this,c=1;
        for(;b;b>>=1,a*=a)if(b&1)c*=a;
        return x=c.x,*this;
    }
    modint<mod> &operator /=(modint<mod> o){return *this *=o^=mod-2;}
    modint<mod> &operator +=(int o){return x=x+o>=mod?x+o-mod:x+o,*this;}
    modint<mod> &operator -=(int o){return x=x-o<0?x-o+mod:x-o,*this;}
    modint<mod> &operator *=(int o){return x=1ll*x*o%mod,*this;}
    modint<mod> &operator /=(int o){return *this *= ((modint<mod>(o))^=mod-2);}
    template<class I>friend modint<mod> operator +(modint<mod> a,I b){return a+=b;}
    template<class I>friend modint<mod> operator -(modint<mod> a,I b){return a-=b;}
    template<class I>friend modint<mod> operator *(modint<mod> a,I b){return a*=b;}
    template<class I>friend modint<mod> operator /(modint<mod> a,I b){return a/=b;}
    friend modint<mod> operator ^(modint<mod> a,int b){return a^=b;}
    friend bool operator ==(modint<mod> a,int b){return a.x==b;}
    friend bool operator !=(modint<mod> a,int b){return a.x!=b;}
    bool operator ! () {return !x;}
    modint<mod> operator - () {return x?mod-x:0;}
    modint<mod> &operator++(int){return *this+=1;}
};
using mint=modint<998244353>;
const int N=1e5+100,M=3e5+100;
int n;
char c[N][2];
mint fac[M],ifac[M];
mint C(int n,int m){return fac[n]*ifac[m]*ifac[n-m];}
signed main(){
	fac[0]=ifac[0]=1;
	for(int i=1;i<M;i++)fac[i]=fac[i-1]*i,ifac[i]=1/fac[i];
	read(n);int bl=0,wh=0;
	for(int i=1;i<=n;i++){
		scanf("%s",c[i]);
		for(int j=0;j<2;j++)
			if(c[i][j]=='B')c[i][j]=0,bl++;
			else if(c[i][j]=='W')c[i][j]=1,wh++;
			else c[i][j]=2;
	}
	if(bl<=n&&wh<=n){
		mint ans=C(2*n-bl-wh,n-bl);
		int x=0,y=0,all=0;
		// x = 1(0/2) (1/2)0
		// y = 0(1/2) (0/2)1
		for(int i=1;i<=n;i++){
			if(c[i][0]==2&&c[i][1]==2)all++;
			else if((c[i][0]==1||c[i][0]==2)&&(c[i][1]==0||c[i][1]==2))x++;
			else if((c[i][0]==0||c[i][0]==2)&&(c[i][1]==1||c[i][1]==2))y++;
		}
		//printf("%d %d %d\n",x,y,all);
		if(x+y+all==n){
			//
			ans-=(mint(2)^all);
			if(!x)ans+=1;
			if(!y)ans+=1;
		}
		write(ans.x);
	}else puts("0");
}