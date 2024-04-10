#include<cstdio>
const int N=101;
int n,a[N],s;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	for(int i=2;i<=n;i++)if(a[i]>1&&a[i-1]>1)return 0*puts("Infinite");
	puts("Finite");
	if(a[1]==1)s+=a[2]==2?3:4;
	if(a[n]==1)s+=a[n-1]==2?3:4;
	for(int i=2;i<n;i++)if(a[i]==1){
	  if(a[i-1]==2&&a[i+1]==2)s+=6;
	  if(a[i-1]==2&&a[i+1]==3)s+=7;
	  if(a[i-1]==3&&a[i+1]==2)s+=6;
	  if(a[i-1]==3&&a[i+1]==3)s+=8;
	}printf("%d",s);
	return 0;
}