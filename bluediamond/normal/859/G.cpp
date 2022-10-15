#include <iostream>
#include <vector> 
#include <algorithm> 
#include <string> 
#include <cassert> 
#include <algorithm> 
#include <set> 
#include <iomanip> 
#include <queue> 
#include <deque> 
#include <unordered_set> 
#include <unordered_map> 
#include <functional> 
#include <cmath> 
#include <map> 
#include <random> 
#include <chrono> 

bool home = true;

using namespace std;

int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

typedef long double ld;
typedef long long ll;

struct P {
  ld x;
  ld y;
};

P operator + (P a, P b) {
  return { a.x + b.x, a.y + b.y };
}

P operator * (P a, ld v) {
  return { a.x * v, a.y * v };
}

const ld pi = 3.14159265358979323846264338327950288419716939937510;
const ld eps = 1e-9;

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    FILE* stream;
    freopen_s(&stream, "iron_man.txt", "r", stdin);
  }
  else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  time_t bg = clock();

  int n;
  vector<int> a;
  vector<P> pts;

  {
    cin >> n;
    a.resize(n);
    pts.resize(n);
    {
      string s;
      cin >> s;
      assert((int)s.size() == n);
      for (int i = 0; i < n; i++) {
        a[i] = s[i] - '0';
        ld ang = 2 * pi * i / n;
        pts[i] = { cos(ang), sin(ang) };
      }
    }
  }
  mt19937 rng((long long)(new char));




  while (1) {
    time_t nd = clock();
    if ((double) (nd - bg) / CLOCKS_PER_SEC > 0.95) break;
    int m = rng() % n;
    while (gcd(m, n) != 1) {
      m = rng() % n;
    }
    P s = { 0, 0 };
    for (int i = 0; i < n; i++) {
      s = s + pts[i] * a[i * (ll)m % n];
    }
    if (abs(s.x) > eps || abs(s.y) > eps) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
}