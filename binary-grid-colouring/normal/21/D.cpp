#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int w[34][34];
int d[32768];
int f[32768];
int ans = 0;
int main()
{
	int n,m;
	cin>>n>>m;
	int x,y,z;
	if(m==0)return 0*puts("0");
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
		{
			w[i][j] = (1<<29);
		}
	}
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y>>z;
		d[x]++;
		d[y]++;
		ans+=z;
		if(w[x][y]>z)
		{
			w[x][y] = z;
			w[y][x] = z;
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			if(i!=k)
			{
				for(int j=1;j<=n;j++)
				{
					if(i!=j && j!=k)
					{
						w[i][j] = min(w[i][j],w[i][k]+w[k][j]);
					}
				}
			}
		}
	}
	for(int i=2;i<=n;i++)
	{
		if(d[i] != 0 && w[1][i] == (1<<29))
		{
			return 0*puts("-1");
		}
	}
	int end = 0;
	for(int i=1;i<=n;i++)
	{
		if(d[i]&1)
		{
			end |= (1<<(i-1));
		}
	}
	for(int i=0;i<=end;i++)
	{
		f[i] =  (1<<29);
		f[end] = 0;
	}
	int now = 0;
	for(int i=end;i>=1;--i)
	{
		if(f[i]==(1<<29)) continue;
		for(int j=1;j<=n;j++)
		{
			if(((1<<(j-1)) & i) == 0) continue;
			for(int k=1;k<=n;k++)
			{
				if(((1<<(k-1)) & i ) == 0) continue;
				now = i ^ (1<<(k-1)) ^ (1<<(j-1));
			//	cout<<"now="<<now<<endl;
				f[now] = min(f[now],f[i]+w[j][k]);
			}
		}
	}
	//cout<<f[0]<<endl;
	ans+=f[0];
	cout<<ans<<endl;
	return 0;
}