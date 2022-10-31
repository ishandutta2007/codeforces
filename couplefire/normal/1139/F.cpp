#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#define fi first
#define se second
#define N 110000
#define M 3600000
using namespace std;
const int INF = 0x3f3f3f3f;

int n, m, tot, ans[N];
map<int, int> t;

struct dish {
	int p, s, b;
}d[N], u[N], v[N];

struct people {
	int inc, pref, id;
	bool operator < (const people &rhs) const {
		return inc < rhs.inc;
	}
}a[N];

int cmp1(const dish &a, const dish &b) {
	return a.p < b.p;
}

int cmp2(const dish &a, const dish &b) {
	return a.s < b.s;
}

struct BIT {
	int n, tot, c[N];
  map<int, int> t;

  void init() {
  	for (auto &e: t) e.se = ++ tot;
  }

  void insert(int x) {
  	t[x] = 0;
  }

  int lowbit(int x) {
	  return x & -x;
  }

  int sum(int x) {
	  int ret = 0;
	  while (x) {
		  ret += c[x];
		  x -= lowbit(x);
	  }
	  return ret;
  }

  void add(int x, int k) {
  	x = t[x];
	  while (x <= tot) {
		  c[x] += k;
		  x += lowbit(x);
	  }
  }

  int se(int x) {
	  auto it = t.upper_bound(x);
	  if (it == t.begin()) return 0;
	  it --;
	  return sum(it -> se);
  } 
}B1, B2;

int main() {
//	freopen("1.in", "r", stdin);
//	freopen("1.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++) scanf("%d", &d[i].p);
	for (int i = 1; i <= n; i ++) scanf("%d", &d[i].s);
	for (int i = 1; i <= n; i ++) scanf("%d", &d[i].b);
	for (int i = 1; i <= m; i ++) {
		scanf("%d", &a[i].inc);
		a[i].id = i;
	}
	for (int i = 1; i <= m; i ++) scanf("%d", &a[i].pref);
  sort(a + 1, a + m + 1);
  for (int i = 1; i <= n; i ++) {
  	u[i] = v[i] = d[i];
  	B1.insert(d[i].b - d[i].p);
  	B2.insert(d[i].b + d[i].p);
  }
  B1.init(); B2.init();
  sort(u + 1, u + n + 1, cmp1);
  sort(v + 1, v + n + 1, cmp2);
  int t1 = 1, t2 = 1;
  for (int i = 1; i <= m; i ++) {
  	//cout << "i = " << i << ' ' << a[i].inc << ' ' << a[i].pref << endl;
  	while (t1 <= n && u[t1].p <= a[i].inc) {
  		//cout << u[t1].p << ' ' << u[t1].s << ' ' << u[t1].b << " 1" << endl;
  		B1.add(u[t1].b - u[t1].p, 1);
  		B2.add(u[t1].b + u[t1].p, 1);
  		t1 ++;
  	}
  	while (t2 <= n && v[t2].s < a[i].inc) {
  		//cout << v[t2].p << ' ' << v[t2].s << ' ' << v[t2].b << " -1" << endl;
  		B1.add(v[t2].b - v[t2].p, -1);
  		B2.add(v[t2].b + v[t2].p, -1);
  		t2 ++;
  		//cout << "t2 = " << t2 << endl;
  	}
  	ans[a[i].id] = B2.se(a[i].pref + a[i].inc);
  	ans[a[i].id] -= B1.se(a[i].pref - a[i].inc - 1);
  	//cout << a[i].id << ' ' << ans[a[i].id] << endl;
  }
  for (int i = 1; i <= m; i ++) printf("%d ", ans[i]);
  return 0;
}