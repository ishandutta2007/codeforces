#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;

bool xec(int a, int b, int c) {
  if (a < b) swap(a, b);
  if (a > c and c > b) return 1;
  return 0;
}

bool xec2(int a, int b, int c) {
  if (a < b) swap(a, b);
  if (c > a or b > c) return 1;
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int h, m, s, t1, t2;
  cin >> h >>m >> s >>t1 >> t2;
  h *= 10;
  t1 *= 10;
  t2 *= 10;
  m *= 2;
  s *= 2;
  if (s) ++m;
  m %= 120;
  if (m) ++h;
  h %= 120;
  t1 %= 120;
  t2 %= 120;
  if (xec(t1, t2, h)  and xec(t1, t2, m)  and xec(t1, t2, s)) {
    cout << "YES" << endl;
  }
  else if (xec2(t1, t2, h)  and xec2(t1, t2, m)  and xec2(t1, t2, s)) {
    cout << "YES" << endl;
  }
  else cout << "NO" << endl;
}