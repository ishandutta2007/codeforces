#include<bits/stdc++.h>
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
const int N=1e6+100;
const int mod=998244353;
typedef modint<mod> mint;
mint fac[N],ifac[N];
char str[N];
int S3[N],S4[N];
mint C(int n,int m){
	if(n<m||n<0||m<0)return 0;
	return fac[n]*ifac[m]*ifac[n-m];
}
signed main(){
	fac[0]=1;for(int i=1;i<N;i++)fac[i]=i*fac[i-1];
	ifac[N-1]=mint(1)/fac[N-1];for(int i=N-1;i;i--)ifac[i-1]=ifac[i]*i;
	
	scanf("%s",str+1);int n=strlen(str+1);
	for(int i=n;i;i--){
		S3[i]=S3[i+1],S4[i]=S4[i+1];
		S3[i]+=str[i]==')';
		S4[i]+=str[i]=='?';
	}
	mint ans=0;
	int s1=0,s2=0,s3,s4;
	for(int i=1;i<n;i++){
		s1+=str[i]=='(';
		s2+=str[i]=='?';
		s3=S3[i+1];
		s4=S4[i+1];
		ans+=s1*C(s2+s4,s4+s3-s1);
		ans+=s2*C(s2+s4-1,s3+s4-s1-1);
	}
	printf("%d",ans);
	return 0;
}