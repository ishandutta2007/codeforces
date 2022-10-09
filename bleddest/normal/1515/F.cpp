#include<set>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long li;
#define x first
#define y second

const int N = 300043;

li a[N];
li cnt[N];
li sum[N];
li bal[N];
int used[N];
li n, c;
vector<pair<int, int>> g[N];
set<pair<int, int>> g2[N];

void dfs1(int x)
{
	used[x] = 1;
	for(auto y : g[x])
	{
	 	int to = y.x;
	 	if(used[to] == 0)
	 	{
	 	    g2[x].insert(y);
	 	    g2[y.x].insert(make_pair(x, y.y));
	 	    dfs1(to);
	 	}	
	}
}

void dfs2(int x, int p)
{
	cnt[x] = 1;
	sum[x] = a[x];
 	for(auto y : g2[x])
 	{
 		if(y.x == p) continue;
 		dfs2(y.x, x);
 		cnt[x] += cnt[y.x];
 		sum[x] += sum[y.x];
 	}
 	bal[x] = sum[x] - (cnt[x] - 1) * c;
}

set<pair<li, int>> comps;
vector<int> ans;

int p[N];

int get_leader(int x)
{
	return (p[x] == x ? x : p[x] = get_leader(p[x]));
}

int ex[N];
int ey[N];

int choose(int a, int b, int c)
{
 	if(a == b) return c;
 	return b;
}

void merge_components(int x, int y, int w)
{
	comps.erase(make_pair(a[x], x));
	comps.erase(make_pair(a[y], y));
	auto it = g2[x].lower_bound(make_pair(w, -1));
	ans.push_back(it->y);
	if(g2[x].size() < g2[y].size())
		swap(x, y);                                  
	for(auto z : g2[y])
		if(get_leader(z.x) != x)
			g2[x].insert(z);
	a[x] -= c;
	a[x] += a[y];
	p[y] = x;
	if(a[x] < 0)
	{
	 	cout << "NO\n";
	 	exit(0);
	}
	comps.insert(make_pair(a[x], x)); 	
}

void solve()
{
	int m;
	cin >> n >> m >> c;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 1; i <= m; i++)
	{
	 	int x, y;
	 	cin >> x >> y;
	 	--x;
	 	--y;
	 	ex[i] = x;
	 	ey[i] = y;
	 	g[x].push_back(make_pair(y, i));
	 	g[y].push_back(make_pair(x, i));
 	}
 	dfs1(0);
 	dfs2(0, 0);
 	if(bal[0] < 0)
 		cout << "NO\n";
 	else
 	{         
 		for(int i = 0; i < n; i++)
 		{
 			p[i] = i;
 			comps.insert(make_pair(a[i], i));
 		}
 	 	while(comps.size() > 1)
 	 	{
 	 	 	int x = comps.rbegin()->y;
 	 	 	int y, l;
 	 	 	while(get_leader(g2[x].begin()->x) == get_leader(x))
 	 	 		g2[x].erase(g2[x].begin());
 	 	 	for(auto z : g2[x])
 	 	 	{
 	 	 	 	int w = z.x;
 	 	 	 	if(a[get_leader(w)] + a[x] >= c)
 	 	 	 	{
 	 	 	 	 	y = get_leader(w);
 	 	 	 	 	l = w;
 	 	 	 	 	break;
 	 	 	 	}
 	 	 	}
 	 	 	//cerr << x << " " << y << endl;
 	 	 	merge_components(x, y, l);
 	 	}
 	 	cout << "YES\n";                
 	 	for(auto x : ans) cout << x << " ";
 	 	cout << endl;	
 	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
	int tc = 1;
	for(int i = 0; i < tc; i++)
	{
	 	solve();
	}
}