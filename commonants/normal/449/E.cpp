#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>

using namespace std;

typedef long long ll;

const ll md=1000000007LL,MX=1001000LL,MXN=1000000LL;
ll p[MX],pc,m[MX],r[MX],f[MX],fn[MX],g[3][MX];
void ini()
{
	m[1]=r[1]=f[1]=1;
	for(ll i=2;i<=MXN;i++)
	{
		if(!m[i])
		{
			p[++pc]=i;m[i]=i;r[i]=1;f[i]=2*i-1;
		}
		int k;
		for(ll j=1;j<=pc&&p[j]<=m[i]&&(k=i*p[j])<=MXN;j++)
		{
			if(p[j]==m[i])
			{
				m[k]=m[i];r[k]=r[i];
			}else
			{
				m[k]=p[j];r[k]=i;
			}
			if(r[k]>1)f[k]=(f[r[k]]*f[k/r[k]])%md;
			else f[k]=(m[k]*f[k/m[k]]+i*(m[k]-1))%md;
		}
	}
	fn[1]=1;
	for(ll i=2;i<=10;i++)fn[i]=((md-md/i)*fn[md%i])%md;
	for(ll i=1;i<=MXN;i++)g[0][i]=((f[i]*2+2*fn[3]*((i*i*i)%md)-2*i*i+fn[3]*i)%md+md)%md;
	for(ll i=1;i<=MXN;i++)g[1][i]=(g[0][i]*i)%md;
	for(ll i=1;i<=MXN;i++)g[2][i]=(g[1][i]*i)%md;
	for(int i=0;i<3;i++)
	for(ll j=1;j<=MXN;j++)g[i][j]+=g[i][j-1];
	for(int i=0;i<3;i++)
	for(ll j=1;j<=MXN;j++)g[i][j]%=md;
}
int main()
{
	//freopen("tst.in","r",stdin);
	//freopen("tst.out","w",stdout);
	ios::sync_with_stdio(false);
	ini();
	ll t;cin>>t;
	for(ll i=1;i<=t;i++)
	{
		ll n,m;cin>>n>>m;
		ll mn=min(m,n);
		cout<<((((n+1)*(m+1))%md*g[0][mn]-(n+m+2)*g[1][mn]+g[2][mn])%md+md)%md<<endl;
	}
	return 0;
}