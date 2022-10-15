#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

pair<int, int> operator + (pair<int, int> a, pair<int, int> b) {
  a.first += b.first;
  a.second += b.second;
  return a;
}



int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  if (n & 1) {
    cout << "NO\n";
    return 0;
  }
  vector<pair<int, int>> a(n / 2);
  for (int i = 0; i < n / 2; i++) {
    cin >> a[i].first >> a[i].second;
  }
  pair<int, int> last;
  for (int i = 0; i < n / 2; i++) {
    pair<int, int> b;
    cin >> b.first >> b.second;
    b = b + a[i];
    if (i && b != last) {
      cout << "NO\n";
      return 0;
    }
    last = b;
  }
  cout << "YES\n";


}