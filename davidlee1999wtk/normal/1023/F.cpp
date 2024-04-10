#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cstdlib>
#include<string>
#include<bitset>
#include<iomanip>
#include<deque>
#include<utility>
#include<functional>
#include<sstream>
#include<ctime>
#define INF 1000000000
#define fi first
#define se second
#define N 500005
#define P 1000000007
#define debug(x) cerr<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
char _temp;
bool _flag;
inline void getint(int &_num)
{
	_num = _flag = 0;
	while (1)
	{
		_temp = getchar();
		if (_temp >= 48 && _temp <= 57)
		{
			_num = _num * 10 + _temp - 48;
			_flag = 1;
		}
		else if (_flag)
			return;
	}
}

vector<vector<int> > G(N);
int rt[N], vis[N];
int fa[N][20], dep[N], maxd, lg;
int n;
int flag = 0;
int findr(int x)
{
	return x == rt[x] ? x : rt[x] = findr(rt[x]);
}
int in[N], out[N], dfn = 0;
void dfs1(int x)
{
	int i, len = G[x].size();
	in[x] = ++dfn;
	maxd = max(maxd, dep[x]);
	for (i = 0; i < len; i++)
	{
		int y = G[x][i];
		if (!in[y])
		{
			fa[y][0] = x;
			dep[y] = dep[x] + 1;
			dfs1(y);
		}
	}
	out[x] = dfn;
}


void initlca()
{
	int i, j;
	lg = int(log(double(maxd)) / log(2.0) + 0.5);
	for (j = 1; j <= lg; j++)
		for (i = 1; i <= n; i++)
			fa[i][j] = fa[fa[i][j - 1]][j - 1];
}

inline int lca(int u, int v)
{
	if (dep[u]>dep[v]) swap(u, v);
	int i;
	for (i = lg; i >= 0; i--)
		if (dep[fa[v][i]] >= dep[u])
			v = fa[v][i];
	if (u == v) return u;
	for (i = lg; i >= 0; i--)
		if (fa[v][i] != fa[u][i])
			u = fa[u][i], v = fa[v][i];
	return fa[v][0];
}


vector<vector<pii> > tag(N);
int tr[N*4], qk, ql, qr, qw, rel;
LL ans = 0;

void Add(int o, int L, int R)
{
	if (L == R)
	{
		tr[o] = min(tr[o], qw);
		return;
	}
	int mid = (L + R) >> 1;
	if (qk <= mid)
		Add(o << 1, L, mid);
	else Add(o << 1 | 1, mid + 1, R);
	tr[o] = min(tr[o << 1], tr[o << 1 | 1]);
}

void Get(int o, int L, int R)
{
	if (ql <= L && qr >= R)
	{
		rel = min(rel, tr[o]);
		return;
	}
	int mid = (L + R) >> 1;
	if (ql <= mid)
		Get(o << 1, L, mid);
	if (qr > mid)
		Get(o << 1 | 1, mid + 1, R);
}

void dfs2(int x)
{
	int i, len = G[x].size();
	ql = in[x], qr = out[x];
	rel = INF * 2;
	Get(1, 1, n);
	if (fa[x][0] != x)
	{
		if (rel == INF * 2)
			flag = 1;
		else
			ans += rel;
	}
	for (i = 0; i < tag[x].size(); i++)
	{
		qk = in[tag[x][i].fi];
		qw = tag[x][i].second;
		//debug(qk);
		//debug(qw);
		Add(1, 1, n);
	}
	for (i = 0; i < len; i++)
	{
		int y = G[x][i];
		if (y!=fa[x][0])
		{
			dfs2(y);
		}
	}
	
}

int main()
{
	int k, m, a, b, i, c;
	cin >> n >> k >> m;
	for (i = 1; i <= n*4; i++)
		tr[i] = INF*2;
	for (i = 1; i <= n; i++)
		rt[i] = i;
	for (i = 1; i <= k; i++)
	{
	    scanf("%d%d",&a,&b);
		//getint(a);
		//getint(b);
		G[a].push_back(b);
		G[b].push_back(a);
		int f_a = findr(a), f_b = findr(b);
		rt[f_b] = f_a;
	}
	vector<int> qa, qb, qc;
	for (i = 1; i <= m; i++)
	{
	    scanf("%d%d%d",&a,&b,&c);
		//getint(a);
		//getint(b);
		//getint(c);
		if (findr(a) != findr(b))
		{
			G[a].push_back(b);
			G[b].push_back(a);
			int f_a = findr(a), f_b = findr(b);
			rt[f_b] = f_a;
			ans -= c;
			//continue;
		}
		qa.push_back(a);
		qb.push_back(b);
		qc.push_back(c);
	}

	for (i = 1; i <= n; i++)
		if (!in[i])
		{
			fa[i][0] = i;
			dfs1(i);
		}
	initlca();

	for(i=0;i<qa.size();i++)
	{
		a = qa[i], b = qb[i], c = qc[i];
		int Lca = lca(a, b);
		//debug(a);
		//debug(b);
		//debug(Lca);
		tag[Lca].push_back(MP(a, c));
		tag[Lca].push_back(MP(b, c));
	}
	
	for (i = 1; i <= n; i++)
		if (fa[i][0] == i)
			dfs2(i);
	if (flag == 1)
		cout << -1 << endl;
	else
		cout << ans << endl;
	return 0;
}
// davidlee1999WTK 2017/
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000") compiler c++,not g++
//#include<bits/stdc++.h>
/*

*/