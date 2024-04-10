#include<cstdio>
#define min(a,b)a<b?a:b
int n,k,ans,key[]={0,5,15,30,50,75,105,140,180,225};
int main(){
	scanf("%d%d",&n,&k);
	for(int i=0;i<10;i++)if(key[i]+k<=240)ans=i;
	printf("%d",min(n,ans));
	return 0;
}