#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}
int n,m;
int main()
{
	n=read(); m=read();
	if(n>29)
	{
		printf("%d\n",m);
		return 0; //exit 0
	}
	int op=1<<n;
	printf("%d\n",m%op);
}