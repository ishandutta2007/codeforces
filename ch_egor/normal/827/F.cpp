#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <assert.h>
#include <algorithm>
#include <iomanip>
#include <time.h>
#include <math.h>
#include <bitset>

#pragma comment(linker, "/STACK:256000000")

using namespace std;

typedef long long int ll;
typedef long double ld;

/** Interface */

inline int readChar();
template <class T = int> inline T readInt();
template <class T> inline void writeInt(T x);
inline void writeChar(int x);
inline void writeWord(const char *s);
inline void flush();

/** Read */

static const int buf_size = 4096;

inline int getChar()
{
	static char buf[buf_size];
	static int len = 0, pos = 0;
	if (pos == len)
		pos = 0, len = fread(buf, 1, buf_size, stdin);
	if (pos == len)
		return -1;
	return buf[pos++];
}

inline int readChar()
{
	int c = getChar();
	while (c <= 32)
		c = getChar();
	return c;
}

template <class T>
inline T readInt()
{
	int s = 1, c = readChar();
	T x = 0;
	if (c == '-')
		s = -1, c = getChar();
	while ('0' <= c && c <= '9')
		x = x * 10 + c - '0', c = getChar();
	return s == 1 ? x : -x;
}

/** Write */

static int write_pos = 0;
static char write_buf[buf_size];

inline void writeChar(int x)
{
	if (write_pos == buf_size)
		fwrite(write_buf, 1, buf_size, stdout), write_pos = 0;
	write_buf[write_pos++] = x;
}

inline void flush()
{
	if (write_pos)
		fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
}

template <class T>
inline void writeInt(T x)
{
	if (x < 0)
		writeChar('-'), x = -x;

	char s[24];
	int n = 0;
	while (x || !n)
		s[n++] = '0' + x % 10, x /= 10;
	while (n--)
		writeChar(s[n]);
}

inline void writeWord(const char *s)
{
	while (*s)
		writeChar(*s++);
}


const int INF = 1000 * 1000 * 1000 + 21;
const ll LLINF = (1ll << 60) + 5;
const int MOD = 1000 * 1000 * 1000 + 7;

const int MAX_N = 500 * 1000 + 228;

struct edge
{
	int v;
	int u;
	ll l;
	ll r;
	int num;
	int v_type;
};


int n, m;
vector<edge> graph[MAX_N][2];
int ptr[MAX_N][2];
edge edges[2 * MAX_N];
ll dist[2 * MAX_N];
set<pair<ll, int>> look_now;

bool cmp(const edge &a, const edge &b)
{
	return a.l < b.l || (a.l == b.l && a.r < b.r);
}


int main()
{
#ifdef CH_EGOR
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
#endif
	
	n = readInt();
	m = readInt();

	for (int i = 0; i < m; ++i)
	{
		edges[i].v = readInt() - 1;
		edges[i].u = readInt() - 1;
		edges[i].l = readInt();
		edges[i].r = readInt();
		edges[i].num = i;
		edges[i].v_type = 0;

		edges[i + m] = edges[i];
		edges[i + m].num = i + m;
		edges[i + m].v_type = 1;

		graph[edges[i].v][0].push_back(edges[i]);
		graph[edges[i].u][1].push_back(edges[i]);
		
		graph[edges[i + m].v][1].push_back(edges[i + m]);
		graph[edges[i + m].u][0].push_back(edges[i + m]);
	}
	
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			sort(graph[i][j].begin(), graph[i][j].end(), cmp);
		}
	}

	
	for (int i = 0; i < 2 * m; ++i)
	{
		dist[i] = LLINF;
	}

	memset(ptr, 0, sizeof(ptr));
	
	while (ptr[0][0] < (int)graph[0][0].size() && graph[0][0][ptr[0][0]].l == 0)
	{
		dist[graph[0][0][ptr[0][0]].num] = 0;	
		look_now.insert({0ll, graph[0][0][ptr[0][0]].num});
		++ptr[0][0];
	}
	
	//cout << look_now.size() << endl;	

	while (!look_now.empty())
	{
		int now = look_now.begin()->second;
		look_now.erase(look_now.begin());
	
		ll cur_r = edges[now].r;
		int v = edges[now].v;
		int type = edges[now].v_type;

		if ((cur_r&1) != type) --cur_r;
		while (ptr[v][type] < (int)graph[v][type].size() &&
			   graph[v][type][ptr[v][type]].l <= cur_r)
		{
			ll min_can = LLINF;
			if (graph[v][type][ptr[v][type]].l > dist[now] + 1)
			{
				if ((graph[v][type][ptr[v][type]].l&1) != type)
				{
					min_can = graph[v][type][ptr[v][type]].l + 1;
				}
				else
				{
					min_can = graph[v][type][ptr[v][type]].l;
				}
			}
			else
			{
				if ((dist[now]&1) != type)
					min_can = dist[now] + 1;
				else
					min_can = dist[now] + 2;
			}
	//		cout << "KEK" << endl;
	//		cout << min_can << endl;
	//		cout << graph[v][type][ptr[v][type]].r << endl;
			if (min_can < graph[v][type][ptr[v][type]].r && min_can < dist[graph[v][type][ptr[v][type]].num])
			{
				look_now.erase({dist[graph[v][type][ptr[v][type]].num], graph[v][type][ptr[v][type]].num});
				dist[graph[v][type][ptr[v][type]].num] = min_can;	
				look_now.insert({dist[graph[v][type][ptr[v][type]].num], graph[v][type][ptr[v][type]].num});
			}

			++ptr[v][type];
		}

		cur_r = edges[now].r;
		v = edges[now].u;
		type ^= 1;
		
		if ((cur_r&1) != type) --cur_r;
		while (ptr[v][type] < (int)graph[v][type].size() &&
			   graph[v][type][ptr[v][type]].l <= cur_r)
		{
			ll min_can = LLINF;
			if (graph[v][type][ptr[v][type]].l > dist[now] + 1)
			{
				if ((graph[v][type][ptr[v][type]].l&1) != type)
				{
					min_can = graph[v][type][ptr[v][type]].l + 1;
				}
				else
				{
					min_can = graph[v][type][ptr[v][type]].l;
				}
			}
			else
			{
				if ((dist[now]&1) != type)
					min_can = dist[now] + 1;
				else
					min_can = dist[now] + 2;
			}
			
			if (min_can < graph[v][type][ptr[v][type]].r && min_can < dist[graph[v][type][ptr[v][type]].num])
			{
				look_now.erase({dist[graph[v][type][ptr[v][type]].num], graph[v][type][ptr[v][type]].num});
				dist[graph[v][type][ptr[v][type]].num] = min_can;	
				look_now.insert({dist[graph[v][type][ptr[v][type]].num], graph[v][type][ptr[v][type]].num});
			}

			++ptr[v][type];
		}
	}

	ll ans = LLINF;
	for (int i = 0; i < 2 * m; ++i)
	{
		if (edges[i].v == n - 1)
		{
			if ((dist[i]&1) == edges[i].v_type)
				ans = min(ans, dist[i]);
			else
				ans = min(ans, dist[i] + 1);
		}
		if (edges[i].u == n - 1)
		{
			if ((dist[i]&1) == edges[i].v_type)
				ans = min(ans, dist[i] + 1);
			else
				ans = min(ans, dist[i]);
		}
	}
	
	if (n == 1)
	{
		ans = 0;
	}
	
	if (ans >= LLINF)
	{
		writeInt(-1);
	}
	else
	{
		writeInt(ans);
	}

	flush();

	return 0;
}