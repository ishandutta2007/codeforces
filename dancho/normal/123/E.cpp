#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int n;
vector<int> g[100020];
double x[100020], y[100020];

int par[100020], ncnt[100020];

double ytot, xtot;
double ysm[100020][2];
double dp[100020][3];

double getYsm(int v, int d)
{
	if (ysm[v][d] == ysm[v][d])
	{
		return ysm[v][d];
	}
	if (d == 1)
	{
		double smdown = getYsm(v, 0);
		ysm[v][d] = ytot - smdown;
	}
	else
	{
		ysm[v][d] = y[v];
		for (int i = 0; i < (int) g[v].size(); ++i)
		{
			int u = g[v][i];
			if (u != par[v])
			{
				ysm[v][d] += getYsm(u, 0);
			}
		}
	}
	return ysm[v][d];
}

inline bool goodEdge(int w, int v, int u, int d)
{
	//~ printf("GED %d %d %d!\n", w, v, u);
	if (d == 2)
		return true;
	if (v == w && u == par[v])
		return false;
	if (w == par[v] && u == v)
		return false;
	return true;
}

double getDP(int v, int d)
{
	//~ printf("GET DP %d %d\n", v, d);
	if (dp[v][d] == dp[v][d])
	{
		return dp[v][d];
	}
	double ycr = ytot;
	if (d != 2)
		ycr = getYsm(v, d);
	if (ycr == 0)
	{
		return (dp[v][d] = 0);
	}
	double nsm = 0;
	int w = v;
	if (d == 1)
	{
		w = par[v];
		getDP(w, 2);
		double wsl = dp[w][2] * ytot;
		double wns = n - 1;
		double sol = wsl - getYsm(v, 0) * ((wns - ncnt[v]) + 1.0 + getDP(v, 0));
		sol -= (ytot - y[w] - getYsm(v, 0)) * ncnt[v];
		dp[v][d] = sol / ycr;
		return dp[v][d];
	}
	for (int i = 0; i < (int) g[w].size(); ++i)
	{
		int u = g[w][i];
		if (goodEdge(w, v, u, d))
		{
			if (u == par[w])
			{
				nsm += n - ncnt[w];
			}
			else
			{
				nsm += ncnt[u];
			}
		}
	}

	double sol = 0.0;
	for (int i = 0; i < (int) g[w].size(); ++i)
	{
		int u = g[w][i];
		if (goodEdge(w, v, u, d))
		{
			if (u == par[w])
			{
				sol += getYsm(w, 1) * ((nsm - n + ncnt[w]) + 1.0 + getDP(w, 1));
			}
			else
			{
				sol += getYsm(u, 0) * ((nsm - ncnt[u]) + 1.0 + getDP(u, 0));
			}
		}
	}
	sol /= ycr;

	dp[v][d] = sol;
	//~ printf("DP %d %d %d %lf __ %lf\n", v, d, w, dp[v][d], ycr);
	return dp[v][d];
}

void dfs_par(int v)
{
	ncnt[v] = 1;
	for (int i = 0; i < (int) g[v].size(); i++)
	{
		int u = g[v][i];
		if (par[u] == -1)
		{
			par[u] = v;
			dfs_par(u);
			ncnt[v] += ncnt[u];
		}
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n - 1; ++i)
	{
		int j, k;
		scanf("%d %d", &j, &k);
		g[j].push_back(k);
		g[k].push_back(j);
	}
	ytot = xtot = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%lf %lf", &x[i], &y[i]);
		xtot += x[i];
		ytot += y[i];
	}
	
	
	memset(par, -1, sizeof(par));
	par[1] = 0;
	dfs_par(1);
	
	memset(ysm, -1, sizeof(ysm));
	memset(dp, -1, sizeof(dp));
	
	double ans = 0.0;
	for (int i = 1; i <= n; ++i)
	{
		ans += x[i] * getDP(i, 2);
	}
	ans /= xtot;
	
	printf("%.12lf\n", ans);
	return 0;
}