#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#define setIO(x) freopen(x".in", "r", stdin), freopen(x".out", "w", stdout)
#define closefile fclose(stdin), fclose(stdout)
#define m_p make_pair
#define sz(x) (int)x.size()
#define see(x) cerr << x << " "
#define seeln(x) cerr << x << endl
#define out(x) cerr << #x << " = " << x << " "
#define outln(x) cerr << #x << " = " << x << endl
#define outarr(x, l, r) {cerr<< #x"[" << l << " ~ " << r << "] = "; for (int _i = l; _i <= r; ++_i) cerr << x[_i] << " "; cerr << endl;}
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define gc() getchar()
//#define gc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++)
char buf[1 << 21], *p1 = buf, *p2 = buf;
template <class T> void read(T &x)
{
    x = 0; int c = gc(); int flag = 0;
    while (c < '0' || c > '9') flag |= (c == '-'), c = gc();
    while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) +(c ^ 48), c = gc();
    if (flag) x = -x;
}
template <class T> T _max(T a, T b){return b < a ? a : b;}
template <class T> T _min(T a, T b){return a < b ? a : b;}
template <class T> bool checkmax(T &a, T b){return a < b ? a = b, 1 : 0;}
template <class T> bool checkmin(T &a, T b){return b < a ? a = b, 1 : 0;}
const int N = 100005, inf = 0x3f3f3f3f;
int e = 0, first[N], nxt[N << 1], point[N << 1], value[N << 1];
int n, m;
set<int> S[N];
int dis[N];
void add_edge(int x, int y, int z)
{
	nxt[++e] = first[x];
	first[x] = e;
	point[e] = y;
	value[e] = z;
}

void init()
{
	read(n); read(m);
	memset(first, -1, sizeof first);
	for (int i = 1, u, v, w; i <= m; ++i)
	{
		read(u); read(v); read(w);
		add_edge(u, v, w);
		add_edge(v, u, w);
	}
	for (int i = 1, k; i <= n; ++i)
	{
		read(k);
		for (int j = 1, x; j <= k; ++j)
		{
			read(x);
			S[i].insert(x);
		}
	}
}

void solve()
{
	memset(dis, 0x3f, sizeof dis);
	priority_queue<pii, vector<pii>, greater<pii> > q;
	q.push(m_p(0, 1)); dis[1] = 0;
	while (!q.empty())
	{
		pii now = q.top(); q.pop();
		int x = now.second;
		int D = now.first;
		if (D > dis[x]) continue;
        if(x==n) break;
        //while (S[x].find(D) != S[x].end()) ++D;
		if (S[x].count(D))
		{
			++dis[x];
			q.push(m_p(dis[x],x));
			continue;
		}
		for (int i = first[x]; ~i; i = nxt[i])
		{
			int to = point[i];
			if (checkmin(dis[to], D + value[i]))
			{
				q.push(m_p(dis[to], to));
			}
		}
	}
	if (dis[n] == inf) printf("-1\n");
	else printf("%d\n", dis[n]);
}

int main()
{
	//setIO("");
	init();
	solve();
	return 0;
}