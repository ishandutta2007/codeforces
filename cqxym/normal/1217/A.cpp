#include<stdio.h>
#define R register int
int main(){
	int i,a,b,c,t;
	scanf("%d",&t);
	for(i=0;i<t;i++){
		scanf("%d%d%d",&a,&b,&c);
		if(a<=b){
			c-=b-a+1;
			if(c<0){
				printf("0\n");
			}else{
				printf("%d\n",c/2+1);
			}
		}else{
			if(a-b>c){
				printf("%d\n",c+1);
				continue;
			}
			if((a+b)%2==1&&c%2==1){
				printf("%d\n",(c+1)/2+(a-b)/2);
			}else{
				printf("%d\n",(c+1)/2+(a-b+1)/2);
			}
		}
	}
	return 0;
}