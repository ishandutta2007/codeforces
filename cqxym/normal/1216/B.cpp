#include<stdio.h>
#include<algorithm>
#define R register int
struct Can{
	int a,id;
}p[1001];
bool Com(Can x,Can y){
	return x.a>y.a;
}
int main(){
	int n,x=0;
	long long ans=0;
	scanf("%d",&n);
	for(R i=0;i<n;i++){
		scanf("%d",&p[i].a);
		p[i].id=i+1;
	}
	std::sort(p,p+n,Com);
	for(R i=0;i<n;i++){
		ans+=p[i].a*x+1;
		x++;
	}
	printf("%lld\n",ans);
	for(R i=0;i<n;i++){
		printf("%d ",p[i].id);
	}
	return 0;
}