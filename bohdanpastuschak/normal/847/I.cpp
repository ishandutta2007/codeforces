#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <iterator>
#include <functional>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <fstream>
#include <iomanip>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <cmath>
#include <list>
#include <sstream>
#include <tuple>
#include <complex>

#define ld double
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll,ll>
#define MP make_pair
#define MT make_tuple
#define SZ(a) (ll)((a).size())
#define X first
#define Y second
#define endl '\n'
#define PB push_back
#define has(i, m) (m.find(i) != m.end())

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(int i = (b) - 1; i >= (a); --i)
#define REPEAT(t) FOR(name_that_will_never_apper, 0, t)
#define iter(el, arr) for(auto& el : arr)
#define ALL(a) a.begin(), a.end()

#define vi vector<int>
#define vll vector<ll>
#define vld vector<ld>
#define vch vector<char>
#define vb vector<bool>
#define vvi vector<vi>
#define vvll vector<vll>
#define vpii vector<pii>
#define vpll vector<pll>
#define vvch vector<vch>
#define vvb vector<vb>
#define vs vector<string>
#define vss vector<vs>
#define pdd pair<ld, ld>
#define vpll vector<pll>
#define vpdd vector<pdd>
#define base complex<double>
#define PI 3.141592653589793
#define alphabet_size 26
using namespace std;

#define mod 1000000007
#define INF (ll)1e18
#define MAXN 251

ll n, m, q, p;

ll a[MAXN][MAXN];
char f[MAXN][MAXN];
vi g[MAXN*MAXN];

int dist[MAXN*MAXN];
vch used;
vi pushed;

void bfs(int v)
{
	pushed.clear();
	queue<int> q;
	q.push(v);
	dist[v] = 0;
	vch used(MAXN*MAXN, 0);
	used[v] = 1;
	pushed.push_back(v);
	while (!q.empty())
	{
		int t = q.front();
		q.pop();
		if (dist[t] > 25)
			break;
		for(auto i: g[t])
			if (used[i] == 0)
			{
				q.push(i);
				used[i] = 1;
				dist[i] = dist[t] + 1;
				pushed.push_back(i);
			}
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	cin >> n >> m >> q >> p;

	FOR(i, 0, n)
		FOR(j, 0, m)
		cin >> f[i + 1][j + 1];

	//(i,j) -> i*MAXN + j;

	FOR(i,1,n+1)
		FOR(j, 1, m + 1)
		if (f[i][j] != '*')
		{
			int c = i*MAXN + j;
			pii s;

			s = MP(i - 1, j);
			if (s.X > 0 && s.X <= n && s.Y > 0 && s.Y <= m && f[s.X][s.Y] != '*')
				g[c].push_back(s.X*MAXN + s.Y);

			s = MP(i + 1, j);
			if (s.X > 0 && s.X <= n && s.Y > 0 && s.Y <= m && f[s.X][s.Y] != '*')
				g[c].push_back(s.X*MAXN + s.Y);

			s = MP(i, j - 1);
			if (s.X > 0 && s.X <= n && s.Y > 0 && s.Y <= m && f[s.X][s.Y] != '*')
				g[c].push_back(s.X*MAXN + s.Y);

			s = MP(i, j + 1);
			if (s.X > 0 && s.X <= n && s.Y > 0 && s.Y <= m && f[s.X][s.Y] != '*')
				g[c].push_back(s.X*MAXN + s.Y);
		}

	ll p2[26];
	p2[0] = 1;
	FOR(i, 1, 26)
		p2[i] = 2LL * p2[i - 1];

	ll ans = 0;

	FOR(i,1,n+1)
		FOR(j, 1, m + 1)
		if (f[i][j] >= 'A' && f[i][j] <= 'Z')
		{
			bfs(i*MAXN + j);
			for (auto kl : pushed)
				a[kl / MAXN][kl%MAXN] += (q * 1LL * (f[i][j] - 'A' + 1)) / p2[dist[kl]];
		}


	FOR(i, 1, n + 1)
		FOR(j, 1, m + 1)
		if (a[i][j] > p)
			ans++;

	cout << ans;
	//cin >> n;
	return 0;
}