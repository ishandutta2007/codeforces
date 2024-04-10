#include<cstdio>
int n,m,a[100],s,f=1;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)scanf("%d",a+i);
	for(int i=0;i<n;i++)if(a[i]>m){s+=i;break;}
	for(int i=n-1;~i;i--)if(a[i]>m){s+=n-i-1;f=0;break;}
	printf("%d",f?n:s);
	return 0;
}