#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;

int F[20];


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    int r = 0;
    int p = 1;
    for (int j = 0; j < k; ++j) {
      int tt;
      cin >> tt;
      if (tt == 0) r += p;
      p *= 2;
    }
    F[r] = 1;
  }
  int ob = (1<<k)-1;
  for (int i = 0; i <= ob; ++i) {
    for (int j = 0; j <= ob; ++j) {
      if ((i|j) == ob and F[i] and F[j]) {
        cout << "YES" << endl;
        return 0;
      }
    }
  }
  cout << "NO" << endl;
}