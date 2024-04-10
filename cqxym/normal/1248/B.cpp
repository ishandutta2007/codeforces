#include<stdio.h>
#include<algorithm>
#define R register int
int a[100000];
int main(){
	int n,s1=0,s2=0,i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	std::sort(a,a+n);
	for(i=0;i<(n>>1);i++){
		s1+=a[i];
	}
	while(i<n){
		s2+=a[i];
		i++;
	}
	printf("%lld",1ll*s1*s1+1ll*s2*s2);
	return 0;
}