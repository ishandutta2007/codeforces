#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define pb push_back
#define nodes first.first
#define edges first.second
#define isGov second

typedef pair <int, int> pii;
typedef pair <pii, int> p3;
typedef long long ll;

const int N = 1010;

int c[N];
bool gov[N] = {0}, seen[N] = {0};
vector <int> g[N];

p3 bfs(int);
ll choose2(ll n);

int main() {
	int n, m, k, u, v;
	cin >> n >> m >> k;
	
	for (int i = 0; i < k; ++i)
	{
		cin >> c[i];
		gov[c[i]] = true;
	}
	
	for (int i = 0; i < m; ++i)
	{
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	
	ll largestGov = -1, nonGovSize = 0, ans = 0;
	
	for (int i = 1; i <= n; ++i)
	{
		if (!seen[i])
		{
			p3 temp = bfs(i);
			ans += choose2(temp.nodes) - temp.edges;
			// cout <<i << endl;
			
			if (temp.isGov)
			{
				if (temp.nodes > largestGov)
					largestGov = temp.nodes;
			}
				
			else if (!temp.second)
			{
				ans += nonGovSize * temp.nodes;
				nonGovSize += temp.nodes;
			}
		}
	}
	
	ans += nonGovSize * largestGov;
	cout << ans;
}

ll choose2(ll n)
{
	return n*(n-1)/2;
}

p3 bfs(int st)
{
	seen[st] = true;
	queue<int> q;
	q.push(st);
	p3 ans = {{1, 0}, gov[st]};
	
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		
		ans.edges += g[cur].size();
		for (auto i : g[cur])
		{
			if (!seen[i])
			{
				q.push(i);
				seen[i] = true;
				ans.nodes++;
				ans.isGov |= gov[i];
			}
			
		}
	}
	
	ans.edges /= 2;
	return ans;
}