//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<cstring>
#include<iomanip>
#include<stack>
#include<bitset>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,q,fa[200005],ri[200005],a,b,c;
int Fa(int now)
{
	return fa[now]==now?now:fa[now]=Fa(fa[now]);
}
int Ri(int now)
{
	return ri[now]==now?now:ri[now]=Ri(ri[now]);
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>q;
	for(int i=1;i<=n;++i)
	{
		fa[i]=i;
		ri[i]=i;
	}
	for(int i=1;i<=q;++i)
	{
		cin>>a>>b>>c;
		if(a==1)
		{
			fa[Fa(b)]=Fa(c);
		}
		if(a==2)
		{
			int now=Ri(b);
			while(now<c)
			{
				fa[Fa(now+1)]=Fa(now);
				while(Fa(now)==Fa(now+1))
				{
					ri[Ri(now)]=Ri(now+1);
					now=Ri(now);
				}
			}
		}
		if(a==3)
		{
			cout<<(Fa(b)==Fa(c)?"YES":"NO")<<endl;
		}
	}
	return 0;
}