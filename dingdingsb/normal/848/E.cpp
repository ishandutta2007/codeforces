#pragma GCC optimize(2)
#include<bits/stdc++.h>
namespace in{
    #ifndef slow
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
const int mod=998244353;
template<const int mod>
struct modint{
    int x;
    modint<mod>(int o=0){x=o%mod;(x<0)&&(x+=mod);}
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
typedef modint<mod>mint;
mint t[]={0,0,0,24,4,240,204,1316,2988,6720, 
 26200,50248,174280,436904,1140888, 
 3436404,8348748,24631232,64575924, 
 174658944,488230244};// 
mint X[17]={
0,0,4,8,-1,16,-10,4,-12,-48, 
26,-44,15,-16,-4,-4,-1
};
signed main(){
	int n=100000;
	in::read(n);
	// x^n % (1-C)
	vector<mint>res,a;
	res.resize(17);res[0]=1;
	a.resize(17);a[1]=1;
	auto mul=[&](vector<mint>A,vector<mint>B){
		// 
		vector<mint> C;C.resize(40);
		for(int i=0;i<A.size();i++)
			for(int j=0;j<B.size();j++)
				C[i+j]+=A[i]*B[j];
		for(int i=C.size()-1;i>=16;i--){
			if(C[i]!=0){
				for(int k=0;k<=16;k++)
					C[i-k]+=C[i]*X[k];
				C[i]=0;
			}
		} 
		C.resize(17);
		return C;
	} ;
	while(n){
		if(n&1)res=mul(res,a);
		a=mul(a,a);n>>=1;
	}
	mint ans=0;
	for(int i=0;i<=16;i++)
		ans+=res[i]*t[i];
	out::write(ans.x);
	out::flush();
}