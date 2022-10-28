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
#define sz(a) (ll)a.size()
#define F first
#define S second
#define PI 3.1415926536
#define INF 2e18
#define endl "\n"
#define _time_ 1.0 * clock() / CLOCKS_PER_SEC
ll power(ll b,ll e,ll m)
{
	if(e==0) return 1;
	if(e&1) return b*power(b*b%m,e/2,m)%m;
	return power(b*b%m,e/2,m);
}
ll power( ll b, ll e)
{
	if(e==0) return 1;
	if(e&1) return b*power(b*b,e/2);
	return power(b*b,e/2);
}
int _runtimeTerror_()
{
	ll n,m;
	cin>>n>>m;
	if(n<m)
	{
		cout<<1<<endl;return 0;
	}
	ll a[m][m],i,j,ans[m][m],fuck[m][m];
	for(i=0;i<m;++i)
	{
		for(j=0;j<m;++j)
		{
			fuck[i][j]=0;
			a[i][j]=0;
		}
		if(i>0)
			a[i][i-1]++;
	}
	a[0][0]++;a[0][m-1]++;
	ll pw=n-m+1;
	for(i=0;i<m;++i)
		for(j=0;j<m;++j)
			ans[i][j]=a[i][j];
	for(i=0;i<m;++i)
		fuck[i][i]=1;
	while(pw>1)
	{
		if(pw&1)
			{
			ll b[m][m];
			for(i=0;i<m;++i)
			{
				for(j=0;j<m;++j)
					b[i][j]=a[i][j];
			}
			ll c[m][m],i,j,k;
			for(i=0;i<m;i++)
			{
				for(j=0;j<m;j++)
				{
					c[i][j]=0;
					for(k=0;k<m;k++)
					{
						c[i][j]=(c[i][j]+fuck[i][k]*b[k][j]%M)%M;
					}
				}
			}
			for(i=0;i<m;i++)
			{
				for(j=0;j<m;j++)
					fuck[i][j]=c[i][j];
			}
			}
			ll b[m][m];
			for(i=0;i<m;++i)
			{
				for(j=0;j<m;++j)
					b[i][j]=a[i][j];
			}
			ll c[m][m],i,j,k;
			for(i=0;i<m;i++)
			{
				for(j=0;j<m;j++)
				{
					c[i][j]=0;
					for(k=0;k<m;k++)
					{
						c[i][j]=(c[i][j]+a[i][k]*b[k][j]%M)%M;
					}
				}
			}
			for(i=0;i<m;i++)
			{
				for(j=0;j<m;j++)
					a[i][j]=c[i][j];
			}
			pw>>=1;
	}
	ll b[m][m];
			for(i=0;i<m;++i)
			{
				for(j=0;j<m;++j)
					b[i][j]=fuck[i][j];
			}
			ll c[m][m],k;
			for(i=0;i<m;i++)
			{
				for(j=0;j<m;j++)
				{
					c[i][j]=0;
					for(k=0;k<m;k++)
					{
						c[i][j]=(c[i][j]+a[i][k]*b[k][j]%M)%M;
					}
				}
			}
			for(i=0;i<m;i++)
			{
				for(j=0;j<m;j++)
					a[i][j]=c[i][j];
			}
	ll ff=0;
	for(i=0;i<m;++i)
	{
		ff+=a[0][i];
		ff%=M;
	}
	cout<<ff<<endl;
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifdef runSieve
		sieve();
	#endif
	#ifdef NCR
		initialize();
	#endif
	int TESTS=1;
	//cin>>TESTS;
	while(TESTS--)
		_runtimeTerror_();
	cerr<<_time_;
	return 0;
}