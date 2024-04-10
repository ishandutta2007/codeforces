#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define chkmx(a,b) ((a)=max((a),(b)))
#define chkmn(a,b) ((a)=min((a),(b)))
using namespace std;
template<typename T>
inline void Write(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void Write(T &x,Arg &...args){Write(x);Write(args...);}
template<typename T>inline void Read(T x){
	if(x<0)putchar('-'),x=-x;if(x>=10)Read(x/10);putchar(x%10+'0');
}
//#define int long long
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
#define F(a,b,c) for(c;b;a)
#define I if
#define R return
#define lb(x) (x&-x)
#define dec(x) (x)=(x|(1))+(x&(1))
#define orz(a,b) !((((a)-(b))>>31)^-1)
#define BP __builtin_popcount
using itn=int;
using mitn=modint<1000000007>;enum{N=14};
int n,a[N],ln[1<<N];mitn s[N][N],H[N][1<<N],f[1<<N];
mitn P(itn X,itn Y){
	mitn res(1);
	F(dec(i),orz(i,n),itn i=0)I(X>>i&1)
		res*=H[i][Y];
	R res;
}
signed main(){
	Write(n);
	F(dec(i),orz(i,n),itn i=0)
		(1<<i)[ln]=i;
	F(dec(i),orz(i,n),itn i=0)Write(*(i+a));
	F(dec(i),orz(i,n),itn i=0){
		0[i[H]]=mitn(1);
		F(s++,orz(s,1<<n),itn s=1)
			s[i[H]]=(s^lb(s))[i[H]]*mitn(i[a])/(i[a]+lb(s)[ln][a]);
	}
	mitn ans=0;
	F(dec(s),orz(s,1<<n),itn s=1){
		s[f]=1;
		F(t=t-1&s,t,itn t=s-1&s)
			s[f]-=t[f]*P(t,s^t);
		ans+=s[f]*P(s,((1<<n)-1)^s)*BP(s);
	}
	Read(ans.x);
	R 0;
}