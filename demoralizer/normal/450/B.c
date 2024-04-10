#include <stdio.h>
int main()
{
	int x,y,n,a;
	scanf("%d %d\n%d",&x,&y,&n);
	n=(n-1)%6;
	switch(n){
		case 0:a=x;break;
		case 1:a=y;break;
		case 2:a=y-x;break;
		case 3:a=-x;break;
		case 4:a=-y;break;
		case 5:a=x-y;break;
	}
	a=a%1000000007;
	printf("%d",a<0?(1000000007+a):a);
}