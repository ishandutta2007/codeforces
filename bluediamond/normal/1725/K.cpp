#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 12e5 + 7;
int n;
int h[N];
int id[N];
int q;
int y = 0;
int t[N];
set<pair<int, int>> s;

int root(int a) {
  if (t[a] == a) {
    return a;
  } else {
    return t[a] = root(t[a]);
  }
}

void mrg(int l, int r, int what) {
  while (1) {
    auto it = s.lower_bound({l, -1});
    if (it == s.end()) break;
    if (it->first > r) break;
    t[it->second] = what;
    s.erase(it);
  }
}

int main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0); cout.tie();
#endif /// ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  freopen ("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE

  for (int i = 0; i < N; i++) {
    t[i] = i;
  }

  cin >> n;
  for (int i = 1; i <= n; i++) {
    id[i] = ++y;
    cin >> h[id[i]];
    s.insert({h[y], y});
  }
  cin >> q;
  for (int iq = 1; iq <= q; iq++) {
    int type;
    cin >> type;
    assert(1 <= type && type <= 3);
    if (type == 1) {
      int k, w;
      cin >> k >> w;
      assert(1 <= k && k <= n);
      id[k] = ++y;
      h[id[k]] = w;
      s.insert({h[y], y});
      continue;
    }
    if (type == 2) {
      int k;
      cin >> k;
      assert(1 <= k && k <= n);
      cout << h[root(id[k])] << "\n";
      continue;
    }
    if (type == 3) {
      int l, r;
      cin >> l >> r;
      assert(l <= r);
      assert(l % 2 != r % 2);
      int mid = (l + r) / 2;
      h[++y] = l - 1;
      s.insert({h[y], y});
      h[++y] = r + 1;
      s.insert({h[y], y});
      mrg(l, mid, y - 1);
      mrg(mid + 1, r, y);
    }
  }
  return 0;
}