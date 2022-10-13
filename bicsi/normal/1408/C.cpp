#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    int n; double l; cin >> n >> l;
    
    vector<double> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    a.push_back(0.0); a.push_back(l);
    sort(a.begin(), a.end());
    n = a.size();
    
    double timer = 0;
    int pos1 = 0, pos2 = n - 1, v1 = 1, v2 = 1;
    double t1 = 0, t2 = 0;
    double meet;
    while (true) {
      if (pos2 - pos1 == 1) {
        double dist = a[pos2] - a[pos1];
        // v1 * (x - t1) + v2 * (x - t2) = dist
        // (v1 + v2) * x = dist + v1 * t1 + v2 * t2
        meet = 1.0 * (dist + v1 * t1 + v2 * t2) / (v1 + v2);
        break;
      } else {
        double adv1 = 1.0 * (a[pos1 + 1] - a[pos1]) / v1;
        double adv2 = 1.0 * (a[pos2] - a[pos2 - 1]) / v2;
        if (t1 + adv1 < t2 + adv2) {
          // cerr << "at: " << t1 + adv1 << ": " << pos1 + 1 << endl;
          t1 += adv1; pos1 += 1; v1 += 1; 
        } else {
          // cerr << "at: " << t1 + adv1 << ": " << pos2 - 1 << endl;
          t2 += adv2; pos2 -= 1; v2 += 1;
        }
      }
    }
    cout << fixed << setprecision(20) << meet << '\n';
  }

  return 0;
}