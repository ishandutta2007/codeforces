#include<cstdio>
void read(int&x)
{
	x=0;char c;
	do c=getchar();while(c<'0'||c>'9');
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
}
int main()
{
	int n,c,a,b,i,ans=1;
	read(n);read(c);read(a);
	for(i=1;i<n;i++)
	{
		read(b);
		if(b-a<=c)ans++;
		else ans=1;
		a=b;
	}
	printf("%d",ans);
}