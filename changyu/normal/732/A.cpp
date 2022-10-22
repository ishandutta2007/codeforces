#include<cstdio>
int main(){
	int k,r,ans;
	scanf("%d%d",&k,&r);
	for(int i=1;i<=10;i++)
	if(k%10*i%10==r||k*i%10==0){ans=i;break;}
	printf("%d\n",ans);
	return 0;
}