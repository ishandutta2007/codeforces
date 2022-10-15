#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int ll

const int N = (int) 1e5 + 7;
int n, a[N], sol;
vector<int> pz[N];

signed main()
{
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    map<int, int> mp;
    cin >> n;
    sol = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      mp[a[i]] = 0;
      pz[i].clear();
    }
    int ind = 0;
    for (auto &it : mp) {
      it.second = ++ind;
    }
    for (int i = 1; i <= n; i++) {
      a[i] = mp[a[i]];
      pz[a[i]].push_back(i);
    }
    for (int x = 1; x <= n; x++) {
      int k = (int) pz[x].size(), sum = 0;
      for (int j = 0; j < k; j++) {
        sol += (n + 1 - pz[x][j]) * sum;
        sum += pz[x][j];
      }
    }
    cout << sol << "\n";
  }
  return 0;
}