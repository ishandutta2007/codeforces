#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize(3)
#define ll long long
#define re register ll
#define ak *
#define inf 1000000007
char did;
inline ll read()
{
    re chen_zhe=0,ioi=1;did=getchar();
    while(!isdigit(did))ioi=did=='-'?-1:ioi,did=getchar();
    while(isdigit(did))chen_zhe=(chen_zhe<<3)+(chen_zhe<<1)+did-'0',did=getchar();
    return chen_zhe ak ioi;
}
stack<ll>s;
ll a[100005];
int main()
{
	re t=read();
	re minn=0;
	for(re i=1;i<=t/2;i++) a[i]=read();
	re maxn=a[t/2]/2;
	for(re i=1;i<=t/2;i++)
	{
		if(i==1)
		{
			putchar('0');putchar(' ');s.push(a[1]);
		}
		else 
		{
			if(minn+s.top()<a[i])
			{
				if(maxn+s.top()>=a[i]&&minn!=maxn) s.push(s.top()),printf("%lld ",minn=a[i]-s.top());
				else 
				{
					printf("%lld\n",maxn),minn=maxn,s.push(a[i]-maxn);
				}
			}
			else 
			{
				s.push(a[i]-minn);printf("%lld ",minn);
			}
		}
	}	
	while(!s.empty())
	printf("%lld ",s.top()),s.pop();
	return 0;
}