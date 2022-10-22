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
int n,a[200001],ans;
int main()
{
	n=read();
	int num=0;
	for(register int i=1;i<=n;++i)
	{
		a[i]=read();
		if(a[i]==0)
		{
			ans=max(ans,num);
			num=0;
		}
		else
			++num;
	}
	int ar_ans=0;
	for(register int i=1;i<=n;++i)
		if(a[i]==0)
		{
			ar_ans+=(i-1);
			break;
		}
	for(register int i=n;i>=1;--i)
		if(a[i]==0)
		{
			ar_ans+=(n-i);
			break;
		}
	printf("%d\n",max(ans,ar_ans));
    return 0;
}