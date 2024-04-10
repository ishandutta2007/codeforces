#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;


signed main(){
  ios::sync_with_stdio(0); cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    vector<int> kek(4);
    kek = {a, b, c, d};
    sort(kek.begin(), kek.end());
    int fi = kek[2], sc = kek[3];
    int x = max(a, b), y = max(c, d);
    if (x == fi && y == sc) {
      cout << "YES\n"; continue;
    }
    if (y == fi && x == sc) {
      cout << "YES\n"; continue;
    }
    cout << "NO\n";
  }

  return 0;
}