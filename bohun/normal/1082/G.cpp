#include <bits/stdc++.h>
#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
using namespace std;
const int nax = 2005;
const ll inf = 1e18;
struct flow{
	int n;
	vector <int> v[nax];
	ll prze[nax][nax];
	vector <int> :: iterator pocz[nax];
	int odl[nax], q[nax];
	void init(int _n)
	{
		n = _n;
	}
	void add(int a, int b, ll c)
	{
		v[a].pb(b);
		v[b].pb(a);
		prze[a][b] += c;
	}
	int bfs(int s, int t)
	{
		for(int i = 1; n >= i; ++i)
			odl[i] = -1;
		odl[s] = 0;
		int p = 0, k = 0;
		q[k++] = s;
		while(k > p)
		{
			int node = q[p++];
			for(auto it: v[node])
			{
				if(odl[it] == -1 && prze[node][it] > 0)
				{
					odl[it] = odl[node] + 1;
					q[k++] = it;
				}
			}
		}
		return odl[t] != -1;
	}
	ll dfs(int node, int t, ll ile)
	{
		if(node == t || ile == 0)
			return ile;
		ll out = 0;
		for(vector <int> :: iterator &it = pocz[node]; it != v[node].end(); ++it)
		{
			if(odl[*it] == odl[node] + 1 && prze[node][*it])
			{
				ll c = dfs(*it, t, min(ile, prze[node][*it]));
				prze[node][*it] -= c;
				prze[*it][node] += c;
				ile -= c;
				out += c;
				if(ile == 0)
					break;
			}
		}
		return out;
	}	
	ll maxflow(int s, int t)
	{
		ll ans = 0;
		while(bfs(s, t))
		{
			for(int i = 1; n >= i; ++i)
				pocz[i] = v[i].begin();
			ans += dfs(s, t, inf);
		}
		return ans;
	}
			
};
	
flow ja;
	
int n, m;
vector <pair<int, int>> v[nax];
int a, b, c;	
int w[nax];


int main(){
	ll res = 0;
	scanf("%d %d", &n, &m);
	for(int i = 1; n >= i; ++i)
		scanf("%d", &w[i]), ja.add(i, n + m + 2, w[i]);
	ja.init(n + m + 2);
	for(int i = 1; m >= i; ++i)
	{
		scanf("%d %d %d", &a, &b, &c);
		res += c;
		ja.add(n + i, a, inf);
		ja.add(n + i, b, inf);
		ja.add(n + m + 1, n + i, c);
	}
	printf("%lld", res - ja.maxflow(n + m + 1, n + m + 2));
	

  return 0;
}