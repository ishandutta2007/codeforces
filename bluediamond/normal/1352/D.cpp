#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
 /// freopen ("input", "r", stdin);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    deque<int> a;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      a.push_back(x);
    }
    int x = 0, y = 0, s = 1, ant = 0;
    while (!a.empty()) {
      if (s & 1) {
        int cur = 0;
        while (!a.empty() && cur <= ant) {
          cur += a.front();
          a.pop_front();
        }
        ant = cur;
        x += cur;
      } else {
        int cur = 0;
        while (!a.empty() && cur <= ant) {
          cur += a.back();
          a.pop_back();
        }
        ant = cur;
        y += cur;
      }
      s++;
    }
    cout << s - 1 << " " << x << " " << y << "\n";
  }
  return 0;
}