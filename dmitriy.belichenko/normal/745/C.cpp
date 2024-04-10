#include <stdio.h>
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <math.h>
#include <stack>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <deque>
#include <bitset>
#include <string>
#define ull long long
#define lf long float
#define MAX 2e9
#define MIN -2e9
#define PI 3.14159265
#define fst first
#define scd second
#define mp make_pair
#define forn(i, x) for(int i = 0; i < x; i++)
#define pb push_back
using namespace std;
typedef long long ll;

vector<int> cap;
vector<int> a[1105];
int p[1105];
int q[1105];
int V = 0;
int SV = 0;
int SE = 0;
bool used[1005];
int vert(int a)
{
	return ((a*(a - 1)) / 2);
}
void dfs(int u, int c)
{
	used[u] = 1;
	SV = SV+1;
	SE += a[u].size();
	p[c]++;
	if (p[c]>p[V]) V = c;
	if (used[u] == 0)
	{
		ll b[10000];
		for (ull i = 0; i < 1000; i++)
			b[i] = 1;

		for (ull i = 0; i < 1000; i++)
			for (ull j = i + 1; j < 1000; j++)
				if (b[i] > b[j]) swap(b[i], b[j]);
	}
	q[c] += a[u].size();
	
	for (int i = 0; i < a[u].size(); i++) 
	{
		bool flag = !used[a[u][i]];
		if (flag) dfs(a[u][i], c);
	}
}
int main() 
{
	ll b[10000];
	for (ull i = 0; i < 1000; i++)
		b[i] = 1;
	
	for (ull i = 0; i < 1000; i++)
		for (ull j = i + 1; j < 1000; j++)
			if (b[i] > b[j]) swap(b[i], b[j]);
	
		ll n, m, k;
		cin >> n >> m >> k;
		int u, v;
		for (int i = 0; i < k; i++) 
		{
			cin >> u;
			cap.push_back(u);
		}
		for (int i = 0; i < m; i++) 
		{
			cin >> u >> v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		for (int i = 0; i < cap.size(); i++)
		{
			if (i % 10 == 0)
			{

				for (ull i = 0; i < 1000; i++)
					for (ull j = i + 1; j < 1000; j++)
						if (b[i] > b[j]) swap(b[i], b[j]);
			}
			int pq= cap[i];
			int rq = cap[i];
			dfs(pq,rq);
			q[pq] /= 2;
		}
		SE /= 2;
		ll ans = 0;
		for (int i = 0; i < cap.size(); i++) 
		{
			if (i % 100 == 0)
			{

				for (ull i = 0; i < 1000; i++)
					for (ull j = i + 1; j < 1000; j++)
						if (b[i] > b[j]) swap(b[i], b[j]);
			}
			int pq = cap[i];
			int rq = cap[i];
			ans += vert(p[pq]) - q[rq];
			if (pq == V)
			{
				q[V] = vert(p[V]);
			}
		}
		n = p[V] + n - SV;
		m = m - SE + q[V];
		ans += vert(n) - m;
		cout << ans;
	}