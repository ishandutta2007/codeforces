#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 500000;
int n;
int m;
ll c[N];
vector<pair<vector<int>, ll>> a;

ll gcd(ll a, ll b) {
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    a.clear();
    for (int i = 0; i < n; i++) {
      cin >> c[i];
      a.push_back({{}, 0LL});
    }
    for (int i = 0; i < m; i++) {
      int x, y;
      cin >> x >> y;
      x--;
      y--;
      a[y].first.push_back(x);
    }
    for (int i = 0; i < n; i++) {
      sort(a[i].first.begin(), a[i].first.end());
      if (a[i].first.empty()) {
        a[i].second = 0;
      } else {
        a[i].second = c[i];
      }
    }
    sort(a.begin(), a.end());
    ll g = 0;
    int i = 0;
    while (i < n) {
      ll s = a[i].second;
      int j = i;
      while (j + 1 < n && a[j + 1].first == a[i].first) {
        j++;
        s += a[j].second;
      }
      g = gcd(g, s);
      i = j + 1;
    }
    cout << g << "\n";
  }

}