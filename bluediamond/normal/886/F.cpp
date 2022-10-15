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
#include <cstdio> 


bool home = true;
using namespace std;
#define int long long 

class Vector {
public:
  int x;
  int y;
};

bool operator == (Vector a, Vector b) { return a.x == b.x && a.y == b.y; }
Vector operator + (Vector a, Vector b) { return { a.x + b.x, a.y + b.y }; }
Vector operator - (Vector a, Vector b) { return { a.x - b.x, a.y - b.y }; }
Vector operator / (Vector a, int b) { return { a.x / b, a.y / b }; }
int dot(Vector a, Vector b) { return a.x * b.x + a.y * b.y; }

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

  int n;
  cin >> n;
  vector<Vector> pts(n);
  Vector g = { 0, 0 };
  for (auto& pt : pts) {
    cin >> pt.x >> pt.y;
    pt.x *= 2;
    pt.y *= 2;
    g = g + pt;
    pt.x *= n;
    pt.y *= n;
  }
  vector<bool> alive(n, true);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (pts[i] - g == g - pts[j]) {
        alive[i] = alive[j] = false;
        break;
      }
    }
  }
  n = 0;
  for (int i = 0; i < (int)pts.size(); i++) {
    if (alive[i]) {
      swap(pts[n++], pts[i]);
    }
  }
  pts.resize(n);
  if (n <= 1) {
    cout << "-1\n";
    return 0;
  }
  int sol = 0;
  vector<pair<int, int>> v(n);
  for (int other = 0; other < n; other++) {
    Vector mid = (pts[other] + pts[0]) / 2;
    mid = g - mid;
    Vector line = { mid.y, -mid.x };
    for (int i = 0; i < n; i++) {
      v[i] = { dot(pts[i], line), i }; // no need to scale line to a linear vector :) bc all are scaled by the same value
    }
    sort(v.begin(), v.end());
    int p0, poth = 0;
    for (int i = 0; i < n; i++) {
      if (v[i].second == 0) p0 = i;
      if (v[i].second == other) poth = i;
    }

    if (p0 + poth != n - 1) continue;
    bool ok = 1;
    for (int i = 0; i < n; i++) {
      ok &= (v[i].first + v[n - 1 - i].first == v[0].first + v[n - 1].first);
    }
    sol += ok;
  }
  cout << sol << "\n";
}