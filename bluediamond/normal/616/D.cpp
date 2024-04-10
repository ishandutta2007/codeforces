#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 5e5 + 7;
const int A = (int) 1e6 + 7;
int n, k, a[N], ls = 100, rs, f[A], cnt = 0;

void upd(int l, int r) {
  if (r - l > rs - ls) {
    ls = l;
    rs = r;
  }
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int l = 1;
  for (int i = 1; i <= n; i++) {
    cnt += (f[a[i]] == 0);
    f[a[i]]++;
    while (cnt > k) {
      f[a[l]]--;
      cnt -= (f[a[l]] == 0);
      l++;
    }
    upd(l, i);
  }
  cout << ls << " " << rs << "\n";


  return 0;
}