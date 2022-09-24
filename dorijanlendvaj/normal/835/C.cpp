#include <bits/stdc++.h>

using namespace std;

vector<int> zvj[110][110];
int pref[110][110][11];
int n,q,c;
int x,y,s,x2,y2,t;

int main()
{
	cin>>n>>q>>c;
	for (int i=1;i<=100;++i) for (int j=1;j<=100;++j)
	{
		zvj[i][j].resize(11);
	}
	for (int i=0;i<n;++i)
	{
		cin>>x>>y>>s;
		++zvj[x][y][s];
	}
	for (int k=0;k<=c;++k)
	{
		pref[1][1][k]=zvj[1][1][k];
		for (int i=2;i<=100;++i) pref[i][1][k]=zvj[i][1][k]+pref[i-1][1][k];
		for (int i=2;i<=100;++i) pref[1][i][k]=zvj[1][i][k]+pref[1][i-1][k];
		for (int i=2;i<=100;++i)
		{
			for (int j=2;j<=100;++j)
			{
				pref[i][j][k]=pref[i-1][j][k]+pref[i][j-1][k]-pref[i-1][j-1][k]+zvj[i][j][k];
			}
		}
	}
	while (q--)
	{
		cin>>t>>x>>y>>x2>>y2;
		int zb=0;
		for (int k=0;k<=c;++k)
		{
			if (k || t) zb+=(pref[x2][y2][k]-pref[x-1][y2][k]-pref[x2][y-1][k]+pref[x-1][y-1][k])*((k+t)%(c+1));
		}
		cout<<zb<<endl;
	}
}