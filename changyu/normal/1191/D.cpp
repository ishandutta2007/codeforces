#include<cstdio>
#include<algorithm>
#define int long long
const int N=1e5+2;
int n,a[N],f,s;
signed main(){
	scanf("%I64d",&n);
	for(int i=1;i<=n;i++)scanf("%I64d",a+i),s+=a[i];
	if(n==1)return 0*puts(a[1]&1?"sjfnb":"cslnb");
	if(!s)return 0*puts("cslnb");
	std::sort(a+1,a+1+n);
	for(int i=2;i<=n;i++)
	  if(a[i]==a[i-1]){
		if(a[i]==0||i-2>0&&a[i]-1==a[i-2])return 0*puts("cslnb");
		f++;
	  }
	if(f>1)return 0*puts("cslnb");
	s-=n*(n-1)/2+f;
	return 0*puts((s&1)^f?"sjfnb":"cslnb");
}