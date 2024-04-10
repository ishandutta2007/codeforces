#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;

vpi fes3(int a, int b) {
  vpi V(3, pi(0,0));
  if (a < 75) return vpi(1,pi(-1,-1));
  V[0].first = V[1].first = V[2].first = 25;
  a -= 75;
  int c = b - a;
  if (c < 0 or (c < 23 and a > 0)) return vpi(1,pi(-1,-1));
  V[0].second = min(c, 23);
  c -= V[0].second;
  V[1].second = min(c, 23);
  c -= V[1].second;
  V[2].second = min(c, 23);
  c -= V[2].second;
  if (c > 0) return vpi(1,pi(-1,-1));
  V[0].first += a;
  V[0].second += a;
  return V;
}

vpi fes13(int a, int b) {
  vpi V(4, pi(0,0));
  if (a < 75 or b < 25) return vpi(1,pi(-1,-1));
  V[1].first = V[2].first = V[3].first = V[0].second = 25;
  a -= 75;
  b -= 25;
  for (int c = 0; c <= min(a,b); ++c) {
    int a1 = a - c;
    int b1 = b - c;
    auto f = V;
    f[0].first = min(a1, 23);
    a1 -= f[0].first;
    f[1].second = min(b1, 23);
    b1 -= f[1].second;
    f[2].second = min(b1, 23);
    b1 -= f[2].second;
    f[3].second = min(b1, 23);
    b1 -= f[3].second;
    if (a1 or b1) continue;
    if (c == 0) return f;
    if (f[0].first + 2 == f[0].second) {
      f[0].first += c;
      f[0].second += c;
      return f;
    }
    if (f[1].first - 2 == f[1].second) {
      f[1].first += c;
      f[1].second += c;
      return f;
    }
  }
  return vpi(1,pi(-1,-1));
}

vpi fes23(int a, int b) {
  vpi V(5, pi(0,0));
  if (a < 65 or b < 50) return vpi(1,pi(-1,-1));
  V[1].second = V[2].first = V[3].first = V[0].second = 25;
  V[4].first = 15;
  a -= 65;
  b -= 50;
  for (int c = 0; c <= min(a,b); ++c) {
    int a1 = a - c;
    int b1 = b - c;
    auto f = V;
    f[0].first = min(a1, 23);
    a1 -= f[0].first;
    f[1].first = min(a1, 23);
    a1 -= f[1].first;
    f[4].second = min(b1, 13);
    b1 -= f[4].second;
    f[2].second = min(b1, 23);
    b1 -= f[2].second;
    f[3].second = min(b1, 23);
    b1 -= f[3].second;
    if (a1 or b1) continue;
    if (c == 0) return f;
    if (f[0].first + 2 == f[0].second) {
      f[0].first += c;
      f[0].second += c;
      return f;
    }
    if (f[4].first - 2 == f[4].second) {
      f[4].first += c;
      f[4].second += c;
      return f;
    }
  }
  return vpi(1,pi(-1,-1));
}

void print(bool q, vpi V) {
  int n = (int)V.size();
  pi res(3, n-3);
  if (!q) swap(res.first, res.second);
  cout << res.first << ":" << res.second << '\n';
  for (auto it : V) {
    if (!q) swap(it.first, it.second);
    cout << it.first << ":" << it.second << ' ';
  }
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  while (n--) {
    int a, b;
    cin >> a >> b;
    auto v = fes3(a,b);
    if (v.size() > 1) {
      print(true, v);
      continue;
    }
    v = fes13(a,b);
    if (v.size() > 1) {
      print(true, v);
      continue;
    }
    v = fes23(a,b);
    if (v.size() > 1) {
      print(true, v);
      continue;
    }
    v = fes23(b,a);
    if (v.size() > 1) {
      print(false, v);
      continue;
    }
    v = fes13(b,a);
    if (v.size() > 1) {
      print(false, v);
      continue;
    }
    v = fes3(b,a);
    if (v.size() > 1) {
      print(false, v);
      continue;
    }
    cout << "Impossible" << '\n';

  }
}