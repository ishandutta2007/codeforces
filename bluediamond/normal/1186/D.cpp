#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;
  vector <double> a(n);
  vector <int> b(n);


  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[i] = (int) a[i] - (a[i] < 0 && a[i] != (int) a[i]);
  }

  long long s = 0;
  for (int i = 0; i < n; i++) {
    s -= b[i];
  }

  for (int i = 0; i < n; i++) {
    if (s && a[i] != (int) a[i]) {
      s--;
      b[i]++;
    }
    cout << b[i] << "\n";
  }

  return 0;
}