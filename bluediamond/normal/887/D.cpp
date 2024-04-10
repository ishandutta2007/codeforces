#include <iostream>
#include <vector> 
#include <algorithm> 
#include <string> 
#include <cassert> 
#include <algorithm> 
#include <set> 
#include <iomanip> 
#include <queue> 
#include <deque> 
#include <unordered_set> 
#include <unordered_map> 
#include <functional> 
#include <cmath> 
#include <map> 
#include <random> 
#include <chrono> 
// 394 ---> 395

bool home = true;

using namespace std;
typedef long long ll;

const int M = (int)1e9 + 7;

int add(int a, int b) {
  a += b;
  if (a >= M) return a - M;
  if (a < 0) return a + M;
  return a;
}

int mul(int a, int b) {
  return a * (ll)b % M;
}

int fpw(int a, int b) {
  if (b == 0) {
    return 1;
  }
  int r = 1;
  while (b) {
    if (b & 1) r = mul(r, a);
    a = mul(a, a);
    b /= 2;
  }
  return r;
}

int dv(int a, int b) {
  return mul(a, fpw(b, M - 2));
}

void addup(int& a, int b) {
  a = add(a, b);
}

void mulup(int& a, int b) {
  a = mul(a, b);
}

const int N = (int)3e5 + 7;
const ll INF = (ll)1e18 + 7;
const int INF_INT = (int)1e9 + 7;
int n;
int a, b, c, d, start, len;
int t[N], q[N];
int reach[N];
int reach_right_after[N];
ll cost[N];
ll tmin[4 * N];
ll lazy[4 * N];

void push(int v, int tl, int tr) {
  if (lazy[v]) {
    tmin[v] += lazy[v];
    if (tl < tr) {
      lazy[2 * v] += lazy[v];
      lazy[2 * v + 1] += lazy[v];
    }
    lazy[v] = 0;
  }
}

void add(int v, int tl, int tr, int l, int r, ll x) {
  push(v, tl, tr);
  if (tr < l || r < tl) return;
  if (l <= tl && tr <= r) {
    lazy[v] += x;
    push(v, tl, tr);
    return;
  }
  int tm = (tl + tr) / 2;
  add(2 * v, tl, tm, l, r, x);
  add(2 * v + 1, tm + 1, tr, l, r, x);
  tmin[v] = min(tmin[2 * v], tmin[2 * v + 1]);
}

ll get(int v, int tl, int tr, int l, int r) {
  push(v, tl, tr);
  if (tr < l || r < tl) return INF;
  if (l <= tl && tr <= r) return tmin[v];
  int tm = (tl + tr) / 2;
  return min(get(2 * v, tl, tm, l, r), get(2 * v + 1, tm + 1, tr, l, r));
}

void add(int l, int r, ll x) {
  add(1, 1, n, l, r, x);
}

ll get(int l, int r) {
  return get(1, 1, n, l, r);
}



void set_type(int index, int type) {
  assert(1 <= index && index <= n);
  assert(type == 0 || type == 1);
  ll init = cost[index];
  if (type == 0) {
    if (q[index] == 1) {
      cost[index] = a;
    }
    else {
      cost[index] = b;
    }
  }
  else {
    if (q[index] == 1) {
      cost[index] = c;
    }
    else {
      cost[index] = d;
    }
  }
  ll delta = cost[index] - init;
  add(index, n, delta);
}

bool is_ok(int last) {
  return get(1, last) >= -start;
}

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif


  if (home) {
    FILE* stream;
    freopen_s(&stream, "iron_man.txt", "r", stdin);
  }
  else {
    ios::sync_with_stdio(0); cin.tie(0);
  }

  // 1 = a or c
  // 0 = b or d

  cin >> n >> a >> b >> c >> d >> start >> len;
  b *= -1;
  d *= -1;
  for (int i = 1; i <= n; i++) {
    cin >> t[i] >> q[i];
  }
  {
    int j = 1;
    for (int i = 1; i <= n; i++) {
      while (j + 1 <= n && t[j + 1] < t[i] + len) {
        j++;
      }
      reach[i] = j;
    }
  }
  {
    int j = 0;
    for (int i = 0; i <= n; i++) {
      while (j + 1 <= n && t[j + 1] < t[i] + 1 + len) {
        j++;
      }
      reach_right_after[i] = j;
    }
  }

  for (int i = 1; i <= n; i++) {
    set_type(i, 0);
  }

  int best = INF_INT;

  if (is_ok(n)) {
    best = min(best, t[n] + 1);
  }

  // start from 0
  int pivot = 0;
  while (pivot + 1 <= n && t[pivot + 1] < len) {
    pivot++;
    set_type(pivot, 1);
  }

  if (is_ok(pivot)) {
    best = min(best, 0);
  }

  for (int i = 1; i <= n; i++) {
    // start from t[i - 1] + 1 to t[i]
    int max1 = reach_right_after[i - 1];
    int max2 = reach[i];
    if (i - 1 >= 1) {
      set_type(i - 1, 0);
    }
    assert(pivot <= max1);
    while (pivot < max1) {
      pivot++;
      set_type(pivot, 1);
    }
    assert(pivot <= max2);
    if (is_ok(pivot)) {
      best = min(best, t[i - 1] + 1);
    }
    while (pivot + 1 <= max2) {
      pivot++;
      set_type(pivot, 1);
      if (is_ok(pivot)) {
        best = min(best, t[pivot] - len + 1);
      }
    }
  }

  if (best == INF_INT) {
    best = -1;
  }

  cout << best << "\n";


}