#include<bits/stdc++.h>
using namespace std ;

#define M 1000000007
#define MM 998244353 
#define ll long long 
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define memf(a) memset(a,false,sizeof(a))
#define all(v) v.begin(),v.end()
#define rep(i,a,b) for(i=a;i<b;i++)
#define F first
#define S second
#define PI 3.1415926536
#define INF 

ll power(ll b,ll e,ll m)
{
	if(e==0)
		return 1;
	if(e%2)
		return b*power(b*b%m,(e-1)/2,m)%m;
	else
		return power(b*b%m,e/2,m);
}
ll power( ll b, ll e)
{
	if(e==0)
		return 1;
	if(e%2)
		return b*power(b*b,(e-1)/2);
	else
		return power(b*b,e/2);
}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll na,ma,nb,mb,i,j,x,y,ansx=0,ansy=0,prod,check=0;
	cin>>na>>ma;
	ll m1[na][ma];
	char c;
	for(i=0;i<na;i++)
	{
		for(j=0;j<ma;j++){cin>>c;m1[i][j]=c-48;}
	}
	cin>>nb>>mb;
	ll m2[nb][mb];
	for(i=0;i<nb;i++)
	{
		for(j=0;j<mb;j++){cin>>c;m2[i][j]=c-48;}
	}
	for(x=1-na;x<=nb-1;x++)
	{
		for(y=1-ma;y<=mb-1;y++)
		{
			prod=0;
			for(i=max(0LL,-x);i<=min(na-1,nb-x-1);i++)
			{
				for(j=max(0LL,-y);j<=min(ma-1,mb-y-1);j++)
					prod+=m1[i][j]*m2[i+x][j+y];
			}
			if(prod>check)
			{
				check=prod;
				ansx=x;ansy=y;
			}
		}
	}
	cout<<ansx<<" "<<ansy;
	return 0;
}