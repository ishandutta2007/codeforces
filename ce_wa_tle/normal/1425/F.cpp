#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;

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
int a[N],s[N];
int get(int l,int r)
{
	printf("? %d %d\n",l,r);
	fflush(stdout);
	return read();
}

signed main()
{
	s[0]=0;
	int n=read();
	int ab=get(1,2),bc=get(2,3),abc=get(1,3);
	a[2]=ab+bc-abc;
	a[1]=ab-a[2];
	a[3]=bc-a[2];
	for (int i=1;i<=3;i++) s[i]=s[i-1]+a[i];
	for (int i=4;i<=n;i++)
	{
		s[i]=get(1,i);
		a[i]=s[i]-s[i-1];
	}
	putchar('!');
	for (int i=1;i<=n;i++) putchar(' '),write(a[i]);
	fflush(stdout);

	return 0;
}