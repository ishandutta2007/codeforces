#include <bits/stdc++.h>


using namespace std;
#define int ll

typedef long long ll;

bool home = 1;
const int N = (int)2e5 + 7;
int n1, n2, x1[N], x2[N], dify, print;

int solve() {
  int sol = 1;
  {
    set<int> sx1;
    for (int i = 1; i <= n1; i++) {
      sx1.insert(x1[i]);
    }
    for (int i = 1; i <= n2; i++) {
      if (sx1.count(x2[i])) {
        sol = max(sol, 2LL);
      }
    }
  }

  for (int d = 1; d <= (int)1e9; d *= 2) {
    map<int, int> cnt1, cnt2;
    for (int i = 1; i <= n1; i++) {
      cnt1[x1[i] % (2 * d)]++;
    }
    for (int i = 1; i <= n2; i++) {
      cnt2[(x2[i] + d) % (2 * d)]++;
    }
    vector<int> is;
    for (auto& it : cnt1) is.push_back(it.first);
    for (auto& it : cnt2) is.push_back(it.first);
    for (auto& i : is) {
      sol = max(sol, cnt1[i] + cnt2[i]);
    }
  }
  return sol;
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);


#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen("iron_man.txt", "r", stdin);
  }
  if (!home) {
    ios::sync_with_stdio(0), cin.tie(0);
  }
  int ______________;
  cin >> n1 >> ______________;
  for (int i = 1; i <= n1; i++) cin >> x1[i];
  cin >> n2 >> ______________;
  for (int i = 1; i <= n2; i++) cin >> x2[i];


  cout << solve() << "\n";
}