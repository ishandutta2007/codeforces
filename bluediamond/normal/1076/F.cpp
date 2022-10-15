#include <bits/stdc++.h>

using namespace std;

#define int long long
const int INF = (int) 1e18;
const int N = (int) 3e5 + 7;

int k, aa[N];

int get(int pa, int pb, int a, int b) {
  int ret = INF;
  if (pa <= k) {
    int mn = (a + pa + k - 1) / k - 1;
    if (b == mn) ret = min(ret, a + pa - k * mn);
    if (b > mn && b <= a * k) ret = min(ret, 1LL);
  }
  if (pb <= k) {
    int mn = (a + k - 1) / k - 1;
    if (b == mn) ret = min(ret, a - k * mn);
    if (b > mn && b <= k - pb + (a - 1) * k) ret = min(ret, 1LL);
  }
  return ret;
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n >> k;
  int pa = 0, pb = 0;
  for (int i = 1; i <= n; i++) {
    cin >> aa[i];
  }
  for (int i = 1; i <= n; i++) {
    int b;
    cin >> b;
    int pa2, pb2;
    pa2 = get(pa, pb, aa[i], b);
    pb2 = get(pb, pa, b, aa[i]);
    pa = pa2;
    pb = pb2;
  }
  cout << ((min(pa, pb) <= k) ? "YES" : "NO") << "\n";
}