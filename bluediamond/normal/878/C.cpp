#include <bits/stdc++.h>
///#prbgmb GCC target ("sse4.2")

///#pragma GCC opimize("O1")
///#pragma GCC opimize("O2")

///#pragma GCC opimize("Os")
///#pragma GCC opimize("Ofast")
///#pragma GCC target("avx,avx2,fma")
///#pragma GCC target("avx2")



///#pragma GCC opimize("O3")
///#pragma GCC opimization ("unroll-loops")

using namespace std;

bool home = 1;
typedef long long ll;
typedef long double ld;
#define int ll
signed realMain();


signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("tony_stark", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  realMain();
}

int k;

struct S {
  int mn;
  int mx;
};

S operator + (S a, S b) {
  return {min(a.mn, b.mn), max(a.mx, b.mx)};
}

struct T {
  S a[10];
  int cnt;
};

T operator + (T first, T second) {
  first.cnt += second.cnt;
  for (int i = 0; i < k; i++) {
    first.a[i] = first.a[i] + second.a[i];
  }
  return first;
}

bool win(T first, T second) {
  for (int i = 0; i < k; i++) {
    if (first.a[i].mx > second.a[i].mn) {
      return 1;
    }
  }
  return 0;
}

bool lose(T first, T second) {
  for (int i = 0; i < k; i++) {
    if (first.a[i].mn < second.a[i].mx) {
      return 1;
    }
  }
  return 0;
}

T get(vector<int> v) {
  assert((int) v.size() == k);
  T ret;
  for (int i = 0; i < k; i++) {
    ret.a[i] = {v[i], v[i]};
  }
  ret.cnt = 1;
  return ret;
}

bool operator < (T first, T second) {
  return first.a[0].mx < second.a[0].mx;
}

const int N = (int) 5e4 + 7;
int n;
set<T> s;

void baga(vector<int> v) {
  T now = get(v);
  s.insert(now);
  while (1) {
    auto it = s.find(now), nxt = it;
    nxt++;
    if (nxt != s.end()) {
      /// avem win(nxt, it)
      if (lose(*nxt, *it)) {
        now = *it + *nxt;
        s.erase(it);
        s.erase(nxt);
        s.insert(now);
        continue;
      }
    }
    auto ant = it;
    if (it != s.begin()) {
      ant--;
      if (win(*ant, *it)) {
        now = *it + *ant;
        s.erase(it);
        s.erase(ant);
        s.insert(now);
        continue;
      }
    }
    break;
  }
}

signed realMain() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    vector<int> v(k);
    for (auto &x : v) {
      cin >> x;
    }
    baga(v);
    assert(!s.empty());
    auto it = s.end();
    it--;
    cout << it->cnt << "\n";
  }
  return 0;
}