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
	 
	int a[5][5];
	mem0(a);
	int m,i,j,k,count;
	cin>>m;
	a[0][0]=a[1][1]=a[2][2]=a[3][3]=a[4][4]=1;
	while(m--)
	{
		ll x,y;
		cin>>x>>y;
		a[x-1][y-1]=1;
		a[y-1][x-1]=1;
	}
	for(i=0;i<5;i++)
	{
		for(j=i+1;j<5;j++)
		{
			for(k=j+1;k<5;k++)
			{
				count=(a[i][j]==1)+(a[i][k]==1)+(a[j][k]==1);
				if(count==0 || count==3)
				{
					cout<<"WIN";return 0;
				}
			}
		}
	}
	cout<<"FAIL";
	return 0;
}