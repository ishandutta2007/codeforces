#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
using namespace std;
const int nax = 200005;
int n, a, b;
vector <int> v[nax], ans;
int col[nax];
void dfs(int node, int par)
{
	int ile = col[node];
	for(auto it: v[node])
	{
		dfs(it, node);
		ile += col[it];
	}
	if(ile == ss(v[node]) + 1)
		ans.pb(node);
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n;
	int root = -1;
	for(int i = 1; n >= i; ++i)
	{
		cin >> a >> b;
		if(a == -1)
		{
			root = i;
		}
		else
			v[a].pb(i);
		col[i] = b;
	}
	dfs(root, -1);
	sort(ans.begin(), ans.end());
	if(!ss(ans))
		cout << -1;
	else
	{
		for(auto it: ans)
			cout << it << " ";
	}
	
	return 0;
}