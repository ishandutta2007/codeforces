#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2000 + 7;
int n, a[N];

signed main(){
  ios::sync_with_stdio(0); cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<int> x, y;
    for (int i = 1; i <= n; i++) {
      int num;
      cin >> num;
      if (num & 1) x.push_back(num);
      else y.push_back(num);
    }
    int sz = 0;
    for (auto &it : y) a[++sz] = it;
    for (auto &it : x) a[++sz] = it;

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        if (__gcd(a[i], 2 * a[j]) > 1) {
          cnt++;
        }
      }
    }
    cout << cnt << "\n";
  }
  return 0;
}