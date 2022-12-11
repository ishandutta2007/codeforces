#include<cstdio>
char B[1<<6],*S=B,C;int X;
inline read()
{
	while((C=*S++)<'0'||C>'9');
	for(X=C-'0';(C=*S++)>='0'&&C<='9';)X=(X<<3)+(X<<1)+C-'0';
	return X;
}
int main()
{
	fread(B,1,1<<6,stdin);
	int ans=0,f=1,x,i;
	for(;;)
	{
		x=read();ans+=x*f;
		if(C=='+')f=1;
		else if(C=='-')f=-1;
		else break;
	}
	if(x=ans/100)
	{
		ans%=100;
		for(i=1;i<=x+'0';++i)putchar('+');
		puts(".>");
	}
	if(x=ans/10)
	{
		ans%=10;
		for(i=1;i<=x+'0';++i)putchar('+');
		puts(".>");
	}
	for(i=1;i<=ans+'0';++i)putchar('+');puts(".");
}