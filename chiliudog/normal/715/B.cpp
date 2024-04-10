#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef long double ld;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

const int N = 1001;
const int M = 10001;
const ll INF = ll(1e18);

vector<ii> adj[N];
vector<int> adj2[N];
int L[M]; int R[M];
ll d1[N];
ll d2[N];
int par[N];
ll dist[N][N];

int n, m, l, s, e;

void dijkstra()
{
	d1[s] = 0;
	priority_queue<ii, vector<ii>, greater<ii> > pq;
	pq.push(ii(0, s));
	int cnt = 0;
	while(!pq.empty())
	{
		cnt++;
		int u = pq.top().se; ll d = pq.top().fi; pq.pop();
		for(int i = 0; i < adj[u].size(); i++)
		{
			int v = adj[u][i].fi; ll w = adj[u][i].se;
			if(d + w < d1[v])
			{
				d1[v] = d + w;
				pq.push(ii(d1[v], v));
			}
		}
	}
	cerr << "DIJKSTRA OPERATIONS : " << cnt << '\n';
}

bool dijkstra2()
{
	d2[s] = 0;
	priority_queue<ii, vector<ii>, greater<ii> > pq;
	pq.push(ii(0, s));
	while(!pq.empty())
	{
		int u = pq.top().se; ll d = pq.top().fi; pq.pop();
		for(int i = 0; i < adj2[u].size(); i++)
		{
			int v = adj2[u][i]; ll w = dist[u][v];
			if(d + abs(w) < d2[v])
			{
				d2[v] = d + abs(w);
				par[v] = u;
				pq.push(ii(d2[v], v));
			}
		}
	}
	if(d2[e] > l) return false;
	int cur = e;
	while(cur != s)
	{
		int p = par[cur];
		if(dist[p][cur] < 0)
		{
			dist[p][cur] = -2; dist[cur][p] = -2;
		}
		cur = par[cur];
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(dist[i][j] == -1)
			{
				dist[i][j] = INF;
			}
		}
	}
	cur = e;
	while(cur != s)
	{
		int p = par[cur];
		if(dist[p][cur] < 0)
		{
			dist[p][cur] = -1; dist[cur][p] = -1;
		}
		cur = par[cur];
	}
	return true;
}

void print()
{
	cout << "YES\n";
	for(int i = 0; i < m; i++)
	{
		int u = L[i]; int v = R[i];
		ll d = dist[u][v];
		if(d < 0) d = -d;
		cout << u << ' ' << v << ' ' << d << '\n';
	}
}

bool relax()
{
	for(int i = 0; i < n; i++) d2[i] = INF;
	memset(par, -1, sizeof(par)); //shouldn't be neccesary
	d2[s] = 0;
	priority_queue<ii, vector<ii>, greater<ii> > pq;
	pq.push(ii(0, s));
	while(!pq.empty())
	{
		int u = pq.top().se; ll d = pq.top().fi; pq.pop();
		for(int i = 0; i < adj2[u].size(); i++)
		{
			int v = adj2[u][i]; ll w = dist[u][v];
			if(d + abs(w) < d2[v])
			{
				d2[v] = d + abs(w);
				par[v] = u;
				pq.push(ii(d2[v], v));
			}
		}
	}
	//cerr << d2[e] << '\n';
	if(d2[e] == l) return true;
	int cur = e; bool meet = false;
	while(cur != s)
	{
		int p = par[cur];
		if(!meet && dist[p][cur] < 0)
		{
			ll d = abs(dist[p][cur]);
			dist[p][cur] = d + l - d2[e];
			dist[cur][p] = d + l - d2[e];
			//cerr << d << endl;
			meet = true;
		}
		if(meet) break;
		cur = par[cur];
	}
	return false;
}

int dist1[N][N];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> l >> s >> e;
	memset(dist1, -1, sizeof(dist1));
	for(int i = 0; i < m; i++)
	{
		int u, v, w; cin >> u >> v >> w;
		if(w > 0)
		{
			adj[u].pb(ii(v, w)); adj[v].pb(ii(u, w));
			adj2[u].pb(v); adj2[v].pb(u);
			dist1[u][v] = w; dist1[v][u] = w;
			dist[u][v] = w; dist[v][u] = w;
		}
		else
		{
			adj2[u].pb(v); adj2[v].pb(u);
			dist[u][v] = -1; dist[v][u] = -1;
		}
		L[i] = u; R[i] = v;
	}
	for(int i = 0; i < n; i++)
	{
		d1[i] = INF; d2[i] = INF;
	}
	dijkstra(); //cerr << d1[e] << '\n';
	if(d1[e] < l)
	{
		cout << "NO\n";
		return 0;
	}
	if(d1[e] == l)
	{
		cout << "YES\n";
		for(int i = 0; i < m; i++)
		{
			int u = L[i]; int v = R[i];
			ll d = dist1[u][v];
			if(d <= 0) d = INF;
			cout << u << ' ' << v << ' ' << d << '\n';
		}
		return 0;
	}
	bool tmp = dijkstra2();
	if(!tmp)
	{
		cout << "NO\n";
		return 0;
	}
	//cerr << d2[e] << '\n';
	int cnt = 0;
	while(!relax())
	{
		relax(); cnt++;
	}
	cerr << "RELAXATIONS DONE : " << cnt << '\n';
	print();
}