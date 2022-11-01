#include<stdio.h>
int main(){
	int q,a,b,c,i,d,e,f;
	scanf("%d",&q);
	for(i=0;i<q;i++){
		scanf("%d%d%d",&a,&b,&c);
		d=a;
		if(b<d){
			d=b;
		}
		e=d;
		if(c<d){
			d=c;
		}
		if(d==c){
			f=(a+b+c)/3;
			if(e<f){
				printf("%d\n",e);
			}else{
				printf("%d\n",f);
			}
		}else{
			printf("%d\n",d);
		}
	}
	return 0;
}