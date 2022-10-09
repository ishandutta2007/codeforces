#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using cd = complex<ld>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int test;
  cin >> test;
  while (test--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    vector<string> res(4);
    string yes = "Ya", no = "Tidak";
    if ((a + b) % 2 == 0) {
      res[0] = res[1] = no;
      res[2] = (b + c > 0) ? yes : no;
      res[3] = (a + d > 0) ? yes : no;
    } else {
      res[2] = res[3] = no;
      res[0] = (a + d > 0) ? yes : no;
      res[1] = (b + c > 0) ? yes : no;
    }
    for (auto &s : res) {
      cout << s << " ";
    }
    cout << "\n";
  }

  return 0;
}