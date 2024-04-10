#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = (int) 2e5 + 7;
int n, l[N], r[N], opt[N], who[N];
vector<int> in[N];
map<pair<int, int>, int> obioan;
int ijing;
int jiing;

struct T {
  int i;
};

bool operator < (T a, T b) {
  if (r[a.i] == r[b.i]) {
    return a.i < b.i;
  } else {
    return r[a.i] < r[b.i];
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> l[i] >> r[i];
    if (obioan.count({l[i], r[i]})) {
      ijing = obioan[{l[i], r[i]}];
      jiing = i;
    }
    obioan[{l[i], r[i]}] = i;
    in[l[i]].push_back(i);
  }
  set<T> all;
  for (int p = 1; p <= n; p++) {
    for (auto &i : in[p]) {
      all.insert({i});
    }
    auto it = *all.begin();
    opt[it.i] = p;
    who[p] = it.i;
    all.erase(it);
  }
  if (ijing) {
    cout << "NO\n";
    for (int i = 1; i <= n; i++) {
      cout << opt[i] << " ";
    }
    cout << "\n";
    for (int i = 1; i <= n; i++) {
      if (who[i] == ijing) {
        ijing = i;
        break;
      }
    }
    for (int i = 1; i <= n; i++) {
      if (who[i] == jiing) {
        jiing = i;
        break;
      }
    }
    swap(who[ijing], who[jiing]);
    for (int i = 1; i <= n; i++) {
      opt[who[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
      cout << opt[i] << " ";
    }
    cout << "\n";
    return 0;
  }
  for (int i = 1; i < n; i++) {
    int a = who[i];
    int b = who[i + 1];
    if (l[a] <= i + 1 && i + 1 <= r[a] && l[b] <= i && i <= r[b]) {
      cout << "NO\n";
      for (int i = 1; i <= n; i++) {
        cout << opt[i] << " ";
      }
      cout << "\n";
      swap(who[i], who[i + 1]);
      for (int i = 1; i <= n; i++) {
        opt[who[i]] = i;
      }
      for (int i = 1; i <= n; i++) {
        cout << opt[i] << " ";
      }
      cout << "\n";
      return 0;
    }
  }
  cout << "YES\n";
  for (int i = 1; i <= n; i++) {
    cout << opt[i] << " ";
  }
  cout << "\n";
  return 0;
}