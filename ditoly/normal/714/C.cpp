#include<cstdio>
#define ll long long
void read(ll&x)
{
	x=0;char c;
	do c=getchar();while(c<'0'||c>'9');
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
}
#define MAX 262144
int f[MAX+5];
int main()
{
	ll n,x,k,i;char t;
	read(n);
	while(n--)
	{
		do t=getchar();while(t!='+'&&t!='-'&&t!='?');
		read(x);
		for(i=0,k=0;i<18;i++,x/=10)k=(k<<1)+(x&1);
		if(t=='+')f[k]++;
		if(t=='-')f[k]--;
		if(t=='?')printf("%d\n",f[k]);
	}
}