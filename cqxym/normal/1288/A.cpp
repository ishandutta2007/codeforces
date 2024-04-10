#include<stdio.h>
#include<cmath>
inline int Day(int x,int d){
	return x+(d+x)/(x+1);
}
int main(){
	int t,n,d,x;
	scanf("%d",&t);
	for(register int i=0;i!=t;i++){
		scanf("%d%d",&n,&d);
		x=sqrt(d);
		if(Day(x,d)<=n||Day(x-1,d)<=n){
			puts("YES");
		}else{
			puts("NO");
		}
	}
	return 0;
}