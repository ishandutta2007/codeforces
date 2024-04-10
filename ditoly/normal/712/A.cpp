#include<cstdio>
void read(int&x)
{
	x=0;char c;int f=1;
	do{c=getchar();if(c=='-')f=-f;}while(c<'0'||c>'9');
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	x*=f;
}
int main()
{
	int n,i,x[2];
	read(n);read(x[0]);
	for(i=1;i<n;i++)
	{
		read(x[i&1]);
		printf("%d ",x[i&1]+x[i&1^1]);
	}
	printf("%d",x[i&1^1]);
}