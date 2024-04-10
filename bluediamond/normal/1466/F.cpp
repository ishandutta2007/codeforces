#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 5e5 + 7;
const int M = (int) 1e9 + 7;
int n;
int m;
int t[N];
bool e[N];

int root(int a) {
  if (t[a] == a) {
    return a;
  } else {
    return t[a] = root(t[a]);
  }
}

bool unite(int a, int b) {
  a = root(a);
  b = root(b);
  if (a == b || (e[a] & e[b])) {
    return 0;
  } else {
    t[b] = a;
    e[a] |= e[b];
    return 1;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    t[i] = i;
    e[i] = 0;
  }
  int ret = 1;
  vector<int> idx;
  for (int i = 1; i <= n; i++) {
    int k;
    cin >> k;
    if (k == 2) {
      int x, y;
      cin >> x >> y;
      if (unite(x, y)) {
        ret = 2 * ret % M;
        idx.push_back(i);
      }
    } else {
      int x;
      cin >> x;
      x = root(x);
      if (e[x] == 0) {
        ret = 2 * ret % M;
        e[x] = 1;
        idx.push_back(i);
      }
    }
  }
  cout << ret << " " << (int) idx.size() << "\n";
  for (auto &i : idx) {
    cout << i << " ";
  }
  cout << "\n";
}