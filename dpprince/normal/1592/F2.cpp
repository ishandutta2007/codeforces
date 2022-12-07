// By: Little09
// Problem: F1. Alice and Recoloring 1
// Contest: Codeforces - Codeforces Round #746 (Div. 2)
// URL: https://codeforces.ml/contest/1592/problem/F1
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(x) memset(x,0,sizeof(x))
#define printYes puts("Yes")
#define printYES puts("YES")
#define printNo puts("No")
#define printNO puts("NO")

const ll INF=1000000000000000000; 
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=1110;
int n,m; 
int a[N][N],sum[N][N],c[N][N];
ll s,T,cnt=1;
const int M=100020;
ll nxt[M],h[N],t[M],cur[N];
ll w[M];
ll deth[N];
queue <ll> q;
void add(ll x,ll y,ll z)
{
    t[++cnt]=y;
    nxt[cnt]=h[x];
    w[cnt]=z;
    h[x]=cnt;
}
ll bfs()
{
    memset(deth,0,sizeof(deth));
    while (!q.empty()) q.pop();
    deth[s]=1;
    q.push(s);
    cur[s]=h[s];
    while (!q.empty())
    {
        ll u=q.front();
        q.pop();
        for (ll i=h[u];i!=-1;i=nxt[i])
        {
            if (w[i]>0&&deth[t[i]]==0)
            {
                deth[t[i]]=deth[u]+1;
                cur[t[i]]=h[t[i]];
                q.push(t[i]);
            }
        }
    }
    if (deth[T]!=0) return 1;
	return 0;
}
ll dfs(ll u,ll dist)
{
    if (u==T) return dist;
    for (ll i=cur[u];i!=-1;i=nxt[i])
    {
    	cur[u]=i;
        if ((deth[t[i]]==deth[u]+1)&&(w[i]!=0))
        {
            ll di=dfs(t[i],min(dist,w[i])); 
            if (di>0) 
            {
                w[i]-=di;
                w[i^1]+=di;
                return di;
            }
        }
    }
    deth[u]=0; 
    return 0;
}
ll dinic()
{
    ll ans=0;
    while (bfs())
    {
    	while (ll res=dfs(s,INF)) ans+=res;
    }
    return ans;
}

inline int read()
{
    int F=1,ANS=0;
	char C=getchar();
    while (C<'0'||C>'9')
	{
		if (C=='-') F=-1;
		C=getchar();
	}
    while (C>='0'&&C<='9')
	{
		ANS=ANS*10+C-'0';
		C=getchar();
	}
    return F*ANS;
}
inline char readchar()
{
	char C=getchar();
    while (C<33||C>126) C=getchar();
    return C;
}

int main()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			char x=readchar();
			if (x=='W') a[i][j]=0;
			else a[i][j]=1;
		}
	}
	for (int i=n;i>=1;i--)
	{
		for (int j=m;j>=1;j--)
		{
			int s=(sum[i+1][j+1]^sum[i][j+1]^sum[i+1][j]);
			sum[i][j]=a[i][j];
			c[i][j]=(s^a[i][j]);
		}
	}
	int ans=0;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			ans+=c[i][j];
		}
	}
	if (1)
	{
		s=n+m+1,T=n+m+2;
		memset(h,-1,sizeof(h));
		for (int i=1;i<n;i++) add(s,i,1),add(i,s,0);
		for (int i=1;i<m;i++) add(i+n,T,1),add(T,i+n,0);
		for (int i=1;i<n;i++)
		{
			for (int j=1;j<m;j++)
			{
				if (c[i][j]==1&&c[i][m]==1&&c[n][j]==1)
				{
					add(i,n+j,1),add(n+j,i,0);
				}
			}
		}
		int p=dinic();
		ans-=p;
		if (p%2==1) 
		{
			if (c[n][m]==0) ans++;
			else ans--;
		}
		printf("%d\n",ans);
	}
	return 0;
}