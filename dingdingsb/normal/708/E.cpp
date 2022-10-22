// Problem: CF708E Student's Camp
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF708E
// Memory Limit: 250 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
typedef modint<1000000007>mint;
const int N=1.5e3+10;
const int M=1e5+10;
int n,m,a,b,k;
mint D[N],SD[N];
mint SL[N][N],L[N][N],SS[N][N],A,F[N];
mint fac[M],ifac[M];
mint C(int n,int m){
	if(m>n)return 0;
	return fac[n]*ifac[m]*ifac[n-m];
}
signed main(){
	fac[0]=1;for(int i=1;i<M;i++)fac[i]=fac[i-1]*i;
	ifac[M-1]=1/fac[M-1];for(int i=M-1;i;i--)ifac[i-1]=ifac[i]*i;
	cin>>n>>m>>a>>b>>k;
	mint p=mint(a)/b;
	for(int i=0;i<=m&&i<=k;i++)
		D[i]=C(k,i)*(p^i)*((1-p)^k-i);
	for(int i=1;i<=m;i++)
		SD[i]=SD[i-1]+D[i-1];
	F[0]=1;SL[0][m]=1;
	for(int i=1;i<=n;i++){
		for(int r=1;r<=m;r++)
			SL[i][r]=D[m-r]*((F[i-1]-L[i-1][m+1-r])*SD[r]-SS[i-1][r]);
		for(int r=1;r<=m;r++)
			F[i]+=SL[i][r];
		for(int x=2;x<=m+1;x++)
			L[i][x]=L[i][x-1]+SL[i][x-1];
		assert(L[i][m+1].x==F[i].x);
		for(int r=1;r<=m;r++)
			SS[i][r]=SS[i][r-1]+D[r-1]*L[i][r];
	}
	cout<<F[n].x;
}