#include<bits/stdc++.h>
typedef long long ll;
const int N=1e5+3,M=998244353;
int n,ans,c0,c1,s0,s1,fac[N],invf[N];
char a[N];
inline int Pow(int a,int m){int s=1;for(;m;m>>=1)m&1?s=(ll)s*a%M:0,a=(ll)a*a%M;return s;}
inline int C(int n,int m){return(ll)fac[n]*invf[m]%M*invf[n-m]%M;}
int main(){
	int T;scanf("%d",&T);for(;T--;){
		scanf("%d%s",&n,a+1);
		fac[0]=1;for(int i=1;i<=n;i++)fac[i]=(ll)fac[i-1]*i%M;
		invf[n]=Pow(fac[n],M-2);for(int i=n;i;i--)invf[i-1]=(ll)invf[i]*i%M;
		ans=1,c0=c1=s0=s1=0;
		for(int i=1;i<=n;i++)c0+=a[i]=='0',c1+=a[i]=='1';
		for(int i=1,j;i<=n;i++)
			if(a[i]=='1'&&a[i-1]!='1'){
				for(j=i;a[j+1]=='1';j++);
				if(j-i+1&1)--c1;
			}
		c1/=2;
		ans=(ll)ans*C(c0+c1,c0)%M;
		printf("%d\n",ans);
	}return 0;
}