#include <bits/stdc++.h>

using namespace std;
#define int long long


int getSum(int i, int j) {
  int o, a;
  cout << "or " << i << " " << j << endl;
  cin >> o;

  cout << "and " << i << " " << j << endl;
  cin >> a;

  return a + o;
}

const int N = (int) 1e4 + 7;
int v[N];

signed main() {
  int n, k;
  cin >> n >> k;

  int s12 = getSum(1, 2);
  int s13 = getSum(1, 3);
  int s23 = getSum(2, 3);

  assert((s12 + s13 + s23) % 2 == 0);
  int s123 = (s12 + s13 + s23) / 2;

  v[1] = s123 - s23;
  v[2] = s123 - s13;
  v[3] = s123 - s12;

  for (int i = 4; i <= n; i++) {
    v[i] = getSum(1, i) - v[1];
  }

  sort(v + 1, v + n + 1);
  cout << "finish " << v[k] << endl;


  return 0;
}