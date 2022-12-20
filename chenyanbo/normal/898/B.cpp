#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}


long long h,x,y,a,b,c,o;

int gcd(int a, int b)
{
	if(!b)return a;
	return gcd(b,a%b);
}

long long exGcd(long long a, long long b, long long &x, long long &y) {
if (b == 0) return x = 1, y = 0, a;
long long r = exGcd(b, a % b, y, x);
y -= (a / b) * x;
return r;
}

int main()
{
	c=read();
	a=read();
	b=read();
	o=gcd(a,b);
	if(c%o)
	{
		puts("NO");
		return 0; 
	}
	a/=o;
	b/=o;  
	c/=o;
	exGcd(a,b,x,y);
	x=x*c; y=y*c;
	if(x<0)
	{
		h=y/a;
		x=x+h*b;
		y=y%a;
		if(x<0)
	{
		puts("NO");
		exit(0);
	} 
	}
	if(y<0)
	{
		h=x/b;
		y=y+h*a;
		x=x%b;
		if(y<0)
	{
		puts("NO");
		exit(0);
	}
	}

	puts("YES");   
printf("%I64d %I64d\n",x,y);
}