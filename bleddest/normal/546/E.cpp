#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sqr(a) ((a) * (a))
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

template<class A, class B> ostream& operator << (ostream &out, pair<A, B> &a) {
	return out << "(" << a.x << ", " << a.y << ")";
}

template<class A> ostream& operator << (ostream &out, vector<A> &a) {
 	out << "[";
 	forn(i, sz(a)) {
 		if(i) out << ", ";
 		out << a[i];
 	}
 	return out << "]\n";
}

const int INF = int(1e9);
const li INF64 = li(1e18);
const int MOD = INF + 7;
const ld PI = acosl(-1.0);
const ld EPS = 1e-9; 
const int N = 202;
const int M = 5000;


struct edge
{
 	int y;
 	int cap;
 	int flow;
 	edge() {};
 	edge(int y, int cap, int flow = 0) : y(y), cap(cap), flow(flow) {};
};

edge e[M];
int sze;
vector<int> g[N];

void add_edge(int x, int y, int cap)
{
 	g[x].pb(sze);
 	e[sze++] = edge(y, cap);
 	g[y].pb(sze);
 	e[sze++] = edge(x, 0);
}

int d[N];
int last[N];
int q[M];
int vc;

inline int rem(int id)
{
   	return e[id].cap - e[id].flow;
}

bool bfs(int s, int t)
{
 	int hd = 0, tl = 0;
 	forn(i, vc) d[i] = -1;
 	q[tl++] = s;
 	d[s] = 0;
 	while(hd < tl && d[t] == -1)
 	{
 		int x = q[hd++];
 		
 		if(hd == M)
 			hd = 0;
 		for(auto num : g[x])
 		{
 		 	int y = e[num].y;
 		 	if (d[y] == -1 && rem(num))
 		 	{
 		 		q[tl++] = y;
 		 		if(tl == M)
 		 			tl = 0;
 		 		d[y] = d[x] + 1;	
 		 	}
 		}
 	}
 	return d[t] != -1;
}

int dfs(int x, int t, int mx)
{
 	if (!mx) return 0;
 	if (x == t) return mx;
 	int sum = 0;
 	for(; last[x] < sz(g[x]); last[x]++)
 	{
 	 	int id = g[x][last[x]];
 	 	int y = e[id].y;
 	 	if (d[y] != d[x] + 1)
 	 		continue;
 	 	int flow = dfs(y, t, min(mx, rem(id)));
 	 	if (flow)
 	 	{
 	 	 	e[id].flow += flow;
 	 	 	e[id ^ 1].flow -= flow;
 	 	 	mx -= flow;
 	 	 	sum += flow;
 	 	}
 	 	if (mx == 0)
 	 		break;
 	}
 	return sum;
}

int Dinic(int s, int t)
{
	int ans = 0;                  
 	while(true)
 	{
 	 	if (!bfs(s, t))
 	 		break;
 	 	forn(i, vc) 
 	 		last[i] = 0;
 	 	int add;
 	 	while(add = dfs(s, t, INF))
 	 		ans += add;
 	}
 	return ans;
}

int n, m;
int s;
int t;
int suma = 0, sumb = 0;
int ans[N][N];
 	

bool read() {
 	if(scanf("%d %d", &n, &m) != 2)
 		return false;
 	s = 2 * n;
 	t = 2 * n + 1;	
 	forn(i, n)
 	{
 	 	int a;
 	 	scanf("%d", &a);
 	 	add_edge(s, i * 2, a);
 	 	add_edge(i * 2, i * 2 + 1, a);
 	 	suma += a;
 	 	ans[i][i] = a;
 	}
 	forn(i, n)
 	{
     	int b;
     	scanf("%d", &b);
     	add_edge(i * 2 + 1, t, b);
     	sumb += b;
    }
    forn(i, m)
    {
     	int x, y;
     	scanf("%d %d", &x, &y);
     	--x;
     	--y;
     	add_edge(x * 2, y * 2 + 1, 100000);
     	add_edge(y * 2, x * 2 + 1, 100000);
    }
 	return true;
}


void solve() {
	vc = 2 * n + 2;
	int ans = Dinic(s, t);
	if (ans != max(suma, sumb))
	{
	 	puts("NO");
	 	return;
	}
	puts("YES");
	
	forn(i, n) 
		for(auto z : g[i * 2])
		{
		 	if (z & 1) continue;
		 	if (e[z].y == t)
		 		continue;
		 	::ans[i][e[z].y >> 1] = e[z].flow;
		}
   	forn(i, n)
   	{
   	 	forn(j, n) printf("%d ", ::ans[i][j]);
   	 	printf("\n");
   	}
}

int main() {
	
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tt = clock();
#endif

	srand(time(NULL));
	cout << fixed << setprecision(15);

	while(read()) {

		solve();

#ifdef _DEBUG
		cerr << "TIME = " << clock() - tt << " ms\n";
		tt = clock();
#endif

	}
	
	return 0;
}