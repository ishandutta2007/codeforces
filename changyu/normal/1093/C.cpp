#include<cstdio>
const int N=2e5+2;
int n;long long a[N],b[N];
int main(){
	scanf("%d",&n);
	for(int i=1;i+i<=n;i++)
	  scanf("%I64d",b+i);
	a[1]=0;a[n]=b[1];
	for(int i=2;i+i<=n;i++)
	  if(b[i]>=b[i-1])
		a[i]=a[i-1]+b[i]-b[i-1],a[n-i+1]=a[n-i+2];
	  else
		a[i]=a[i-1],a[n-i+1]=a[n-i+2]+b[i]-b[i-1];
	for(int i=1;i<=n;i++)printf("%I64d ",a[i]);
	return 0;
}