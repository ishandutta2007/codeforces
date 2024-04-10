#include<cstdio>
#include<algorithm>
int n,m,t;long long a[200001],ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%I64d",a+i),a[i]+=a[i-1];
	for(int i=1;i<=n;i++){
	  t=std::lower_bound(a+1,a+1+n,a[n]-a[i])-a;
	  if(a[t]==a[n]-a[i]&&i<=t)ans=a[i];
	}printf("%lld",ans);
	return 0;
}