#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <list>
#include <map>
#include <queue>
#include <iterator>
#include <iomanip>
#include <stdio.h>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <utility>
#include <functional>
#include <stack>
#include <deque>
#include <sstream>
using namespace std;

#define ll long long
#define mod 1000000009
#define ld long double
#define infinity (ll)1e18+1
#define PI 3.14159265358979

#define pdd pair<double,double>
#define pll pair<ll, ll>
#define pii pair<int,int>

#define MP make_pair
#define SZ size()
#define PB push_back

#define vi vector<int>//ll
#define vll vector<ll>
#define vpll vector<pll>
#define vpii vector<pii>
#define vch vector<char>
#define vb vector<bool>
#define vld vector<ld>
#define vs vector<string>

#define FOR(i,a,b) for(ll i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(ll i = (b) - 1; i >= (a); --i)
#define REPEAT(i) FOR(counter1234,0,i)
#define ALL(a) a.begin(), a.end()
#define X first
#define Y second
#define MAXN 200001

vi g[MAXN];
int p[MAXN];
int distToRoot[MAXN];
int distToAnc[MAXN];

int n;
int x;
int dist[MAXN];
vch used;

vi leafs;

void bfs(int v)
{
	dist[v] = 0;
	queue<int> q;
	q.push(v);
	used[v] = 1;
	while (!q.empty())
	{
		int t = q.front();
		q.pop();
		int c = 0;
		for (auto i : g[t])
			if (used[i] == 0)
			{
				used[i] = 1;
				q.push(i);
				dist[i] = dist[t] + 1;
				p[i] = t;
				++c;
			}

		if (c == 0)
			leafs.push_back(t);
	}
}

int main()
{
	srand(time(NULL));
	clock_t startTime = clock();
	ios_base::sync_with_stdio(false), cin.tie(0);
	//ifstream in("In.txt");
	
	cin >> n >> x;

	int aa, bb;
	FOR(i, 0, n - 1)
	{
		cin >> aa >> bb;
		g[aa].push_back(bb);
		g[bb].push_back(aa);
	}

	used.assign(n + 1, 0);
	bfs(1);

	int distToX = dist[x];

	if (distToX % 2 == 1)
	{
		int turns = distToX / 2;
		int curr = x;
		REPEAT(turns)
			curr = p[curr];

		FOR(i, 1, MAXN)
			distToRoot[i] = dist[i];

		int ans = turns * 2;
		used.assign(n + 1, 0);
		bfs(p[curr]);
		FOR(i, 1, MAXN)
			distToAnc[i] = dist[i];

		used.assign(n + 1, 0);
		bfs(curr);

		int longest = 0;
		for (auto l : leafs)
		{
			if (distToAnc[l] > dist[l])
				longest = max(longest, dist[l]);
		}

		ans += (2 * longest + 2);
		cout << ans;
	}
	else
	{
		int turns = distToX / 2 - 1;
		int curr = x;
		REPEAT(turns)
			curr = p[curr];

		FOR(i, 1, MAXN)
			distToRoot[i] = dist[i];

		int ans = distToX;
		used.assign(n + 1, 0);
		bfs(p[curr]);
		FOR(i, 1, MAXN)
			distToAnc[i] = dist[i];

		used.assign(n + 1, 0);
		bfs(curr);

		int longest = 0;
		for (auto l : leafs)
		{
			if (distToAnc[l] > dist[l])
				longest = max(longest, dist[l]);
		}

		ans += (2 * longest + 2);
		cout << ans;
	}
	return 0;
}