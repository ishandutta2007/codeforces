#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int par[2020];
int dep[2020];
int a[2020];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int n;
  cin >> n;
  cout << "? 1" << endl;
  int odddep = 0, evendep = 0;
  for (int i=1; i<=n; ++i) {
    cin >> dep[i];
    if (i != 1) {
      (dep[i] % 2 == 1 ? odddep : evendep)++;
      if (dep[i] == 1) {
        par[i] = 1;
      }
    }
  }
  if (n == 2) {
    cout << "!\n1 2" << endl;
    return 0;
  }
  assert(!dep[1]);
  for (int i=2; i<=n; ++i) {
    if ((odddep*2 < n && dep[i]%2 == 1)
     || (odddep*2 >= n && dep[i]%2 == 0)) {
      cout << "? " << i << endl;
      for (int j=1; j<=n; ++j) {
        cin >> a[j];
        if (a[j] == 1) {
          assert(abs(dep[i]-dep[j]) == 1);
          if (dep[i] > dep[j]) {
            assert(!par[i] || par[i] == j);
            par[i] = j;
          } else {
            assert(!par[j] || par[j] == i);
            par[j] = i;
          }
        }
      }

    }
  }
  cout << "!" << endl;
  for (int i=2; i<=n; ++i) {
    cout << i << " " << par[i] << endl;
  }
  return 0;
}