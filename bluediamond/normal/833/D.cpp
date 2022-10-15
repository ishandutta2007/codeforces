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

bool home = true;
using namespace std;
#define int long long

typedef long long ll;
typedef long double ld;

const int M = (int)1e9 + 7;

int add(int a, int b) {
  a += b;
  if (a >= M) return a - M;
  if (a < 0) return a + M;
  return a;
}

int mul(int a, int b) {
  return a * (ll)b % M;
}

int pw(int a, int b) {
  int r = 1;
  while (b) {
    if (b & 1) r = mul(r, a);
    a = mul(a, a);
    b /= 2;
  }
  return r;
}

int dv(int a, int b) {
  return mul(a, pw(b, M - 2));
}

void addup(int& a, int b) {
  a = add(a, b);
}

void mulup(int& a, int b) {
  a = mul(a, b);
}

const int N = (int)1e5 + 7;

struct Edge {
  int to;
  int type;
  int w;
};

int n;
vector<Edge> g[N];
int print = 1;

bool blocked[N];
int under[N];
int total_under;

void build_under(int a, int p = -1) {
  under[a] = 1;
  for (auto& edge : g[a]) {
    int b = edge.to, type = edge.type, w = edge.w;
    if (blocked[b] || b == p) continue;
    build_under(b, a);
    under[a] += under[b];
  }
}

int fcen(int a, int p = -1) {
  int mx = total_under - under[a];
  for (auto& edge : g[a]) {
    int b = edge.to, type = edge.type, w = edge.w;
    if (blocked[b] || b == p) continue;
    mx = max(mx, under[b]);
  }
  if (mx <= total_under / 2) return a;
  for (auto& edge : g[a]) {
    int b = edge.to, type = edge.type, w = edge.w;
    if (blocked[b] || b == p) continue;
    if (under[b] == mx) return fcen(b, a);
  }
  assert(0);
}

bool isok(int a, int b) {
  if (a > b) swap(a, b);
  return a <= b && b <= a * 2;
}

int cnt[N][2], prod[N];

void build(int a, int p = -1) {
  if (isok(cnt[a][0], cnt[a][1])) {
    mulup(print, prod[a]);
  }
  for (auto& edge : g[a]) {
    int b = edge.to, type = edge.type, w = edge.w;
    if (blocked[b] || b == p) continue;
    prod[b] = mul(prod[a], w);
    cnt[b][0] = cnt[a][0];
    cnt[b][1] = cnt[a][1];
    cnt[b][type]++;
    build(b, a);
  }
}

struct Data {
  int cnt0, cnt1, prod;
};

vector<Data> currentData;

void explore(int a, int p) {
  currentData.push_back({ cnt[a][0], cnt[a][1], prod[a] });
  for (auto& edge : g[a]) {
    int b = edge.to, type = edge.type, w = edge.w;
    if (blocked[b] || b == p) continue;
    explore(b, a);
  }
}

struct P {
  int dif;
  int prod;
};

bool operator < (P a, P b) {
  return a.dif < b.dif;
}

int get(vector<P> all) {
  sort(all.begin(), all.end());
  int sol = 1;
  for (auto& x : all) {
    int cnt = 0, low = 0, high = (int)all.size() - 1;
    while (low <= high) {
      int i = (low + high) / 2;
      if (all[i].dif + x.dif > 0) {
        high = i - 1;
        cnt = (int)all.size() - i;
      }
      else {
        low = i + 1;
      }
    }
    mulup(sol, pw(x.prod, cnt));
  }
  return sol;
}

void solve(int a) {
  build_under(a);
  total_under = under[a];
  a = fcen(a);


  cnt[a][0] = cnt[a][1] = 0;
  prod[a] = 1;
  if (home) {
    cout << "centroid = " << a << "\n";
  }
  build(a);

  vector<vector<Data>> datas;

  int lz = 0;

  for (auto& edge : g[a]) {
    int b = edge.to, type = edge.type, w = edge.w;
    if (blocked[b]) continue;
    currentData.clear();
    explore(b, a);
    lz += (int)currentData.size();
    datas.push_back(currentData);
  }

  int dim = (int)datas.size();
  int sol = 1, prod = 1;

  for (int i = 0; i < dim; i++) {
    for (auto& x : datas[i]) {
      mulup(prod, pw(x.prod, lz - (int)datas[i].size()));
    }
  }

  for (int step = 0; step < 2; step++) {
    vector<vector<P>> guys(dim);
    for (int i = 0; i < dim; i++) {
      guys[i].reserve((int)datas[i].size());
      for (auto& x : datas[i]) {
        guys[i].push_back({ x.cnt1 - 2 * x.cnt0, x.prod });
      }
    }
    vector<P> all;
    for (int i = 0; i < dim; i++) {
      for (auto& x : guys[i]) {
        all.push_back(x);
      }
    }
    mulup(sol, get(all));
    int inv = 1;
    for (int i = 0; i < dim; i++) {
      mulup(inv, get(guys[i]));
    }
    sol = dv(sol, inv);
    for (int i = 0; i < dim; i++) {
      for (auto& x : datas[i]) {
        swap(x.cnt0, x.cnt1);
      }
    }
  }
  mulup(print, dv(prod, sol));

  blocked[a] = 1;
  for (auto& edge : g[a]) {
    int b = edge.to, type = edge.type, w = edge.w;
    if (blocked[b]) continue;
    solve(b);
  }
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

  cin >> n;
  for (int i = 1; i < n; i++) {
    int a, b, type, w;
    cin >> a >> b >> w >> type;
    g[a].push_back({ b, type, w });
    g[b].push_back({ a, type, w });
  }

  solve(1);

  cout << print << "\n";
}