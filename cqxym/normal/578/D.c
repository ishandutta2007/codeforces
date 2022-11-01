#include<stdio.h>
char a[100002];
int main() {
	int n,m,i,c=0;
	long long ans=0;
	scanf("%d%d", &n,&m);
	scanf("%s",a+1);
	a[0]=a[1];
	a[n+1]=a[n];
	for(i=1;i<=n;i++){
		if(a[i]!=a[i-1]){
			c++;
		}
		ans+=c;
	}
	c=0;
	for(i=n;i!=0;i--){
		if(a[i]!=a[i+1]){
			c++;
		}
		ans+=c;
	}
	ans=(ans+n)*(m-1);
	c=1;
	for(i=2;i<=n;i++){
		if(a[i]==a[i-1]){
			c=1;
		}else if(a[i]!=a[i-2]){
			c=2;
		}else{
			c++;
		}
		ans-=c-1;
	}
	printf("%lld",ans);
	return 0;
}