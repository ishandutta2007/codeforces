#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;
typedef long double ld;

int realMain();

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("input", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  realMain();
}

const int N = (int) 1e6 + 7;
int n;
int a[N];
bool vis[N];

signed realMain() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      vis[i] = 0;
      a[i] = i - a[i];
    }
    vector<int> guys;
    int i = 1;
    while (!vis[i]) {
      guys.push_back(i);
      vis[i] = 1;
      i = a[i];
    }
    vector<int> guys2;
    bool found = 0;
    for (auto &x : guys) {
      found |= (x == i);
      if (found) {
        guys2.push_back(x);
      }
    }
    swap(guys, guys2);
    cout << (int) guys.size() << "\n";
    for (auto &i : guys) {
      cout << i << " ";
    }
    cout << "\n";
  }
}