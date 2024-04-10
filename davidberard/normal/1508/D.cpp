#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

struct Pt {
  ll x, y;
  int idx, val;
  Pt operator- (const Pt& o) const {
    return {x-o.x, y-o.y, -1, -1};
  }
};

ll cp(const Pt& a, const Pt& b) {
  return a.x*b.y - a.y*b.x;
}

const int N = 2020;
Pt pts[N];
int uf[N];
void setup() {
  memset(uf, -1, sizeof uf);
}
int FIND(int u) {
  if (uf[u] == -1) return u;
  return uf[u] = FIND(uf[u]);
}
bool UNION(int u, int v) {
  if (FIND(u) == FIND(v)) {
    return false;
  }
  uf[FIND(u)] = FIND(v);
  return true;
}

int n;

int seen[N];
int zz = 0;
pair<int, int> build(int u) {
  if (seen[u]) return {0, 0};
  int v = u;
  int amt = 0;
  do {
    ++amt;
    int w = pts[v].val;
    UNION(w, v);
    v = w;
  } while (v != u);
  return {u, amt};
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  setup();
  cin >> n;
  vector<Pt> f;
  for (int i=1; i<=n; ++i) {
    int x, y, v;
    cin >> x >> y >> v;
    pts[i] = {x, y, i, v};
    if (i != v) {
      f.push_back(pts[i]);
    }
  }
  if (f.size() == 0) {
    cout << 0 <<"\n";
    return 0;
  }
  Pt best = {(ll) 1e8, (ll) 1e8, (ll) 1e8, (ll) 1e8};
  int bi = -1;
  for (int i=0; i<f.size(); ++i) {
    auto p = f[i];
    if (p.x < best.x || (p.x == best.x && p.y < best.y)) {
      best = p;
      bi = i;
    }
  }
  for (int i=1; i<=n; ++i) {
    build(i);
  }
  swap(f[bi], f[0]);
  sort(f.begin()+1, f.end(), [best](const Pt& a, const Pt& b) {
    return cp(a-best, b-best) > 0;
  });
  vector<pair<int, int>> swaps;
  for (int i=1; i<f.size()-1; ++i) {
    if (UNION(f[i].idx, f[i+1].idx)) {
      swaps.push_back({f[i].idx, f[i+1].idx});
      swap(pts[f[i].idx].val, pts[f[i+1].idx].val);
      swap(f[i].val, f[i+1].val);
    }
  }
  bi = f[0].idx;
  while (bi != pts[bi].val) {
    int v = pts[bi].val;
    swaps.push_back({bi, v});
    swap(pts[bi].val, pts[v].val);
  }
  cout << swaps.size() << "\n";
  for (auto& [u, v] : swaps) {
    cout << u << " " << v << "\n";
  }
  return 0;
}