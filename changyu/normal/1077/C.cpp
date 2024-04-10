#include<cstdio>
#include<algorithm>
typedef long long ll;
const int N=2e5+1;
int n;ll a[N],t[N],b,ans[N],k;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i),b+=t[i]=a[i];
	std::sort(t+1,t+1+n);
	for(int i=1;i<=n;i++)
	  if(b-a[i]==2*t[a[i]==t[n]?n-1:n])ans[++k]=i;
	printf("%d\n",k);
	for(;k;)printf("%d ",ans[k--]);
	return 0;
}