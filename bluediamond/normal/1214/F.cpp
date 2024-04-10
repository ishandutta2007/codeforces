#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

const int N = 200000 + 7;
const int INF = (int) 1e18;
int l, n, a[N], b[N], ret = INF, rla[N], rlb[N], opt_shift, pr[N], cost[N];

int type(int i, int j) {
  if (i >= j) {
    if (abs(i - j) <= l - abs(i - j)) return 1;
    else return 2;
  } else {
    if (abs(i - j) <= l - abs(i - j)) return 3;
    else return 4;
  }
}

int fl(int tp) {
  if (tp == 1) return 0;
  if (tp == 2) return l;
  if (tp == 3) return 0;
  if (tp == 4) return l;

}

int f1(int i, int tp) {
  if (tp == 1) return i;
  if (tp == 2) return -i;
  if (tp == 3) return -i;
  if (tp == 4) return i;
}

int f2(int j, int tp) {
  if (tp == 1) return -j;
  if (tp == 2) return j;
  if (tp == 3) return j;
  if (tp == 4) return -j;
}

void add(int l, int r, int x) {
  assert(l >= 0 && r >= 0);
  if (l <= r) {
    cost[l] += x;
    cost[r + 1] -= x;
  } else {
    cost[l] += x;
    cost[0] += x;
    cost[r + 1] -= x;
  }
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> l >> n;
  vector<pair<int, int>> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].first;
    v[i].second = i + 1;
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < n; i++) {
    a[i] = v[i].first;
    rla[i] = v[i].second;
  }
  for (int i = 0; i < n; i++) {
    cin >> v[i].first;
    v[i].second = i + 1;
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < n; i++) {
    b[i] = v[i].first;
    rlb[i] = v[i].second;
  }
  int start = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] >= b[n - 1]) {
      start = 0;
    } else {
      while (b[start] <= a[i]) {
        start++;
      }
    }
    int l = 0;
    while (l < n) {
      int r = l, lo = l + 1, hi = n - 1, want = type(a[i], b[(start + l) % n]);
      while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (type(a[i], b[(start + mid) % n]) == want) {
          r = mid;
          lo = mid + 1;
        } else {
          hi = mid - 1;
        }
      }
      int adding = fl(want) + f1(a[i], want);
      int first = (n + (start + l) - i) % n, last = (n + (start + r) - i) % n;
      add(first, last, adding);
      l = r + 1;
    }
  }
  start = 0;
  for (int i = 0; i < n; i++) {
    if (b[i] >= a[n - 1]) {
      start = 0;
    } else {
      while (a[start] <= b[i]) {
        start++;
      }
    }
    int l = 0;
    while (l < n) {
      int r = l, lo = l + 1, hi = n - 1, want = type(a[(start + l) % n], b[i]);
      while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (type(a[(start + mid) % n], b[i]) == want) {
          r = mid;
          lo = mid + 1;
        } else {
          hi = mid - 1;
        }
      }
      int adding = f2(b[i], want);
      int first = (n - (start + l) % n + i) % n, last = (n - (start + r) % n + i) % n;
      swap(first, last);
      add(first, last, adding);
      l = r + 1;
    }
  }
  for (int i = 1; i <= n; i++) {
    cost[i] += cost[i - 1];
  }
  for (int shift = 0; shift < n; shift++) {
    if (cost[shift] < ret) {
      ret = cost[shift];
      opt_shift = shift;
    }
  }
  for (int i = 0; i < n; i++) {
    int x = rla[i], y = rlb[(i + opt_shift) % n];
    pr[x] = y;
  }
  cout << ret << "\n";
  for (int i = 1; i <= n; i++) {
    cout << pr[i] << " ";
  }
  cout << "\n";
}