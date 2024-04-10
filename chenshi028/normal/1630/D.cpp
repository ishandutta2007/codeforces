#include<cstdio>
#include<iostream>
using namespace std;
const int o=1e6+10;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int T,n,m,a[o],g;long long f[o][2],z0,z1;
int main(){
	for(scanf("%d",&T);T--;printf("%lld\n",max(z0,z1)),g=z0=z1=0){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i) scanf("%d",&a[i]);
		for(int b;m--;g=gcd(g,b)) scanf("%d",&b);
		for(int i=1;i<=g;++i) f[i][0]=a[i],f[i][1]=-a[i];
		for(int i=g+1;i<=n;++i)
			f[i][0]=max(f[i-g][0]+a[i],f[i-g][1]-a[i]),f[i][1]=max(f[i-g][1]+a[i],f[i-g][0]-a[i]);
		for(int i=n-g+1;i<=n;++i) z0+=f[i][0],z1+=f[i][1];
	}
	return 0;
}