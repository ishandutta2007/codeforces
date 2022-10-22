#include <bits/stdc++.h>
using namespace std;
#if !defined(ONLINE_JUDGE)&&defined(LOCAL)
#include "my_header\debug.h"
#else
#define dbg(...); 1;
#endif
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int N=1e3+2;
int dis[N],b[N],c[N],f[N*12];
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	{
		queue<int> q;
		int n=1e3,i;
		q.push(1);dis[1]=1;
		while (!q.empty())
		{
			int u=q.front(),v;q.pop();
			for (i=1;i<=u;i++)
			{
				v=u+u/i;
				if (v<=n&&!dis[v]) dis[v]=dis[u]+1,q.push(v);
			}
		}
		for (i=1;i<=n;i++) assert(dis[i]--);
	}
	int T;cin>>T;
	while (T--)
	{
		int n,m,i,j;
		cin>>n>>m;
		for (i=1;i<=n;i++) cin>>b[i],b[i]=dis[b[i]];
		for (i=1;i<=n;i++) cin>>c[i];
		m=min(m,accumulate(b+1,b+n+1,0));
		fill_n(f,m+1,0);
		for (i=1;i<=n;i++) for (j=m;j>=b[i];j--) f[j]=max(f[j],f[j-b[i]]+c[i]);
		cout<<f[m]<<'\n';
	}
}