#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 100100;
int a[N], p[N];
int n, m;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  for (int i=1; i<=m; ++i) {
    cin >> a[i];
  }
  int lst = n+1;
  for (int i=m; i>=1; --i) {
    p[i] = min(lst-1, n+1-a[i]);
    lst = p[i];
  }
  if (p[1] < 1) {
    cout << -1 << "\n";
    return 0;
  }
  int req = 1;
  for (int i=1; i<=m; ++i) {
    p[i] = min(req, p[i]);
    req = p[i] + a[i];
  }
  if (req <= n) {
    cout << -1 << "\n";
    return 0;
  }
  for (int i=1; i<=m; ++i) {
    cout << p[i] << " ";
  }
  cout << "\n";
  return 0;
}