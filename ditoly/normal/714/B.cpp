#include<cstdio>
void read(int&x)
{
	x=0;char c;
	do c=getchar();while(c<'0'||c>'9');
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
}
int main()
{
	int n,i,t,a=-1,b=-1,c=-1,x;
	read(n);
	while(n--)
	{
		read(x);
		if(x!=a&&x!=b&&x!=c)
		{
			if(a<0)a=x;
			else if(b<0)b=x;
			else if(c<0)c=x;
			else{puts("NO");return 0;}
			if(a<b){x=a;a=b;b=x;}
			if(a<c){x=a;a=c;c=x;}
			if(b<c){x=b;b=c;c=x;}
		}
	}
	puts(c<0||a-b==b-c?"YES":"NO");
}