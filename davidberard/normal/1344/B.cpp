#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

struct UF {
  vector<int> par;
  int n;
  UF (int sz) {
    n = sz;
    par = vector<int>(n, -1);
  }
  int FIND(int u) {
    if (par[u] == -1) {
      return u;
    }
    return par[u] = FIND(par[u]);
  }
  void UNION(int u, int v) {
    //cerr << " UNION " << u << "," << v << endl;
    if (FIND(u) == FIND(v)) {
      return;
    }
    par[FIND(u)] = FIND(v);
  }
};

int n, m;
UF uf(1010*1010);

char grid[1010][1010];

void esc() {
  cout << -1 << endl;
  exit(0);
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  for (int i=0; i<n; ++i) {
    cin >> grid[i];
    int state = 0;
    for (int j=0; j<m; ++j) {
      if (state == 0 && grid[i][j] == '#') {
        ++state;
      } else if (state == 1 && grid[i][j] == '.') {
        ++state;
      } else if (state == 2 && grid[i][j] == '#') {
        ++state;
      } else if (state == 3 && grid[i][j] == '.') {
        ++state;
      }
    }
    if (state > 2) {
      esc();
    }
  }
  for (int j=0; j<m; ++j) {
    int state =0;
    for (int i=0; i<n; ++i) {
      if (state == 0 && grid[i][j] == '#') {
        ++state;
      } else if (state == 1 && grid[i][j] == '.') {
        ++state;
      } else if (state == 2 && grid[i][j] == '#') {
        ++state;
      } else if (state == 3 && grid[i][j] == '.') {
        ++state;
      }
    }
    if (state > 2) {
      esc();
    }
  }

  bool has_zrows = 0, has_zcols = 0;
  for (int i=0; i<n; ++i) {
    bool zrow = 1;
    for (int j=0; j<m; ++j) {
      if (grid[i][j] == '#') {
        zrow = 0;
      }
    }
    has_zrows |= zrow;
  }

  for (int j=0; j<m; ++j) {
    bool zcol = 1;
    for (int i=0; i<n; ++i) {
      if (grid[i][j] == '#') {
        zcol = 0;
      }
    }
    has_zcols |= zcol;
  }

  if (has_zrows != has_zcols) {
    esc();
  }

  for (int i=0; i<n-1; ++i) {
    for (int j=0; j<m; ++j) {
      if (grid[i][j] == '#' && grid[i+1][j] == '#') {
        uf.UNION(i*1001+j, (i+1)*1001+j);
      }
    }
  }
  for (int i=0; i<n; ++i) {
    for (int j=0; j<m-1; ++j) {
      if (grid[i][j] == '#' && grid[i][j+1] == '#') {
        uf.UNION(i*1001+j, i*1001+(j+1));
      }
    }
  }

  int ans = 0;
  for (int i=0; i<n; ++i) {
    for (int j=0; j<m; ++j) {
      if (grid[i][j] == '#' && uf.par[i*1001+j] == -1) {
        ++ans;
      }
    }
  }
  cout << ans << "\n";
  return 0;
}