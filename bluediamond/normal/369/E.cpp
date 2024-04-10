#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 1e6 + 7;
int n, q;

struct Segment {
  int l;
  int r;
};

bool operator < (Segment a, Segment b) {
  return a.l < b.l;
}
Segment a[N];

int aib[N];

void add(int i) {
  while (i <= n) {
    aib[i]++;
    i += i & (-i);
  }
}

int get(int i) {
  int r = 0;
  while (i > 0) {
    r += aib[i];
    i -= i & (-i);
  }
  return r;
}

int m;
int p[N];

vector <int> vec[4 * N];

vector <int> uni(vector <int> a, vector <int> b) {
  vector <int> c;
  int na = (int) a.size();
  int nb = (int) b.size();
  int pa = 0;
  int pb = 0;
  while (pa < na || pb < nb) {
    int t = 0;
    if (pa == na) {
      t = 2;
    }
    if (pb == nb) {
      t = 1;
    }
    if (t == 0) {
      if (a[pa] < b[pb]) {
        t = 1;
      } else {
        t = 2;
      }
    }
    if (t == 1) {
      c.push_back(a[pa++]);
    } else {
      c.push_back(b[pb++]);
    }
  }
  return c;
}

void build(int v, int tl, int tr) {
  if (tl < tr) {
    int tm = (tl + tr) / 2;
    build(2 * v, tl, tm);
    build(2 * v + 1, tm + 1, tr);
    vec[v] = uni(vec[2 * v], vec[2 * v + 1]);
  } else {
    vec[v] = {a[tl].r};
  }
}

int cnt(int v, int tl, int tr, int l, int r, int k) { /// cnt <= k
  if (tr < l || r < tl) {
    return 0;
  }
  if (l <= tl && tr <= r) {
    int ans = 0;
    int lo = 0, hi = (int) vec[v].size() - 1;
    while (lo <= hi) {
      int mid = (lo + hi) / 2;
      if (vec[v][mid] >= k) {
        ans = (int) vec[v].size() - mid;
        hi = mid - 1;
      } else {
        lo = mid + 1;
      }
    }
    return ans;
  } else {
    int tm = (tl + tr) / 2;
    int a = cnt(2 * v, tl, tm, l, r, k);
    int b = cnt(2 * v + 1, tm + 1, tr, l, r, k);
    return a + b;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);

  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].l >> a[i].r;
  }
  sort(a + 1, a + n + 1);
  build(1, 1, n);

  while (q--) {
    cin >> m;
    for (int i = 1; i <= m; i++) {
      cin >> p[i];
    }
    sort(p + 1, p + m + 1);
    int sol = 0;
    for (int i = 1; i <= m; i++) {
      int first = (1 << 30);
      int last = -(1 << 30);
      int lo = 1, hi = n;
      while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (p[i - 1] + 1 <= a[mid].l) {
          first = mid;
          hi = mid - 1;
        } else {
          lo = mid  + 1;
        }
        /// 0 0 0 0 0 0 1 1 1 1 1 1
      }
      lo = 1, hi = n;
      while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (a[mid].l <= p[i]) {
          last = mid;
          lo = mid + 1;
        } else {
          hi = mid - 1;
        }
        /// 1 1 1 1 1 0 0 0 0 0
      }
      int now = 0;
      if (first <= last) {
        now = cnt(1, 1, n, first, last, p[i]);
      }
      sol += now;
    }
    cout << sol << "\n";
  }


  /// cate puncte contin primul punct p[i] => p[i - 1] < l <= p[i] <= r
  ///                                      => p[i - 1] + 1 <= l <= p[i] <= r

  return 0;
}