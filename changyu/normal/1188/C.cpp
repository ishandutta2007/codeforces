#include<cstdio>
#include<algorithm>
const int N=1003,A=1e5+3,M=998244353;
int n,m,x,f[A],s[A],a[N],ans;
inline int Mod(int a){return a<M?a:a-M;}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",a+i),x=std::max(x,a[i]);
	std::sort(a+1,a+1+n);
	for(int k=x/(m-1);k;k--){
	  for(int j=0;j<=n;j++)f[j]=1;
	  for(int i=1;i<=m;i++){
		for(int j=n,l=n;~j;j--){
		  for(;l&&a[j]-a[l]<k;l--);
		  f[j]=j?f[l]:0;
		}
		for(int j=1;j<=n;j++)
		  f[j]=Mod(f[j]+f[j-1]);
	  }
	  s[k]=f[n];
	  ans=(ans+(long long)k*(s[k]-s[k+1]+M))%M;
	}printf("%d\n",ans);
	return 0;
}