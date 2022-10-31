#include<stdio.h>
#define R register int
int main(){
	int t,a,b,c,x;
	bool f;
	scanf("%d",&t);
	for(R i=0;i!=t;i++){
		scanf("%d%d%d",&c,&a,&b);
		f=false;
		for(R j=0;j!=a;j++){
			scanf("%d",&x);
			if(x==c){
				f=true;
			}
		}
		for(R j=0;j!=b;j++){
			scanf("%d",&x);
		}
		if(f==true){
			puts("YES");
		}else{
			puts("NO");
		}
	}
	return 0;
}