#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 1e5 + 7;
int n, aib[N], cur = 1;
ll sol;
vector<int> la[N];
set<int> tot;

void add(int i, int x) {
  while (i <= n) {
    aib[i] += x;
    i += i & (-i);
  }
}

int get(int i) {
  int sol = 0;
  while (i) {
    sol += aib[i];
    i -= i & (-i);
  }
  return sol;
}

void delp() {
  assert(tot.count(cur));
  add(cur, -1);
  tot.erase(cur);
  if (tot.empty()) {
    cout << sol << "\n";
    exit(0);
  }
  auto it = tot.lower_bound(cur);
  if (it == tot.end()) {
    it = tot.begin();
  }
  cur = *it;
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    add(i, +1);
    int foo;
    cin >> foo;
    la[foo].push_back(i);
    tot.insert(i);
  }

  for (int x = 1; x < N; x++) {
    vector<int> kek = la[x];
    if (kek.empty()) continue;
    int yo = cur;
    for (auto &it : kek) {
      if (it >= yo) {
        sol += get(it) - get(cur) + 1;
        cur = it;
        delp();
      }
    }
    for (auto &it : kek) {
      if (it < yo) {
        if (cur > it) {
          auto ultim = tot.end();
          ultim--;
          sol += get(*ultim) - get(cur);
          sol++;
          cur = *tot.begin();
        }
        sol += get(it) - get(cur) + 1;
        cur = it;
        delp();
      }
    }
  }
}