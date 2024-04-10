#include <stdio.h>
int main(){
	int r1,r2,c1,c2,d1,d2,a,b,c,d,k;
	scanf("%d %d\n%d %d\n%d %d",&r1,&r2,&c1,&c2,&d1,&d2);
	for(int i=1;i<10;i++){
		a=i;b=r1-a;c=c1-a;d=d1-a;
		k=(a!=b)+(b!=c)+(c!=d)+(d!=a);
		k=k+(a!=c)+(b!=d)+(b>0&&b<10);
		k=k+(c>0&&c<10)+(d>0&&d<10);
		k=k+(c+d==r2)+(b+d==c2)+(b+c==d2);
		if(k==12){
			printf("%d %d\n%d %d",a,b,c,d);
			return 0;
		}
	}
	printf("-1");
}