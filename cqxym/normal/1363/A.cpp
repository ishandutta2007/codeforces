#include<stdio.h>
#include<algorithm>
#define R register int
int a[1000];
inline void Solve(){
	int n,x;
	scanf("%d%d",&n,&x);
	for(R i=0;i!=n;i++){
		scanf("%d",a+i);
		a[i]&=1;
	}
	std::sort(a,a+n);
	int sum=0;
	for(R i=0;i!=x;i++){
		sum+=a[i];
	}
	if(sum%2==1){
		puts("YES");
		return;
	}
	for(R i=x;i!=n;i++){
		sum+=a[i]-a[i-x];
		if((sum&1)==1){
			puts("YES");
			return;
		}
	}
	puts("NO");
}
int main(){
	int t;
	scanf("%d",&t);
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}