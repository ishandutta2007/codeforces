#include<stdio.h>
#include<string.h>
long long ans,n,x,y,num;
char a[300010];
int main()
{
	scanf("%I64d %I64d %I64d ",&n,&x,&y);
	gets(a);
	for(int i=0;i<strlen(a);i++)
		if(a[i]=='0'&&a[i+1]!='0')num++;
	if(num==0)
	{
		printf("0");
		return 0;
	}
	if(y>x)ans=(num-1)*x+y;
	else ans=num*y;
	printf("%I64d",ans);
}