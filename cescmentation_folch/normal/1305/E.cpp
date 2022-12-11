#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;

int f(int n) {
  int res = 0;
  for (int i = 1; i < n-i; ++i) res += (n-2*i);
  return res;
}

int g(int n, int k) {
  int res = 0;
  for (int i = 1; i <= n; ++i) {
    if (k-i > i and k-i <= n) ++res;
  }
  return res;
}

const int N = 100000000;
const int M = 20000;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  if (n == 1) {
    if (m == 0) cout << 1 << endl;
    else cout << -1 << endl;
    return 0;
  }
  int a = 2;
  int b = n+2;
  while (a + 1 < b) {
    int c = (a+b)/2;
    if (f(c) <= m) a = c;
    else b = c;
  }
  if (a > n or (a == n and f(a) < m)) {
    cout << -1 << endl;
    return 0;
  }
  m -= f(a);
  int a0 = a + 1;
  int b0 = 2*n;
  while (a0+ 1 < b0) {
    int c0 = (a0 + b0)/2;
    if (g(a, c0) <= m) b0 = c0;
    else a0 = c0;
  }
  vi R(n);
  for (int i = 0; i < a; ++i) R[i] = i+1;
  if (a < n) R[a] = b0;
  for (int i = a+1; i < n; ++i) R[i] = N + (i-a)*M;
  for (int i = 0; i < n; ++i) {
    if (i) cout << ' ';
    cout << R[i];
  }
  cout << endl;

}