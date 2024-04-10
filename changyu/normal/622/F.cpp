#include<bits/stdc++.h>
typedef long long ll;
const int M=1e9+7,N=1e6+9;
int n,m,y[N],f,invf[N],g,ans;
inline int Pow(int a,int m){int s=1;for(;m;m>>=1)m&1?s=(ll)s*a%M:0,a=(ll)a*a%M;return s;}
int main(){
	scanf("%d%d",&n,&m);
	f=1;
	for(int i=1;i<=m+2;i++)f=(ll)f*i%M;
	invf[m+2]=Pow(f,M-2);
	for(int i=m+2;i>=1;i--)invf[i-1]=(ll)invf[i]*i%M;
	g=1;
	for(int i=1;i<=m+2&&n-i>0;i++)
	  g=(ll)g*(n-i)%M;
	for(int i=1;i<=m+2;i++){
	  y[i]=(y[i-1]+Pow(i,m))%M;
	  if(i==n)return 0*printf("%d\n",y[i]);
	  ans=(ans+(ll)y[i]*invf[i-1]%M*invf[m+2-i]%M*(m+2-i&1?M-1:1)%M*g%M*Pow(n-i,M-2))%M;
	}printf("%d\n",ans);
	return 0;
}