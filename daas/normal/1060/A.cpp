#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#define ll long long
using namespace std;
inline int read()
{
	char c=getchar();
	int kkk=0;
	while(c<'0' || c>'9')
		c=getchar();
	while(c>='0' && c<='9')
		kkk=(kkk<<3)+(kkk<<1)+(c-'0'),c=getchar();
	return kkk;
}
int n,tot;
int main()
{
	n=read();
	for(register int i=1;i<=n;++i)
		if(getchar()=='8')
			++tot;
	printf("%d\n",min(n/11,tot));
	return 0;
}