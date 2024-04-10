#include <bits/stdc++.h>

using namespace std;

bool prie(int x) {
  if (x <= 1) {
    return 0;
  } else {
    for (int i = 2; i * i <= x; i++) {
      if (x % i == 0) {
        return 0;
      }
    }
    return 1;
  }
}

vector<int> sm[100];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<int> p;
  int x = 1;
  while ((int) p.size() <= 11) {
    if (prie(x)) {
      p.push_back(x);
    }
    x++;
  }

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> sol(n);
    for (int i = 0; i < 11; i++) {
      sm[i].clear();
    }
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      for (int j = 0; j < 11; j++) {
        if (x % p[j] == 0) {
          sm[j].push_back(i);
          break;
        }
      }
    }
    int cnt = 0;
    for (int i = 0; i < 11; i++) {
      if (!sm[i].empty()) {
        cnt++;
        for (auto &j : sm[i]) {
          sol[j] = cnt;
        }
      }
    }
    cout << cnt << "\n";
    for (int i = 0; i < n; i++) {
      cout << sol[i] << " ";
    }
    cout << "\n";
  }

}