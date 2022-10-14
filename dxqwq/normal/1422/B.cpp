#include<bits/stdc++.h>
#define ll long long
using namespace std;
int T,n,m;
int a[105][105];
ll b[10];
ll calc(ll x,ll y,ll z,ll t,ll ave)
{
	return abs(x-ave)+abs(y-ave)+abs(z-ave)+abs(t-ave);
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		ll ans=0;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)scanf("%d",&a[i][j]);
		for(int i=1;i<=(n+1)/2;++i)
			for(int j=1;j<=(m+1)/2;++j)
			{
				ll x=a[i][j],y=a[n-i+1][j],z=a[i][m-j+1],t=a[n-i+1][m-j+1];
				b[1]=x;b[2]=y;b[3]=z;b[4]=t;
				sort(b+1,b+4+1);
				ll d=calc(x,y,z,t,b[2]);
				if(i==n-i+1&&j==m-j+1)ans+=0;
				else if(i==n-i+1||j==m-j+1)ans+=d/2;
				else ans+=d;
			}
		cout<<ans<<endl;
	}
}