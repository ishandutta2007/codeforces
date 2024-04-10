#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define faster
namespace in{
	#ifdef faster
	char buf[1<<21],*p1=buf,*p2=buf;
	inline int getc(){return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;}
	#else
	inline int getc(){return getchar();}
	#endif
	template <typename T>inline void read(T& t){
		t=0;int f=0;char ch=getc();while (!isdigit(ch)){if(ch=='-')f = 1;ch=getc();}
	    while(isdigit(ch)){t=t*10+ch-48;ch = getc();}if(f)t=-t;
	}
	template <typename T,typename... Args> inline void read(T& t, Args&... args){read(t);read(args...);}
}
namespace out{
	char buffer[1<<21];int p1=-1;const int p2 = (1<<21)-1;
	inline void flush(){fwrite(buffer,1,p1+1,stdout),p1=-1;}
	inline void putc(const char &x) {if(p1==p2)flush();buffer[++p1]=x;}
	template <typename T>void write(T x) {
		static char buf[15];static int len=-1;if(x>=0){do{buf[++len]=x%10+48,x/=10;}while (x);}else{putc('-');do {buf[++len]=-(x%10)+48,x/=10;}while(x);}
		while (len>=0)putc(buf[len]),--len;
	}
}
using namespace std;
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
const int N=4e6+5;

const int mod=998244353;
const modint<mod> GG=3,Ginv=modint<mod>(1)/3;
struct poly{
	vector<modint<mod>>a;
	modint<mod>&operator[](int i){return a[i];}
	int size(){return a.size();}
	void resize(int n){a.resize(n);}
	void reverse(){std::reverse(a.begin(),a.end());}
	void print(){for(auto x:a)printf("%d ",x);puts("");}
};
int rev[N];
inline poly one(){poly a;a.a.push_back(1);return a;}
inline int ext(int n){int k=0;while((1<<k)<n)k++;return k;}
inline void init(int k){int n=1<<k;for(int i=0;i<n;i++)rev[i]=(rev[i>>1]>>1)|((i&1)<<(k-1));}
inline void ntt(poly&a,int k,int typ){
	int n=1<<k;
	for(int i=0;i<n;i++)if(i<rev[i])swap(a[i],a[rev[i]]);
	for(int mid=1;mid<n;mid<<=1){
		modint<mod> wn=(typ>0?GG:Ginv)^((mod-1)/(mid<<1));
		for(int r=mid<<1,j=0;j<n;j+=r){
			modint<mod> w=1;
			for(int k=0;k<mid;k++,w=w*wn){
				modint<mod> x=a[j+k],y=w*a[j+k+mid];
				a[j+k]=x+y,a[j+k+mid]=x-y;
			}
		}
	}
	if(typ<0){
		modint<mod> inv=modint<mod>(1)/n;
		for(int i=0;i<n;i++)a[i]*=inv;
	}
}
poly operator +(poly a,poly b){
	int n=max(a.size(),b.size());a.resize(n),b.resize(n);
	for(int i=0;i<n;i++)a[i]+=b[i];return a;
}
poly operator -(poly a,poly b){
	int n=max(a.size(),b.size());a.resize(n),b.resize(n);
	for(int i=0;i<n;i++)a[i]-=b[i];return a;
}
inline poly operator*(poly a,poly b){
	int n=a.size()+b.size()-1,k=ext(n);
	a.resize(1<<k),b.resize(1<<k),init(k);
	ntt(a,k,1);ntt(b,k,1);for(int i=0;i<(1<<k);i++)a[i]*=b[i];
	ntt(a,k,-1),a.resize(n);return a;
}
inline poly operator*(poly a,modint<mod> b){for(int i=0;i<a.size();i++)a[i]*=b;return a; }
inline poly operator/(poly a,modint<mod> b){for(int i=0;i<a.size();i++)a[i]/=b;return a; }
inline poly operator-(poly a){for(int i=0;i<a.size();i++)a[i]=-a[i];return a; }
typedef modint<mod> mint;
mint fac[N],ifac[N];
poly next(poly f,mint c){
	poly g;g.resize(f.size());
	for(int i=0;i<f.size();i++)f[i]*=fac[i];f.reverse();
	for(int i=0;i<f.size();i++)g[i]=(c^i)*ifac[i];
	//f.print();g.print();
	g=g*f;g.resize(f.size());g.reverse();for(int i=0;i<f.size();i++)g[i]*=ifac[i];
	//g.print();
	return g;
}
poly solve(int n){
	if(n==0){return one();}
	int m=n/2;
	poly F=solve(m);
	F.resize(m+1);F=F*next(F,mint(m));F.resize(n+1);
	if(n&1){for(int i=n;i;i--)F[i]=F[i]*(n-1)+F[i-1];F[0]*=(n-1);}
	//printf("%d: ",n);F.print();
	return F;
}
mint C(int n,int m){
	if(m>n)return 0;
	return fac[n]*ifac[m]*ifac[n-m];
}
signed main(){
	int n=3,a,b;in::read(n,a,b);
	fac[0]=1;for(int i=1;i<=n;i++)fac[i]=fac[i-1]*i;
	ifac[n]=mint(1)/fac[n];for(int i=n;i;i--)ifac[i-1]=ifac[i]*i;
	poly F=solve(n-1);F.resize(a+b);
	//for(int i=0;i<=n;i++)out::write(F[i].x),out::putc(' ');
	mint ans=F[a+b-2]*C(a+b-2,a-1);
	out::write(ans.x); 
	out::flush();
	return 0;
}