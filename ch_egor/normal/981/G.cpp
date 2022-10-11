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
const int MOD = 998244353; //1000 * 1000 * 1000 + 7;

const int MAX_N = 200 * 1000 + 228;
const int BLOCK = 500;

int n, q;
set<pair<int, int>> have[MAX_N];
ll arr[MAX_N];
ll tree[4 * MAX_N];
ll mul[4 * MAX_N];
ll add[4 * MAX_N];


/*ll add_bl[MAX_N / BLOCK + 228];
ll mul_bl[MAX_N / BLOCK + 228];
ll sum[MAX_N / BLOCK + 228];

void upd(int l, int r, int x)
{
}

ll get(int l, int r)
{
	int lf = l / BLOCK;
	int rf = r / BLOCK;

	ll ans = 0;
	if (lf == rf)
	{
		for (int i = l; i <= r; ++i)
		{
			ans += add_bl[lf] + arr[i] * mul_bl[lf];
			ans %= MOD;
		}
	}
	else
	{
		for (int i = l, target = (lf + 1) * BLOCK; i < target; ++i)
		{
			ans += add_bl[lf] + arr[i] * mul_bl[lf];
			ans %= MOD;
		}

		for (int i = rf * BLOCK; i <= r; ++i)
		{
			ans += add_bl[rf] + arr[i] * mul_bl[rf];
			ans %= MOD;
		}
	}

	return ans;
}*/

void build(int v, int l, int r)
{
	if (r - l == 1)
	{
		tree[v] = 0;
		mul[v] = 1;
		add[v] = 0;
	}
	else
	{
		int m = (l + r) >> 1;

		build(2 * v + 1, l, m);
		build(2 * v + 2, m, r);
	
		tree[v] = 0;
		mul[v] = 1;
		add[v] = 0;
	}
}

void add_v(int v, int l, int r, ll to_add, ll to_mul)
{
	tree[v] = (tree[v] * to_mul + (r - l) * to_add) % MOD;
	mul[v] = (mul[v] * to_mul) % MOD;
	add[v] = (add[v] * to_mul + to_add) % MOD;
}

void push(int v, int l, int r)
{
	int m = (l + r) >> 1;

	add_v(2 * v + 1, l, m, add[v], mul[v]);
	add_v(2 * v + 2, m, r, add[v], mul[v]);
	
	add[v] = 0;
	mul[v] = 1;
}


ll get(int v, int l, int r, int x, int y)
{
	if (y <= l || r <= x) return 0;
	else if (x <= l && r <= y) return tree[v];
	else
	{
		push(v, l, r);
		int m = (l + r) >> 1;
		
		ll ans = get(2 * v + 1, l, m, x, y) + get(2 * v + 2, m, r, x, y);
		if (ans >= MOD) ans -= MOD;
		return ans;
	}
}

void upd(int v, int l, int r, int x, int y, int to_add, int to_mul)
{
	//if (v == 0) cout << x + 1 << " " << y << " " << to_add << " " << to_mul << "\n";
	if (y <= l || r <= x) return;
	else if (x <= l && r <= y) add_v(v, l, r, to_add, to_mul);
	else
	{
		push(v, l, r);
		int m = (l + r) >> 1;

		upd(2 * v + 1, l, m, x, y, to_add, to_mul);
		upd(2 * v + 2, m, r, x, y, to_add, to_mul);

		tree[v] = tree[2 * v + 1] + tree[2 * v + 2];
		if (tree[v] >= MOD) tree[v] -= MOD;
	}
}

void fuck_upd(int l, int r, int x)
{
	auto &cur = have[x];
	
	if (cur.empty())
	{
		cur.insert({l, r});
		upd(0, 0, n, l, r + 1, 1, 1);
		return;
	}

	auto it = cur.lower_bound({l, -INF});

	if (it != cur.begin())
	{
		--it;
		if (it->second < l) ++it;
	}

	int mem_l = l;
	int mem_r = r;
	
	vector<pair<int, int>> inter;
	while (it != cur.end() && it->first <= r)
	{
		inter.push_back(*it);
		it = cur.erase(it);
	}
	
	if (!inter.empty())
	{
		if (inter[0].first < l) mem_l = inter[0].first;
		if (inter.back().second > r) mem_r = inter.back().second;
		
		int ptr = l;

		for (int i = 0; i < (int)inter.size(); ++i)
		{
			if (inter[i].first <= ptr && ptr <= inter[i].second)
			{
				upd(0, 0, n, ptr, min(r, inter[i].second) + 1, 0, 2);
				ptr = min(r, inter[i].second) + 1;
			} 
			else if (ptr < inter[i].first)
			{
				upd(0, 0, n, ptr, inter[i].first, 1, 1);
				upd(0, 0, n, inter[i].first, min(r, inter[i].second) + 1, 0, 2);
				ptr = min(r, inter[i].second) + 1;
			}
		}

		if (ptr <= r)
		{
			upd(0, 0, n, ptr, r + 1, 1, 1);
		}
	}
	else
	{
		upd(0, 0, n, l, r + 1, 1, 1);
	}

	cur.insert({mem_l, mem_r});
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
	q = readInt();

	/*for (int i = 0, j = 0; j < n; ++i, j += BLOCK)
	{
		sum[i] = 0;
		add_bl[i] = 0;
		mul_bl[i] = 1;
	}*/

	build(0, 0, n);

	int t, l, r, x;
	for (int i = 0; i < q; ++i)
	{
		t = readInt();
		l = readInt() - 1;
		r = readInt() - 1;

		if (t == 1)
		{
			x = readInt();
			fuck_upd(l, r, x);
		}
		else
		{
			writeInt(get(0, 0, n, l, r + 1));
			writeChar('\n');
		}
	}

	flush();

	return 0;
}