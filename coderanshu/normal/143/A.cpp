#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>
using namespace std ;

#define M 1000000007
#define MM 998244353 
#define ll long long 
#define pb push_back
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define memf(a) memset(a,false,sizeof(a))
#define all(v) v.begin(),v.end()
#define F first
#define S second
#define PI 3.1415926536
#define INF 2e18
#define endl "\n"

ll power(ll b,ll e,ll m)
{
	if(e==0) return 1;
	if(e&1) return b*power(b*b%m,(e-1)/2,m)%m;
	return power(b*b%m,e/2,m);
}
ll power( ll b, ll e)
{
	if(e==0) return 1;
	if(e&1) return b*power(b*b,(e-1)/2);
	return power(b*b,e/2);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int r1,r2,c1,c2,d1,d2,i,j,k,z;
	cin>>r1>>r2>>c1>>c2>>d1>>d2;
	for(i=1;i<10;++i)
	{
		for(j=1;j<10;++j)
		{
			if(j==i)continue;
			for(k=1;k<10;k++)
			{
				if(k==i || k==j)continue;
				for(z=1;z<10;z++)
				{
					if(z==i || z==j || z==k)continue;
					if(i+j==r1 && i+z==d1 && k+z==r2 && i+k==c1 && j+k==d2 && j+z==c2)
					{
						cout<<i<<" "<<j<<endl<<k<<" "<<z;return 0;
					}
				}
			}
		}
	}
	cout<<-1;
	return 0;
}