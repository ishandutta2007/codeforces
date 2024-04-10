#include <bits/stdc++.h>
using namespace std;
const int N=200001;
typedef long long ll;
const ll MOD=(ll)1e9+7;
typedef pair<ll,ll> pii;
#define mk make_pair

int n;
ll val[N],tmp[N];
vector<int> v[N];
vector<pii> st[N];

ll gcd(ll x,ll y)
{
	if(x<y) swap(x,y);
	if(y==0) return x;
	return gcd(y,x%y); 
}

void dfs(int u,int f)
{
	vector<pii> A; A.clear();
	st[u].push_back(mk(val[u],1LL));
	sort(st[u].begin(),st[u].end());
	for(int i=0;i<(int)st[u].size();i++)
	{
		tmp[i]=st[u][i].first;
	}
	int m=unique(tmp,tmp+(int)st[u].size())-tmp;
	int now=0;
	for(int i=0;i<(int)st[u].size();i++)
	{
		if(A.empty()) A.push_back(st[u][i]);
		else
		{
			if(st[u][i].first==tmp[now]) A[now].second+=st[u][i].second;
			else 
			{
				A.push_back(st[u][i]);
				now++;
			}
		}
	}
	st[u].clear();
	for(int i=0;i<(int)A.size();i++) st[u].push_back(A[i]);
	A.clear();
	for(int i=0;i<(int)v[u].size();i++)
	{
		int to=v[u][i];
		if(to==f) continue;
		for(int j=0;j<(int)st[u].size();j++)
		{
			st[to].push_back(mk(gcd(st[u][j].first,val[to]),st[u][j].second));
		}
		dfs(to,u);
	}
}

int main() 
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&val[i]);
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1,-1);
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<(int)st[i].size();j++)
		{
			//cout<<i<<" "<<st[i][j].first<<" "<<st[i][j].second<<endl;
			ans=(ans+st[i][j].first*st[i][j].second%MOD)%MOD;
		}
	}
	cout<<ans<<endl;
	return 0;
}