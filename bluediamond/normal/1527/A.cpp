#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main()
{
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n;
    k = log2(n);
    cout << (1 << k) - 1 << "\n";
  }
  return 0;
}