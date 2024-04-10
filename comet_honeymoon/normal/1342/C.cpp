#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define int long long
#define N 100010
using namespace std;
inline int read()
{
	int neg=1,num=0;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')neg=-1;
	for(;isdigit(c);c=getchar())num=(num<<1)+(num<<3)+c-'0';
	return neg*num;
}
int T,n,q,a,b;
inline int gcd(int x,int y)
{
	return x%y==0?y:gcd(y,x%y);
}
inline int Calc(int x)
{
	int t=x/b*b-1,g=a*b/gcd(a,b),sum=0;
	if(t>=0)sum+=(t/g+1)*b;
	if(x/b*b%a==0)sum+=x-x/b*b+1;
	return sum;
}
signed main()
{
	T=read();
	while(T--)
	{
		a=read();b=read();q=read();
		if(a>b)swap(a,b);
		while(q--)
		{
			int l=read(),r=read();
			printf("%lld ",r-l+1-(Calc(r)-Calc(l-1)));
		}
		printf("\n");
	}
	return 0;
}