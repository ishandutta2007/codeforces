#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
map<int, int> id;
int nid;

int get(int x) {
  int y = x;
  while (x) {
    int c = x % 10;
    if (c == 4 || c == 7) {
      x /= 10;
    } else {
      return 0;
    }
  }
  x = y;
  if (id.count(x) == 0) {
    id[x] = ++nid;
  }
  return id[x];
}

const int N = (int) 1e5 + 7;
const int A = 1000 + 7;
int n;
int a[N];
vector<int> where;
vector<int> w_ex[N];
int first[N];
int l[N];
int r[N];
int ub[N];
bool valid[N];

int f(int i) {
  if (i == -1) {
    return 0;
  }
  if (i == (int) where.size()) {
    return n + 1;
  }
  return where[i];
}

ll gauss(ll n) {
  return n * (n + 1) / 2;
}

ll s(ll n) {
  return (n * n * n + 3 * n * n + 2 * n) / 6;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    x = get(x);
    if (x) {
      where.push_back(i);
      w_ex[x].push_back(i);
    }
    a[i] = x;
  }
  ll sol = 0;
  for (int it = 0; it < (int) where.size(); it++) {
    for (int j = 1; j <= where[it] - 1; j++) {
      valid[j] = 1;
    }
    for (int i = 1; i < A; i++) {
      first[i] = 0;
    }
    for (int it2 = it; it2 < (int) where.size(); it2++) {
      int i = where[it2];
      if (first[a[i]] == 0) {
        first[a[i]] = i;
        for (auto &j : w_ex[a[i]]) {
          if (j >= where[it]) {
            break;
          }
          valid[j] = 0;
        }
      }
    }
    for (int j = 1; j <= where[it] - 1; j++) {
      if (valid[j]) {
        if (valid[j - 1]) {
          l[j] = l[j - 1];
        } else {
          l[j] = j;
        }
      }
    }
    for (int j = where[it] - 1; j >= 1; j--) {
      if (valid[j]) {
        if (valid[j + 1]) {
          r[j] = r[j + 1];
        } else {
          r[j] = j;
        }
      }
    }
    ll cur = 0;
    for (int j = 1; j <= where[it] - 1; j++) {
      if (valid[j] && l[j] == j) {
        cur += gauss(r[j] - l[j] + 1);
      }
    }
    for (int it2 = (int) where.size() - 1; it2 >= it; it2--) {
      int i = where[it2];
      ll steps = f(it) - f(it - 1);
      sol += (steps * cur - (f(it) - 1 - l[f(it) - 1] + 1) * gauss(steps - 1) + s(steps - 2)) * (f(it2 + 1) - f(it2));
      if (first[a[i]] == i) {
        for (auto &j : w_ex[a[i]]) {
          if (j >= where[it]) {
            break;
          }
          valid[j] = 1;
          l[j] = r[j] = j;
          if (valid[j - 1]) {
            cur -= gauss(r[j - 1] - l[j - 1] + 1);
            l[j] = l[j - 1];
          }
          if (valid[j + 1]) {
            cur -= gauss(r[j + 1] - l[j + 1] + 1);
            r[j] = r[j + 1];
          }
          r[l[j]] = r[j];
          l[r[j]] = l[j];
          cur += gauss(r[j] - l[j] + 1);
        }
      }
    }
  }
  ub[n + 1] = n + 1;
  for (int i = n; i >= 1; i--) {
    if (a[i]) {
      ub[i] = i;
    } else {
      ub[i] = ub[i + 1];
    }
  }
  for (int i = 1; i <= n; i++) {
    sol += (ll) (ub[i] - i) * gauss(i - 1);
  }
  cout << sol << "\n";
}