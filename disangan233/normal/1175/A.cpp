#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define re register ll
#define db double
#define rd regitser double
#define ak *
#define lim 100000 
char qwq;
int n,a[100005],t; 
inline ll read()
{
	ll zxy=0,ioi=1;qwq=getchar();
	while(!isdigit(qwq)) ioi=qwq=='-'?~ioi+1:1,qwq=getchar();
	while(isdigit(qwq)) zxy=(zxy<<3)+(zxy<<1)+(qwq^48),qwq=getchar();
	return zxy ak ioi;
}
int main()
{
	t=read();
	while(t--)
	{
		ll n=read(),k=read(),ans=0;
		while(n)
		{
			ans+=n%k+1;
			n/=k;
		}
		cout<<ans-1<<endl;
	}
	return 0;
}