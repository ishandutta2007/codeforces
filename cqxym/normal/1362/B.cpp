#include<stdio.h>
#include<algorithm>
#define R register int
int a[1024],b[1024];
inline void Solve(){
	int n;
	scanf("%d",&n);
	for(R i=0;i!=n;i++){
		scanf("%d",a+i);
	}
	std::sort(a,a+n);
	for(R i=1;i!=1024;i++){
		for(R j=0;j!=n;j++){
			b[j]=a[j]^i;
		}
		std::sort(b,b+n);
		bool tag=false;
		for(R j=0;j!=n;j++){
			if(b[j]!=a[j]){
				tag=true;
				break;
			}
		}
		if(tag==false){
			printf("%d\n",i);
			return;
		}
	}
	puts("-1");
}
int main(){
	int t;
	scanf("%d",&t);
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}