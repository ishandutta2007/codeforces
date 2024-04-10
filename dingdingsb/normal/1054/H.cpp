#pragma GCC optimize(2)
#include<bits/stdc++.h>
namespace in{
	char buf[1<<21],*p1=buf,*p2=buf;
	inline int getc(){return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;}
	template <typename T>inline void read(T& t){
		t=0;int f=0;char ch=getc();while (!isdigit(ch)){if(ch=='-')f = 1;ch=getc();}
		while(isdigit(ch)){t=t*10+ch-48;ch = getc();}if(f)t=-t;
	}
	template <typename T,typename... Args> inline void read(T& t, Args&... args){read(t);read(args...);}
	char getC(){char c=getc();while(!isdigit(c)&&!isalpha(c))c=getc();return c;}
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
//#define STL
struct cpx{
	double x,y;
	cpx operator+(const cpx&b)const{return (cpx){x+b.x,y+b.y};}
	cpx operator-(const cpx&b)const{return (cpx){x-b.x,y-b.y};}
	cpx operator*(const cpx&b)const{return (cpx){x*b.x-y*b.y,x*b.y+y*b.x};}
	cpx operator*(const double&b)const{return (cpx){x*b,y*b};}
	cpx operator/(const double&b)const{return (cpx){x/b,y/b};}
};
cpx conj(cpx a){return (cpx){a.x,-a.y};}
typedef cpx complex;

const int N=2.1e6+10;const double PI=acos(-1);const complex I={0,1};
const int mod=490019,M=sqrt(mod)+1;
inline int ksm(int a,int b){
	int res=1;
	while(b){
		if(b&1)res=1ll*res*a%mod;
		a=1ll*a*a%mod;b>>=1;
	}return res;
}
inline long long num(double d){return d<0?(long long)(d-0.5)%mod:(long long)(d+0.5)%mod;}
int rev[N];complex Wn[N];
inline void set(complex *A0,complex*A1,int pos,int val){
	A0[pos].x=val/M;
	A1[pos].x=val%M;
}
inline long long get(complex*A0,complex*A1,int X){return (M*M*num(A0[X].x)%mod +
			M*(num(A0[X].y)+num(A1[X].x))%mod+num(A1[X].y))%mod;}
inline int ext(int n){int k=0;while((1<<k)<n)k++;return k;}
inline void init(int k){
	int n=1<<k;
	for(register int i=0;i<n;i++)
		rev[i]=(rev[i>>1]>>1)|((i&1)<<(k-1));
	for(register int i=0;i<n;i++)
		Wn[i]={cos(PI/n*i),sin(PI/n*i)};
}
inline void FFT(complex*A,int n,int t){
	if(t<0)for(register int i=1;i<n;i++)if(i<(n-i))std::swap(A[i],A[n-i]);
	for(int i=0;i<n;i++)if(i<rev[i])std::swap(A[i],A[rev[i]]);
	for(register int mid=1;mid<n;mid<<=1){
		for(register int r=mid<<1,j=0;j<n;j+=r){
			int ch=n/mid,now=0;
			for(int k=j;k<j+mid;++k){
				complex X=A[k],Y=Wn[now]*A[k+mid];
				A[k]=X+Y,A[k+mid]=X-Y,now+=ch;
			}
		}
	}
	if(t<0)for(register int i=0;i<n;i++)A[i]=A[i]/n;
}
inline void MTT(complex*A0,complex*A1,int n,int t){
	for(int i=0;i<n;i++)A0[i]=A0[i]+I*A1[i];
	FFT(A0,n,t);
	for(register int i=0;i<n;i++)A1[i]=conj(A0[i?n-i:0]);
	for(register int i=0;i<n;i++){
		complex p=A0[i],q=A1[i];
		A0[i]=(p+q)*0.5;A1[i]=(q-p)*0.5*I;
	}
}
inline void mul(complex*A0,complex*A1,complex*B0,complex*B1,int Alen,int Blen){
	int n=Alen+Blen-1,k=ext(n);init(k);
	MTT(A0,A1,1<<k,1);MTT(B0,B1,1<<k,1);
	for(register int i=0;i<(1<<k);i++){
		complex p=A0[i]*B0[i]+I*A1[i]*B0[i];
		complex q=A0[i]*B1[i]+I*A1[i]*B1[i];
		A0[i]=p,A1[i]=q;
	}
	FFT(A0,1<<k,-1);FFT(A1,1<<k,-1);
}
complex a0[N],a1[N],b0[N],b1[N];
int n,c,m;
#define C(x) ((1ll*x*(x-1)/2)%(mod-1))

int _[M+1],__[M+1];
int powc(int x){return 1ll*_[x%M]*__[x/M]%mod;}
#define C(x) ((1ll*x*(x-1)/2)%(mod-1))
inline void prework(){
	_[0]=__[0]=1;for(int i=1;i<=M;i++)_[i]=1ll*_[i-1]*c%mod;
	for(int i=1;i<=M;i++)__[i]=1ll*__[i-1]*_[M]%mod;
}
int len1,len2;
int val1[N],val2[N];
signed main(){
	in::read(len1,len2,c);
	n=m=mod-1;prework();
	for(int i=0,a;i<len1;i++)in::read(a),val1[1ll*i*i%(mod-1)]+=a;
	for(int i=0,b;i<len2;i++)in::read(b),val2[1ll*i*i*i%(mod-1)]+=b;
	std::cerr<<"done"<<std::endl;
	for(int i=0;i<n;i++)set(a0,a1,n-i,1ll*val2[i]*powc(mod-1-C(i))%mod);
	for(int i=0;i<n+m;i++)set(b0,b1,i,powc(C(i)));
	mul(a0,a1,b0,b1,n+1,n+m);
	int ans=0;
	for(register int i=0;i<m;i++)
		ans+=1ll*val1[i]*powc(mod-1-C(i))%mod*get(a0,a1,i+n)%mod,ans%=mod;
	out::write(ans);out::putc('\n');
	out::flush();
}