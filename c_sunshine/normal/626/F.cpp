#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long LL;
const int M=1000000007;
int n,m;
int a[205];
int f[205][205][1005];

inline void up(int &x,const int y)
{x=(x+y)%M;}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	sort(a+1,a+n+1);
	f[0][0][0]=1;
	int i,j,k,t,w;
	for(i=1;i<=n;i++)
		for(j=0;j<i;j++)
			for(k=0;k<=m;k++)
				if(t=f[i-1][j][k])
				{
					w=k+j*(a[i]-a[i-1]);
					if(w>m)continue;
					//one
					up(f[i][j][w],t);
					//open
					up(f[i][j+1][w],t);
					//push
					up(f[i][j][w],(LL)j*t%M);
					//close
					if(j)up(f[i][j-1][w],(LL)j*t%M);
				}
	int ans=0;
	for(k=0;k<=m;k++)
		up(ans,f[n][0][k]);
	cout<<ans<<endl;
	return 0;
}