#include<cstdio>
int n,a[101],la=-1;long long ans=0;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
	  scanf("%d",a+i);
	  if(a[i])ans=~la?ans*(i-la):1,la=i;
	}
	printf("%I64d",ans);
	return 0;
}