#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 100;
int a[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    int n;
    cin >> n;
    int o = 0, e = 0;
    for (int i=0; i<n; ++i) {
      cin >> a[i];
      if (i%2) {
        o++;
      } else {
        e++;
      }
      if (a[i]%2) {
        --o;
      } else {
        e--;
      }
    }
    if (o != 0 || e != 0) {
      cout << "-1\n";
      continue;
    }
    int bads = 0;
    for (int i=0; i<n; ++i) {
      bads += (a[i]%2 != i%2);
    }
    cout << bads/2 << "\n";
  }
  return 0;
}