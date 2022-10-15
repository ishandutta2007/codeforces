
#include <bits/stdc++.h>

using namespace std;

void nope() {
  cout << "IMPOSSIBLE\n";
  exit(0);
}

struct T {
  int vertex;
  bool has_l;
  bool has_r;
};

const int N = 1000000 + 7;
int n, restr;
vector<int> lft[N], rgh[N], sol;

int dfs(int a, int at_least) {
  ///cout << "a = " << a << "\n";
  assert(a <= at_least);

  int last_placed = a;
  if (!lft[a].empty()) {
    last_placed = dfs(a + 1, lft[a].back());
  }
  sol.push_back(a);
  if (!rgh[a].empty()) {
    if (rgh[a][0] <= last_placed) {
      nope();
    }
    last_placed = dfs(last_placed + 1, rgh[a].back());
  }
  while (last_placed < at_least) {
    last_placed = dfs(last_placed + 1, at_least);
  }
  return last_placed;
}

int main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  freopen("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE


  cin >> n >> restr;
  for (int i = 1; i <= restr; i++) {
    int a, b;
    string s;
    cin >> a >> b >> s;
    if (b <= a) {
      nope();
    }
    assert(s == "LEFT" || s == "RIGHT");
    if (s == "LEFT") {
      lft[a].push_back(b);
    } else {
      rgh[a].push_back(b);
    }
  }

  for (int i = n; i >= 1; i--) {
    sort(lft[i].begin(), lft[i].end());
    sort(rgh[i].begin(), rgh[i].end());
  }

  dfs(1, n);

  for (auto &x : sol) {
    cout << x << " ";
  }
  cout << "\n";
}