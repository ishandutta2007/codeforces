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

const int N = 200 * 1000 + 43;

int p[N];
int n, k;

vector<int> g[N];

bool read() {
 	if(scanf("%d %d", &n, &k) != 2)
 		return false;
 	return true;
}

void dfs(int x, int cd, vector<int>& d)
{
 	if (d[x] < INF)
 		return;
 	d[x] = cd;
 	for(auto y : g[x])
 		dfs(y, cd + 1, d);
}

void solve() {
	int bs = n % k;
	if (bs == 0) bs = k;
	int cur = 1;
	vector<int> fr;
	for(int i = 1; i < bs; i++, cur++)
	{
		fr.pb(cur);
		p[cur] = 0;
	}
	if (bs == 1 || bs == 2)
		fr.pb(0);
	while(cur < n)
	{
		int last = fr.back();
		vector<int> nfr;
		for(int i = 0; i < k; i++, cur++)
		{
			if (fr.empty())
				p[cur] = last;
			else
				p[cur] = fr.back();
			if (!fr.empty()) fr.pop_back();
			nfr.pb(cur);
					
		}
		fr = nfr;

  	}
  	for(int i = 1; i < n; i++)
  	{
  	 	g[p[i]].pb(i);
  	 	g[i].pb(p[i]);
  	}
  	vector<int> dist(n, INF);
  	dfs(0, 0, dist);
  	int z = max_element(dist.begin(), dist.end()) - dist.begin();
  	forn(i, n) dist[i] = INF;
  	dfs(z, 0, dist);
  	int ans = *max_element(dist.begin(), dist.end());
  	printf("%d\n", ans);
  	for(int i = 1; i < n; i++)
  		printf("%d %d\n", p[i] + 1, i + 1);
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