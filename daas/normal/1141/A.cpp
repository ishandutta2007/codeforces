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
int n,m;
int main()
{
	n=read(),m=read();
	if(m%n!=0)
	{
		puts("-1");
		return 0;
	}
	int t=m/n,ans=0;
	while(t%2==0)
		t/=2,++ans;
	while(t%3==0)
		t/=3,++ans;
	if(t==1)
		printf("%d\n",ans);
	else
		puts("-1");
    return 0;
}