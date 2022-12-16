#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int n;

const int N = 505;
int r;
int a[N][N];

int uf[N*N];
int par[N*N];
int sal[N*N];
int idx[N*N];

void setup() {
  memset(uf, -1, sizeof uf);
}
int FIND(int u) {
  if (uf[u] == -1) {
    return u;
  }
  return uf[u] = FIND(uf[u]);
}

bool UNION(int u, int v){
  u = FIND(u);
  v = FIND(v);
  if (u == v) {
    return false;
  }
  uf[u] = v;
  return true;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  setup();
  cin >> n;
  r = n+1;
  set<int> sals;
  for (int i=1; i<=n; ++i) {
    sals.clear();
    for (int j=1; j<=n; ++j) {
      cin >> a[i][j];
      if (j != i) {
        sals.insert(a[i][j]);
      }
    }
    sal[i] = a[i][i];
    int z = i;
    for (auto& s : sals) {
      par[z] = r++;
      sal[par[z]] = s;
      z = par[z];
    }
  }
  map<int, int> mp;
  for (int i=1; i<=n; ++i) {
    mp.clear();
    for (int j=1; j<=n; ++j) {
      if (j != i) {
        mp[a[i][j]] = j;
      }
    }
    for (auto& [key, va] : mp) {
      int j = va;
      int co = a[i][j];
      int x = i, y = j;
      while (sal[x] != co) {
        x = par[x];
      }
      while (sal[y] != co) {
        y = par[y];
      }
      assert(sal[x] == a[i][j]);
      assert(sal[y] == a[i][j]);
      while (x) {
        assert(y);
        UNION(x, y);
        x = par[x];
        y = par[y];
      }
      assert(!y);
    }
  }
  vector<int> mem;
  int head = 0;
  for (int i=n+1; i<r; ++i) {
    if (FIND(i) == i) {
      mem.push_back(i);
      idx[i] = mem.size()+n;
      if (par[i] == 0) {
        assert(!head);
        head = mem.size()+n;
      }
    }
  }
  cout << mem.size()+n << "\n";
  for (int i=1; i<=n; ++i) {
    cout << sal[i] << " ";
  }
  for (auto& i : mem) {
    cout << sal[i] << " ";
  }
  cout << "\n";
  cout << head << "\n";
  for (int x=1; x<=n; ++x) {
    cout << x << " " << idx[FIND(par[x])] << "\n";
  }
  for (int i=0; i<mem.size(); ++i) {
    int x = mem[i];
    if (!par[x]) {
      continue;
    }
    cout << i+1+n << " " << idx[FIND(par[x])] << "\n";
  }
  return 0;
}