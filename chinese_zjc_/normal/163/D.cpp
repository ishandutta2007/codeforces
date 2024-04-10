//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
#include<map>
#include<queue>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int a,b,c,n,t,v[100],p[100][100],ans,sum,B;
void dfsb(int now,int A,int V)
{
	if((double)V*V>sum/A)
	{
		return;
	}
	if(now>n)
	{
		B=max(B,V);
		return;
	}
	for(int i=v[now];i>=0;--i)
	{
		dfsb(now+1,A,V*p[now][i]);
	}
}
void dfsa(int now,int A)
{
//	cout<<now<<' '<<A<<endl;
	if((double)A*A*A>sum)
	{
		return;
	}
	if(now>n)
	{
		int l=4*A*sqrt(sum/A)+2*sum/A;
		if(l<ans)
		{
			B=0;
			dfsb(1,A,1);
			int C=sum/A/B,S=2*(A*B+A*C+B*C);
			if(S<ans)
			{
				ans=S;
				a=A;
				b=B;
				c=C;
			}
		}
		return;
	}
	for(int i=v[now];i>=0;--i)
	{
		v[now]-=i;
		dfsa(now+1,A*p[now][i]);
		v[now]+=i;
	}
}
signed main()
{
	std::ios::sync_with_stdio(false);
//	freopen("a.in","r",stdin);
//	freopen("b.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		sum=1;
		for(int i=1;i<=n;++i)
		{
			cin>>a>>b;
			v[i]=b;
			p[i][0]=1;
			for(int j=1;j<=b;++j)
			{
				p[i][j]=p[i][j-1]*a;
			}
			sum*=p[i][b];
		}
		ans=INF;
		dfsa(1,1);
		cout<<ans<<' '<<a<<' '<<b<<' '<<c<<endl;
	}
	return 0;
}