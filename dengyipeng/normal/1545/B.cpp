#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define ll long long
#define mo 998244353
#define maxn 200005
using namespace std;

int T,n,i,j,k,a[maxn];
ll fct[maxn],invf[maxn];

ll ksm(ll x,ll y){
	ll s=1;
	for(;y;y/=2,x=x*x%mo) if (y&1)
		s=s*x%mo;
	return s;
}
ll C(int n,int m){return fct[n]*invf[m]%mo*invf[n-m]%mo;}

int main(){
	fct[0]=1;for(i=1;i<maxn;i++) fct[i]=fct[i-1]*i%mo;
	invf[maxn-1]=ksm(fct[maxn-1],mo-2);
	for(i=maxn-2;i>=0;i--) invf[i]=invf[i+1]*(i+1)%mo;
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		char ch=getchar();
		while (ch!='0'&&ch!='1') ch=getchar();
		for(i=1;i<=n;i++) a[i]=ch-'0',ch=getchar();
		int x=0,y=0;
		for(i=1;i<=n;i++) if (i<n&&a[i]&&a[i+1]) y++,i++; 
			else x+=(a[i]==0);
		x++;
		printf("%lld\n",C(x+y-1,x-1));
	}
}