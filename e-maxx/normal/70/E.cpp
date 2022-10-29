#define _CRT_SECURE_NO_DEPRECATE
#pragma comment (linker, "/STACK:200000000")
#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;


const int MAXN = 190;
const long long INF = (long long) 1E18;


int n, w, cost[MAXN*2];
vector<int> g[MAXN], gorig[MAXN];

void dfs (int v, int par = -1) {
	if (par != -1)
		g[v].erase (find (g[v].begin(), g[v].end(), par));
	for (size_t i=0; i<g[v].size(); ++i)
		dfs (g[v][i], v);
}


long long d[MAXN][MAXN*2], d2[MAXN][MAXN*2], d3[MAXN][MAXN*2];
bool ans[MAXN];


long long get_d (int v, int k);
long long get_d2 (int v, int k);

long long get_d3 (int v, int p) {
	long long & my = d3[v][p];
	if (my != -1)  return my;
	my = INF;

	long long sum = cost[p];
	for (size_t i=0; i<g[v].size(); ++i)
		sum += get_d (g[v][i], p+1);
	
	for (size_t i=0; i<g[v].size(); ++i) {
		int to = g[v][i];
		long long nd = sum - get_d (to, p+1) + get_d2 (to, p-1);
		my = min (my, nd);
	}

	if (p-1 >= 1)
		my = min (my, get_d3 (v, p-1));
	return my;
}

long long get_d (int v, int k) {
	long long & my = d[v][k];
	if (my != -1)  return my;
	my = INF;

	if (k != 0)
		my = min (my, get_d (v, 0) + w);

	long long nd = cost[k];
	for (size_t i=0; i<g[v].size(); ++i)
		nd += get_d (g[v][i], k+1);
	my = min (my, nd);

	if (k-1 >= 1)
		my = min (my, get_d3 (v, k-1));
	return my;
}

long long get_d2 (int v, int k) {
	long long & my = d2[v][k];
	if (my != -1)  return my;
	my = INF;
	
	if (k == 0)
		my = w + get_d (v, 0);
	else {
		long long sum = cost[k];
		for (size_t i=0; i<g[v].size(); ++i)
			sum += get_d (g[v][i], k+1);
		
		for (size_t i=0; i<g[v].size(); ++i) {
			int to = g[v][i];
			long long nd = sum - get_d (to, k+1) + get_d2 (to, k-1);
			my = min (my, nd);
		}
	}

	return my;
}


void restore_d2 (int v, int k);

void restore_d (int v, int k) {
	long long my = get_d (v, k);

	if (k != 0 && my == get_d (v, 0) + w) {
		ans[v] = true;
		return restore_d (v, 0);
	}

	long long nd = cost[k];
	for (size_t i=0; i<g[v].size(); ++i)
		nd += get_d (g[v][i], k+1);
	if (my == nd) {
		for (size_t i=0; i<g[v].size(); ++i)
			restore_d (g[v][i], k+1);
		return;
	}

	for (int p=1; p<k; ++p) {
		long long sum = cost[p];
		for (size_t i=0; i<g[v].size(); ++i)
			sum += get_d (g[v][i], p+1);
		
		for (size_t i=0; i<g[v].size(); ++i) {
			int to = g[v][i];
			long long nd = sum - get_d (to, p+1) + get_d2 (to, p-1);
			if (my == nd) {
				for (size_t j=0; j<g[v].size(); ++j) {
					int to = g[v][j];
					if (i == j)
						restore_d2 (to, p-1);
					else
						restore_d (to, p+1);
				}
				return;
			}
		}
	}
	throw;
}

void restore_d2 (int v, int k) {
	long long my = get_d2 (v, k);
	
	if (k == 0) {
		ans[v] = true;
		return restore_d (v, 0);
	}
	else {
		long long sum = cost[k];
		for (size_t i=0; i<g[v].size(); ++i)
			sum += get_d (g[v][i], k+1);
		
		for (size_t i=0; i<g[v].size(); ++i) {
			int to = g[v][i];
			long long nd = sum - get_d (to, k+1) + get_d2 (to, k-1);
			if (my == nd) {
				for (size_t j=0; j<g[v].size(); ++j) {
					int to = g[v][j];
					if (i == j)
						restore_d2 (to, k-1);
					else
						restore_d (to, k+1);
				}
				return;
			}
		}
	}
	throw;
}


int bfs (int v) {
	static int q[MAXN], u[MAXN], cu=0;

	int qh=0, qt=0;
	q[qt++] = v;
	u[v] = ++cu;
	while (qh != qt) {
		int v = q[qh++];
		if (ans[v])  return v;

		for (size_t i=0; i<gorig[v].size(); ++i) {
			int to = gorig[v][i];
			if (u[to] != cu) {
				u[to] = cu;
				q[qt++] = to;
			}
		}
	}
	throw;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);
#endif

	cin >> n >> w;
	for (int i=1; i<n; ++i)
		cin >> cost[i];
	for (int i=0; i<n-1; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		g[a].push_back (b);
		g[b].push_back (a);
	}
	
	for (int i=0; i<n; ++i)
		gorig[i] = g[i];
	dfs (0);

	for (int i=n; i<2*MAXN; ++i)
		cost[i] = 1000000000;
	memset (d, -1, sizeof d);
	memset (d2, -1, sizeof d2);
	memset (d3, -1, sizeof d3);
	long long res = get_d (0, n);
	cout << res << endl;
	restore_d (0, n);
	
	for (int i=0; i<n; ++i) {
		int res;
		if (ans[i])
			res = i;
		else
			res = bfs (i);
		cout << res+1 << ' ';
	}

}