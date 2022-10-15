#include <bits/stdc++.h>
using namespace std;
int a, b, k;
string s;
signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> a >> b >> k;
  if (k && (a + b - k - 1 <= 0 || b == 1 || a == 0)) {cout << "No\n"; exit(0);}
  for (int i = 1; i <= a + b; i++) s += (i <= b) ? "1" : "0";
  cout << "Yes\n" << s << "\n";
  if (!k) {cout << s; exit(0);}
  if (k <= a) for (int i = 1; i <= b + a; i++) cout << ((i <= b + k) ? i < b ? "1" : i == b ? "0" : i < b + k ? "0" : "1" : "0");
  else for (int i = 1; i < b + a; i++) cout << (i == b + a - 1 ? "1" : (i < b) ? i == a + b - k - 1 ? "10" : "1" : "0");
}