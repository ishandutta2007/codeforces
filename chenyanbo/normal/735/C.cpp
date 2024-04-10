#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
inline long long read()
{
	long long ret=0; char c=getchar();
	while (c>57 || c<48)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}
long long n,a,b; int c;
int main()
{
	n=read();
    a=1; b=2;
    while(n>=a)
    {
        long long t=b;
	    a+=b;
	    b=a;
	    a=t;
	    ++c;
    }
    printf("%d\n",c-1); 
}