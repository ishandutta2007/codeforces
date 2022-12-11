#include<cstdio>
void read(int&x)
{
	x=0;char c;
	do{c=getchar();}while(c<'0'||c>'9');
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
}
#define MAX 100000
int f[MAX+5];
int main()
{
	int n,x,q,i;
	read(n);
	for(i=0;i<n;i++){read(x);f[x]++;}
	for(i=1;i<=MAX;i++)f[i]+=f[i-1];
	read(q);
	while(q--)
	{
		read(x);
		printf("%d\n",x>MAX?n:f[x]);
	}
}