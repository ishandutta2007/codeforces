#include<stdio.h>
int Min(int a,int b){
	return a<b?a:b;
}
int main(){
	int t,a,b,c,r,x;
	scanf("%d",&t);
	for(register int i=0;i!=t;i++){
		scanf("%d%d%d%d",&a,&b,&c,&r);
		if(a>b){
			x=b;
			b=a;
			a=x;
		}
		if(c<=a){
			if(c+r>b){
				x=b-a;
			}else if(c+r<a){
				x=0;
			}else{
				x=c+r-a;
			}
		}else if(c>=b){
			if(c-r<a){
				x=b-a;
			}else if(c-r>b){
				x=0;
			}else{
				x=b-c+r;
			}
		}else{
			x=Min(r,c-a)+Min(r,b-c);
		}
		printf("%d\n",b-a-x);
	}
	return 0;
}