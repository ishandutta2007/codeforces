#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) 
    cin >> a[i];

  if (n == 1) {
    cout << 1 << " " << 1 << endl << 0 << endl;
    cout << 1 << " " << 1 << endl << 0 << endl;
    cout << 1 << " " << 1 << endl << -a[0] << endl;
    return 0;
  }

  cout << 1 << " " << n << endl;
  for (int i = 0; i < n; ++i) {
    // a[i] = n * t + (n - 1) * u
    // 1 = n * t + (n - 1) * u
    cout << -1LL * n * a[i] << " ";
  }
  cout << endl;
  cout << 1 << " " << n - 1 << endl;
  for (int i = 0; i < n - 1; ++i)
    cout << 1LL * (n - 1) * a[i] << " ";
  cout << endl;
  cout << n << " " << n << endl;
  cout << 1LL * (n - 1) * a[n - 1] << endl;
  cout << endl;

  return 0;
}