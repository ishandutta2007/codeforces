//written by a fan of emptyhope
#include<bits/stdc++.h>
//#define int long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define WT int TT=read();while(TT--) 
#define NO puts("NO");
#define YES puts("YES");
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int M=2e5+10;
int n,m,c[M],a[15][M];
map<vector<int>,int>t,vis;
set<pair<int,vector<int> > >q;

signed main()
{
	n=read();
	for (int i=1;i<=n;i++)
	{
		c[i]=read();
		for (int j=1;j<=c[i];j++)
			a[i][j]=read();
	}
	m=read();
	for (int i=1;i<=m;i++)
	{
		vector<int>v;
		for (int j=1;j<=n;j++)
			v.pb(read());
		t[v]=1;
	}vector<int>qwq;int res=0;
	for (int i=1;i<=n;i++)qwq.pb(c[i]),res+=a[i][c[i]];
	q.insert(mp(-res,qwq));
	while(!q.empty())
	{
		vector<int>v=(*q.begin()).y;
		int res=-(*q.begin()).x;
		q.erase(*q.begin());
		if (!t.count(v))
		{
			for (int i=0;i<n;i++)
				cout<<v[i]<<' ';
			return 0;
		}
		for (int i=1;i<=n;i++)
			if (v[i-1]!=1)
			{
				int pp=res-a[i][v[i-1]]+a[i][v[i-1]-1];
				v[i-1]--;
				q.insert(mp(-pp,v));
				v[i-1]++;
			}
	}
	return 0;
}