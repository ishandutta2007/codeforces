#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
#define MP make_pair
#define PB push_back
#define X first
#define Y second

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))
#define debug(a) cerr << #a << " = " << a << endl;

const double PI = acos(-1.0);
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1 << 21;
int n;
string s;

namespace SegTreeMax
{
	int t[N << 2];
	int d[N << 2];
	int h;
	
	void init()
	{
		h = sizeof(int) * 8 - __builtin_clz(n);
		//FOR(i, 0, N << 1) t[i] = -INF;
	}
	
	void apply(int p, int value) {
	  t[p] += value;
	  if (p < n) d[p] += value;
	}

	void build(int p) {
	  while (p > 1) p >>= 1, t[p] = max(t[p<<1], t[p<<1|1]) + d[p];
	}

	void push(int p) {
	  for (int s = h; s > 0; --s) {
		int i = p >> s;
		if (d[i] != 0) {
		  apply(i<<1, d[i]);
		  apply(i<<1|1, d[i]);
		  d[i] = 0;
		}
	  }
	}

	void add(int l, int r, int value) {
	  l += n, r += n;
	  int l0 = l, r0 = r;
	  for (; l < r; l >>= 1, r >>= 1) {
		if (l&1) apply(l++, value);
		if (r&1) apply(--r, value);
	  }
	  build(l0);
	  build(r0 - 1);
	}

	int query(int l, int r) {
	  l += n, r += n;
	  push(l);
	  push(r - 1);
	  int res = -2e9;
	  for (; l < r; l >>= 1, r >>= 1) {
		if (l&1) res = max(res, t[l++]);
		if (r&1) res = max(t[--r], res);
	  }
	  return res;
	}
};

namespace SegTreeMin
{
	int t[N << 2];
	int d[N << 2];
	int h;
	
	void init()
	{
		h = sizeof(int) * 8 - __builtin_clz(n);
		//FOR(i, 0, N << 2) t[i] = INF;
	}
	
	void apply(int p, int value) {
	  t[p] += value;
	  if (p < n) d[p] += value;
	}

	void build(int p) {
	  while (p > 1) p >>= 1, t[p] = min(t[p<<1], t[p<<1|1]) + d[p];
	}

	void push(int p) {
	  for (int s = h; s > 0; --s) {
		int i = p >> s;
		if (d[i] != 0) {
		  apply(i<<1, d[i]);
		  apply(i<<1|1, d[i]);
		  d[i] = 0;
		}
	  }
	}

	void add(int l, int r, int value) {
	  l += n, r += n;
	  int l0 = l, r0 = r;
	  for (; l < r; l >>= 1, r >>= 1) {
		if (l&1) apply(l++, value);
		if (r&1) apply(--r, value);
	  }
	  build(l0);
	  build(r0 - 1);
	}

	int query(int l, int r) {
	  l += n, r += n;
	  push(l);
	  push(r - 1);
	  int res = 2e9;
	  for (; l < r; l >>= 1, r >>= 1) {
		if (l&1) res = min(res, t[l++]);
		if (r&1) res = min(t[--r], res);
	  }
	  return res;
	}
};

int a[N];
int sum;

void answer()
{
	int mn = SegTreeMin::query(0, n - 1);
	if (mn < 0 || sum != 0) 
	{
		cout << -1 << ' ';
		return;
	}
	
	int mx = SegTreeMax::query(0, n - 1); 
	if (mx < 0) mx = -1;
	cout << mx << ' ';
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cin >> n >> s;
	//n = 1 << 20;
	n += 10;
	SegTreeMax::init();
	SegTreeMin::init();

	int curr = 0;
	sum = 0;
	
	for(auto i: s)
	{
		if (i == 'L')
		{
			curr--;
			if (curr < 0) curr = 0;
		}
		
		if (i == 'R')
			curr++;
		
		if (i == '(')
		{
			int val = 1 - a[curr];
			SegTreeMax::add(curr, n - 1, val);
			SegTreeMin::add(curr, n - 1, val);
			sum -= a[curr];
			a[curr] = 1;
			sum += a[curr];
		}
		
		if (i == ')')
		{
			int val = -1 - a[curr];
			SegTreeMax::add(curr, n - 1, val);
			SegTreeMin::add(curr, n - 1, val);
			sum -= a[curr];
			a[curr] = -1;
			sum += a[curr];
		}			
		
		if (i >= 'a' && i <= 'z')
		{
			int val = -a[curr];
			SegTreeMax::add(curr, n - 1, val);
			SegTreeMin::add(curr, n - 1, val);
			sum -= a[curr];
			a[curr] = 0;
			sum += a[curr];
		}
		
		answer();
	}
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}