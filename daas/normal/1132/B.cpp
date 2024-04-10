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
    int kkk=0,x=1;
    char c=getchar();
    while((c<'0' || c>'9') && c!='-')
        c=getchar();
    if(c=='-')
        c=getchar(),x=-1;
    while(c>='0' && c<='9')
        kkk=(kkk<<3)+(kkk<<1)+(c-'0'),c=getchar();
    return kkk*x;
}
int n,m,a[300001];
ll all;
int main()
{
	n=read();
	for(register int i=1;i<=n;++i)
		a[i]=read(),all+=a[i];
	sort(a+1,a+n+1);
	m=read();
	for(register int i=1;i<=m;++i)
	{
		int k=read();
		printf("%I64d\n",all-a[n-k+1]);
	}
    return 0;
}