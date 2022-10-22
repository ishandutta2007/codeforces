#include<cstdio>
#include<algorithm>
const int N=1e5+1;
int a[N],b[N],n;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	for(int i=1;i<=n;i++)scanf("%d",b+i);
	for(int i=n;i;i--)a[i]-=a[i-1],b[i]-=b[i-1];
	std::sort(a+2,a+1+n);std::sort(b+2,b+1+n);
	for(int i=1;i<=n;i++)if(a[i]!=b[i])return 0*puts("No");
	return 0*puts("Yes");
}