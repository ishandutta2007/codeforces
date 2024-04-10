#include <bits/stdc++.h>

bool home = 1;
using namespace std;

typedef long long ll;

#define no() {cout << "Impossible\n"; exit(0);}

const int N = (int) 2e5 + 7;
int n, m, s, par[N], last[N], tt;
vector<int> g[N];

void print(vector<int> road) {
  cout << (int) road.size() << "\n";
  reverse(road.begin(), road.end());
  for (auto &X : road) {
    cout << X << " ";
  }
  cout << "\n";
}

void fnd(vector<int>& v, int x) {
  while (x != s) {
    v.push_back(x);
    x = par[x];
  }
  v.push_back(x);
}

void explore(int a, int p) {
  last[a] = tt;

  if (par[a]) {
    vector<int> c1, c2;
    fnd(c1, a);
    par[a] = p;
    fnd(c2, a);
    cout << "Possible\n";
    print(c1);
    print(c2);
    exit(0);
  }
  par[a] = p;
  for (auto &b : g[a]) {
    if (last[b] != tt) {
      explore(b, a);
    }
  }
}

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif

  if (home) {
    freopen("I_am_iron_man", "r", stdin);
  }
  else {
    ios::sync_with_stdio(0); cin.tie(0);
  }

  cin >> n >> m >> s;
  for (int i = 1; i <= m; i++) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
  }
  for (auto &child : g[s]) {
    tt++;
    last[s] = tt;
    explore(child, s);
  }
  no();
}