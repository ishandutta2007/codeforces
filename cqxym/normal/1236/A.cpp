#include<stdio.h>
int Min(int &x,int y){
	return x<y?x:y;
}
int main(){
	int t,a,b,c;
	scanf("%d",&t);
	for(register int i=0;i<t;i++){
		scanf("%d%d%d",&a,&b,&c);
		c=Min(b,c>>1);
		a=Min(a,b-c>>1);
		printf("%d\n",(a+c)*3);
	}
	return 0;
}