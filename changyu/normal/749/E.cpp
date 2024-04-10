#include<cstdio>
#define int long long
const int N=2e5+3;
int a[N],n,bt0[N],bt1[N],s0,s1;double ans;
inline void Add(int k,int a,int*bt){for(;k&&k<=n;k+=k&-k)bt[k]=bt[k]+a;}
inline int Sum(int k,int*bt){int s=0;for(;k;k-=k&-k)s=s+bt[k];return s;}
signed main(){
	scanf("%I64d",&n);
	for(int i=1;i<=n;i++)scanf("%I64d",a+i);
	for(int i=n;i;i--){
	  ans=ans+Sum(a[i],bt0)*(1-i*2.0/n)+Sum(a[i],bt1)*2.0/n*i/(n+1)+1.0*i/n*s0-1.0*s1/n*i/(n+1);
	  Add(a[i],1,bt0),Add(a[i],i,bt1),s0++,s1=s1+i;
	}printf("%.10lf",ans);
	return 0;
}