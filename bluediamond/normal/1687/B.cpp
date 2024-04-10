#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 500 + 7;
int n;
int m;
int v[N];
int act[N];

signed main() {
#ifndef ONLINE_JUDGE
  freopen ("input.txt", "r", stdin);
#endif

#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0);
#endif // ONLINE_JUDGE

  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cout << "? ";
    for (int j = 1; j <= m; j++) {
      cout << (i == j);
    }
    cout << endl;
    cin >> v[i];
  }
  vector<pair<int, int>> edges;
  for (int i = 1; i <= m; i++) {
    edges.push_back({v[i], i});
  }
  sort(edges.begin(), edges.end());
  int sum = 0;
  for (auto &it : edges) {
    int i = it.second;
    act[i] = 1;
    cout << "? ";
    for (int j = 1; j <= m; j++) {
      cout << act[j];
    }
    cout << endl;
    int nw;
    cin >> nw;
    if (nw != sum + v[i]) {
      act[i] = 0;
    } else {
      sum += v[i];
    }
  }
  cout << "! " << sum << endl;


}