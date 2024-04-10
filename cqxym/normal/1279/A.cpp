#include<stdio.h>
#include<algorithm>
int main(){
	int t,a[3];
	scanf("%d",&t);
	for(register int i=0;i!=t;i++){
		scanf("%d%d%d",a,a+1,a+2);
		std::sort(a,a+3);
		if(a[0]+a[1]+1>=a[2]){
			puts("YES");
		}else{
			puts("NO");
		}
	}
	return 0;
}