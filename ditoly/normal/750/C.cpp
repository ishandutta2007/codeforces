#include<cstdio>
inline int read()
{
	int x=0,f=1;char c;
	while((c=getchar())<'0'||c>'9')if(c=='-')f=-1;
	for(;c>='0'&&c<='9';c=getchar())x=x*10+c-'0';
	return x*f;
}
int main()
{
	int n=read(),su=0,bu=0,s,b,f=1900,x,t;
	while(n--)
	{
		x=read();t=read();
		if(t==1)if(!bu||f>b)bu=1,b=f;
		if(t==2)if(!su||f<s)su=1,s=f;
		f-=x;
	}
	if(!su)puts("Infinity");
	else if(!bu||b<s)printf("%d",s-1+1900-f);
	else puts("Impossible");
}