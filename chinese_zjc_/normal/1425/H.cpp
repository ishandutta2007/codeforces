#include<bits/stdc++.h>
using namespace std;

int read()
{
	int s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(int x)
{
	if (x<0)
	{
		putchar('-');
		x=-x;
	}
	if (x<10) putchar(x+'0');
	else
	{
		write(x/10);
		putchar(x%10+'0');
	}
}
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
bool ans[5];

signed main()
{
	int T=read();
	while (T--)
	{
		for (int i=1;i<=4;i++) ans[i]=0;
		int a=read(),b=read(),c=read(),d=read();
		if ((a+b)%2==0)
		{
			ans[3]=b||c;
			ans[4]=a||d;
		}
		else
		{
			ans[1]=a||d;
			ans[2]=b||c;
		}
		for (int i=1;i<=4;i++)
		if (ans[i]) printf("Ya ");
			   else printf("Tidak ");
		putchar('\n');
	}

	return 0;
}