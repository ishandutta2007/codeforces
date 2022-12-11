#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  string a = "abcdefgh";
  string b = "12345678";
  int ind1 = 0;
  int ind2 = 0;
  int fila = 0;
  int prim = 1;
  ++n;
  for (int i = 0; i < n-2; ++i) {
    cout << a[ind1] << b[ind2] << ' ';
    if (i == n-3) break;
    if (prim) {
      prim = 0;
      ind2 = 7;
      if (i == n-4) ind2 = 6;
      if (ind1 == 7) ind2 = 5;
    }
    else {
      --ind2;
      if (ind2 == fila) --ind2;
      if (ind2 < 0) {
        fila ^= 1;
        ind2 = fila;
        prim = 1;
        ind1++;
      }
    }

  }
  if (ind1 == 7) ind2 = 6;
  else ind1 = 7;
  cout << a[ind1] << b[ind2] << ' ';
  cout << a[7] << b[7] << '\n';
  

}