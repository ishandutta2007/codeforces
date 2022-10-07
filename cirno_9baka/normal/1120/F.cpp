#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int t[N],n,a,b,nex,i;
long long ans,s;
char c[N];
int main()
{
	scanf("%d %d %d",&n,&a,&b);
	for(i=1;i<=n;++i)
		scanf("%d %c\n",&t[i],&c[i]);
	s=ans=1ll*n*b;
	scanf("%d",&nex);
	for(i=n;i>=1;--i)
	{
		if(c[i]==c[i-1])
		{
			if(b>1ll*(nex-t[i])*a)
			{
				s-=b;
				s+=1ll*(nex-t[i])*a;
			}
		}
		else
		{
			s-=b;
			s+=1ll*(nex-t[i])*a;
			nex=t[i];
		}
		ans=min(ans,s);
	}
	cout<<ans;
}