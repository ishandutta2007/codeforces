#include<cstdio>
char a[300];int n,f[300],k;
int main(){
	scanf("%d%s",&n,a+1);
	for(int i=1;i<=n;i++)a[i]=a[i]=='B'?1:0;
	for(int i=1;i<n;i++)
	  if(a[i])f[i]^=1,a[i]^=1,a[i+1]^=1;
	if(a[n]){
	  if(~n&1)return 0*puts("-1");
	  for(int i=1;i<n;i+=2)f[i]^=1;
	}
	for(int i=1;i<=n;i++)k+=f[i];
	printf("%d\n",k);
	for(int i=1;i<=n;i++)if(f[i])printf("%d ",i);
	return 0;
}