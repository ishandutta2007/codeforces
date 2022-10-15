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

typedef long long ld;

class Vector {
public:
  ld x, y;
};

Vector operator + (Vector a, Vector b) { return { a.x + b.x, a.y + b.y }; }
Vector operator - (Vector a, Vector b) { return { a.x - b.x, a.y - b.y }; }
Vector operator * (Vector a, ld b) { return { a.x * b, a.y * b }; }
Vector operator / (Vector a, ld b) { return { a.x / b, a.y / b }; }
Vector operator * (ld b, Vector a) { return { a.x * b, a.y * b }; }
ld dot(Vector a, Vector b) { return  a.x * b.x + a.y * b.y; }
ld cross(Vector a, Vector b) { return a.x * b.y - a.y * b.x; }
ld get_norm(Vector a) { return sqrt(a.x * a.x + a.y * a.y); }
Vector normalize(Vector a) { return a / get_norm(a); }
ld getArea(Vector a, Vector b) { return (a.x + b.x) * (a.y - b.y); }
ld getArea(Vector a, Vector b, Vector c) { return getArea(a, b) + getArea(b, c) + getArea(c, a); }
ld getDistSq(Vector a, Vector b) { return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y); }

Vector spec;

bool type;

bool operator < (Vector p1, Vector p2) {
  if (!type) {
    if (getArea(spec, p1, p2) == 0) return getDistSq(spec, p1) < getDistSq(spec, p2);
    return getArea(spec, p1, p2) < 0;
  }
  else {
    if (p1.x != p2.x) return p1.x < p2.x;
    return p1.y < p2.y;
  }
}

class Hulk {
private:

public:
  vector<Vector> Hulkize(vector<Vector> points) {
    assert(!points.empty());
    int n = (int)points.size();
    for (int i = 1; i < n; i++) {
      if (points[i].x < points[0].x) {
        swap(points[i], points[0]);
      }
      else {
        if (points[i].x == points[0].x && points[i].y < points[0].y) {
          swap(points[i], points[0]);
        }
      }
    }
    spec = points[0];
    sort(points.begin() + 1, points.end());
    points.push_back(points[0]);
    vector<Vector> sol;
    for (auto& p : points) {
      while ((int)sol.size() >= 2 && getArea(sol[(int)sol.size() - 2], sol[(int)sol.size() - 1], p) >= 0) {
        sol.pop_back();
      }
      sol.push_back(p);
    }
    return sol;
  }
};

vector<ld> get(vector<Vector> a) {
  int n = (int)a.size();
  vector<ld> x;
  for (int i = 0; i < n; i++) {
    Vector ant = a[i], now = a[(i + 1) % n], nxt = a[(i + 2) % n];
    x.push_back(getDistSq(ant, now));
    x.push_back(getDistSq(ant, nxt));
  }
  return x;
}

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
  int n, m;
  cin >> n >> m;
  vector<Vector> a(n);
  vector<Vector> b(m);
  vector<Vector> ai, bi;
  for (auto& p : a) {
    cin >> p.x >> p.y;
  }
  for (auto& p : b) {
    cin >> p.x >> p.y;
  }
  ai = a;
  bi = b;
  Hulk hulk;
  a = hulk.Hulkize(a);
  b = hulk.Hulkize(b);

  a.pop_back();
  b.pop_back();

  if ((int)b.size() != (int)a.size()) {
    cout << "NO\n";
    return 0;
  }

  if ((int)a.size() == 1) {
    a = ai;
    b = bi;
    type = 1;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if (getDistSq(a[0], a[n - 1]) == getDistSq(b[0], b[m - 1])) {
      cout << "YES\n";
    }
    else {
      cout << "NO\n";
    }
    return 0;
  }
  n = (int)a.size();


  vector<ld> x = get(a), y = get(b);

  n = (int)x.size();
  assert((int)y.size() == n);

  for (int i = 0; i < n; i++) {
    x.push_back(x[i]);
  }
  vector<int> ps((int)y.size());
  ps[0] = 0;
  int j = 0;
  for (int i = 1; i < (int)y.size(); i++) {
    while (j && y[i] != y[j]) j = ps[j - 1];
    if (y[i] == y[j]) j++;
    ps[i] = j;
  }

  j = 0;
  for (int i = 0; i < (int)x.size(); i++) {
    while (j && x[i] != y[j]) j = ps[j - 1];
    if (x[i] == y[j]) j++;
    if (j == (int)y.size()) {
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO\n";

}