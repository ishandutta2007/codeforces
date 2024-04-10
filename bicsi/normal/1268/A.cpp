#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int n, k; cin >> n >> k;
  string s; cin >> s;
  
  cout << n << endl;
  string a = s;
  for (int i = k; i < n; ++i) {
    a[i] = a[i - k];
  }
  
  if (a >= s) {
    cout << a << endl;
  } else {
    for (int i = k - 1; i >= 0; --i) {
      if (a[i] == '9') a[i] = '0';
      else { ++a[i]; break; }
    }
    for (int i = k; i < n; ++i) {
      a[i] = a[i - k];
    }
    cout << a << endl;
  }

  return 0;
}