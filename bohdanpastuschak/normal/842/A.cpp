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

#define ld long double
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll,ll>
#define MP make_pair
#define MT make_tuple
#define SZ(a) ll((a).size())
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
#define PI 3.141592653589793
using namespace std;

#define mod 1000000007
#define INF (ll)1e18
#define MAXN 100001
#define alphabet_size 26

int n;

vvi g;
vll dist;
vi ancestor;
vch used;

void graph_init()
{
	used.assign(n + 1, 0);
	dist.assign(n + 1, INF);
	ancestor.assign(n + 1, -1);
	g.assign(n + 1, vi());
}

void dfs(int v)
{
	used[v] = 1;
	for (auto i : g[v])
		if (used[i] == 0)
			dfs(i);
}

void bfs(int v)
{
	queue<int> q;
	q.push(v);
	used[v] = 1;
	dist[v] = 0;
	ancestor[v] = 0;
	while (!q.empty())
	{
		int top = q.front();
		q.pop();
		for(auto i: g[top])
			if (used[i] == 0)
			{
				used[i] = 1;
				q.push(i);
				ancestor[i] = top;
				dist[i] = dist[top] + 1;
			}
	}
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);
	
	//cin >> n;
	
	//graph_init();

	ll l, r, x, y, k;
	cin >> l >> r >> x >> y >> k;

	FOR(i,l,r+1)
		if (i%k==0)
			if (x <= i / k && y >= i / k)
			{
				cout << "YES";
				return 0;
			}

	cout << "NO";

	return 0;
}