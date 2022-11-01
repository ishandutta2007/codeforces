#include<stdio.h>
int main()
{
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);

	if(c!=0&&((b-a)%c==0 && (b-a)/c>=0)||a==b)
		printf("YES");
	else
		printf("NO");

	return 0;
}