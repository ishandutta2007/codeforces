#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);i++)
#define per(i,n) for(int i=(n)-1;i>=0;i--)
#define prt(n) cout<<(n)<<endl
#define elif else if
#define str string
#define pb push_back
#define mp make_pair
typedef long long ll;
using namespace std;
const ll mod1=998244353;
const ll mod2=1000000007;
//ios_base::sync_with_stdio(false);cin
int n,a[200005],c[200005],cnt;
vector <int> g[200005];
vector <int> fc[200005];
vector <int> v;
void dfs(int i)
{
	if(c[i]!=0) return ;
	c[i]=cnt;
	fc[cnt].pb(i);
	rep(j,g[i].size()) dfs(g[i][j]);
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		g[i].pb(a[i]);
		g[a[i]].pb(i);
	}
	for(int i=1;i<=n;i++)
	{
		if(c[i]!=0) continue;
		cnt++;
		dfs(i);
		int p=fc[cnt][0];
		rep(j,fc[cnt].size()) p=a[p];
		v.pb(p);
	}
	int s=-1;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==i)
		{
			cnt--;
			s=i;
			break;
		}
	}
	if(s==-1)
	{
		s=v[0];
		a[s]=s;
	}
	rep(i,v.size()) if(v[i]!=s) a[v[i]]=s;
	cout<<cnt<<endl;
	for(int i=1;i<=n;i++)
	{
		cout<<a[i];
		cout<<((i==n)?'\n':' ');
	}
	return 0;
}
/*
5
3 2 2 5 3
*/