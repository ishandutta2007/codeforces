#include<cstdio>
void read(int&x)
{
	x=0;char c;
	do{c=getchar();}while(c<'0'||c>'9');
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
}
int main()
{
	int n,i,x,ans=0;
	read(n);
	for(i=0;i<n;i++)
	{
		read(x);ans^=!(x&1);
		printf("%d\n",2-ans);
	}
}