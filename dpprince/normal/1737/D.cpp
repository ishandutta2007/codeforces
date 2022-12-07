// Author: Little09
// Problem: D. Ela and the Wiring Wizard
// Contest: Codeforces - Dytechlab Cup 2022
// URL: https://codeforces.com/contest/1737/problem/D
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(x) memset(x,0,sizeof(x))
#define printYes cout << "Yes" << endl
#define printYES cout << "YES" << endl
#define printNo cout << "No" << endl
#define printNO cout << "NO" << endl
#define endl "\n"
#define lowbit(x) (x&(-x))

const ll inf=1000000000000000000; 
//const ll inf=1000000000;
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=505;
int n,m; 
int a[N][N],b[N][N];


void work()
{
	cin >> n >> m;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			a[i][j]=1e9+5,b[i][j]=1e9+5;
		}
	}
	for (int i=1;i<=n;i++) b[i][i]=0;
	for (int i=1;i<=m;i++) 
	{
		int x,y,z;
		cin >> x >> y >> z;
		a[x][y]=min(a[x][y],z);
		a[y][x]=min(a[y][x],z);
		b[x][y]=1,b[y][x]=1;
	}
	for (int k=1;k<=n;k++)
	{
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++)
			{
				b[i][j]=min(b[i][j],b[i][k]+b[k][j]);
			}
		}
	}
	ll ans=inf;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			if (a[i][j]==1e9+5) continue;
			ans=min(ans,1ll*a[i][j]*(b[i][1]+b[j][n]+1));
			ans=min(ans,1ll*a[i][j]*(b[i][n]+b[j][1]+1));
			for (int k=1;k<=n;k++)
			{
				ans=min(ans,1ll*a[i][j]*(b[i][k]+b[k][n]+b[k][1]+2));
				ans=min(ans,1ll*a[i][j]*(b[j][k]+b[k][n]+b[k][1]+2));
			}
		}
	}
	cout << ans << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while (T--) work();
	return 0;
}