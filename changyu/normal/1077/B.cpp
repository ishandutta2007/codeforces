#include<cstdio>
const int N=101;
int n,s,t;bool a[N],f[N];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	for(int i=2;i<n;i++)t+=f[i]=a[i-1]&&a[i+1]&&!a[i];
	for(int j=1;j<=n;j++)
	  for(int i=2;i<n;i++)
		if(f[i-1]&&f[i+1])
		  {f[i-1]=f[i+1]=0,s++;break;} 
	printf("%d",t-s);
	return 0;
}