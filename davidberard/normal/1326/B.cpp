#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 200200;
ll a[N], b[N], x[N];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i=1; i<=n; ++i) {
    cin >> b[i];
  }
  for (int i=1; i<=n; ++i) {
    a[i] = b[i]+x[i];
    x[i+1] = max(x[i], a[i]);
  }
  for (int i=1; i<=n; ++i) {
    cout << a[i] << " ";
  }
  cout << endl;
  
  return 0;
}