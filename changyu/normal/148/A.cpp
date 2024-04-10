#include<cstdio>
int a[4],n,k;
int main(){
	scanf("%d%d%d%d%d",a,a+1,a+2,a+3,&n);
	for(int i=1;i<=n;i++)
	for(int j=0;j<4;j++)
	  if(i%a[j]==0){k++;break;}
	printf("%d",k);
	return 0;
}