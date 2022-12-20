#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}

int n;

int main()
{
	n=read();
	if(n%10>5)n+=10;
	n=n/10*10;
	printf("%d\n",n); 
}