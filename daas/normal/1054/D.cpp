#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<map>
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
map<int,ll> Q;
int n,K,change,pre;
ll ans;
int main()
{
	n=read(),K=read();
	change=(1<<K)-1;
	Q[0]=1;
	for(register int i=1;i<=n;++i)
	{
		int a=read()^pre;
		//cout<<pre<<endl;
		int b=a^change;
		int na=Q[a],nb=Q[b];
		if(nb>na)
		{
			pre=a;
			ans+=(Q[pre]++);
		}
		else
		{
			pre=b;
			ans+=(Q[pre]++);
		}
	}
	printf("%lld\n",1ll*n*(n+1)/2-ans);
	return 0;
}