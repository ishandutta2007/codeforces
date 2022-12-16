#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 300300;

struct AhoCorasick {
  enum { NMAX = N, ALPHA = 26 };
  //int toi(char c) { assert(false); } // <- implement
  int toi(char c) { return c - 'a'; } // char to int
  int sz;

  int f[NMAX][ALPHA]; // down edges
  int g[NMAX];        // fail links
  int v[NMAX];
  int h[NMAX][ALPHA]; // compressed fail/down
  //ll val[NMAX];       // value at position i in 
  //int ord[NMAX];       // ord[i] = location of ith string
  int cid[NMAX];
  int qu[NMAX];        // queue 

  AhoCorasick() {
    sz = 1;
    memset(f, 0, sizeof f);
    memset(g, 0, sizeof g);
    memset(h, 0, sizeof h);
    memset(v, -1, sizeof h);
    //memset(val, 0, sizeof val);
    memset(cid, 0, sizeof cid);
  }

  pair<int, int> insert(const string& s, int id) {
    int u = 1;
    for (int i=0; i<s.size(); ++i) {
      if (!f[u][toi(s[i])]) {
        f[u][toi(s[i])] = ++sz;
      }
      u = f[u][toi(s[i])];
    }
    //ord[id] = u;
    if (!cid[u]) {
      cid[u] = id;
    }
    return {cid[u], u};
  }

  void build() {
    int qcur=0, qlen=0;
    g[1] = 1;
    v[1] = 1;
    for (int j=0; j<ALPHA; ++j) {
      if (f[1][j]) {
        qu[qlen++] = f[1][j];
        g[f[1][j]] = 1;
        v[f[1][j]] = 1;
        h[1][j] = f[1][j];
      } else {
        h[1][j] = 1;
      }
    }
    while (qcur < qlen) {
      int u = qu[qcur++];
      v[u] = (cid[g[u]] ? g[u] : v[g[u]]);
      for (int j=0; j<ALPHA; ++j) {
        if (!f[u][j]) {
          h[u][j] = h[g[u]][j];
          continue;
        }
        h[u][j] = f[u][j];

        int p=g[u];
        while (p != 1 && f[p][j] == 0) p = g[p];
        if (f[p][j]) p=f[p][j];
        g[f[u][j]] = p;

        qu[qlen++] = f[u][j];
      }
    }
  }

  // find next occurrence of char nxt
  int next(int pos, char nxt) {
    /*
    int k = toi(nxt);
    while (pos != 1 && f[pos][k] == 0) pos = g[pos];
    if (f[pos][k]) return f[pos][k];
    return 1;
    */
    return h[pos][toi(nxt)];
  }
};

string target[N];
int suspicion[N];
int v[N];
set<pair<int, int>> of[N];
int mp[N];
int loc[N];
char p[N];
int n, m;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  AhoCorasick A;
  cin >> n >> m;
  for (int i=1; i<=n; ++i) {
    cin >> target[i];
    auto [x, l]= A.insert(target[i], i);
    mp[i] = x;
    of[mp[i]].insert({0, i});
    loc[i] = l;
  }
  A.build();
  int t2 = 0;
  for (int tt=1; tt<=m; ++tt) {
    int type; 
    cin >> type;
    if (type == 1) {
      int i, x;
      cin >> i >> x;
      of[mp[i]].erase({v[i], i});
      v[i] = x;
      of[mp[i]].insert({v[i], i});
      suspicion[mp[i]] = of[mp[i]].rbegin()->first;
      //A.v[loc[mp[i]]] = suspicion[mp[i]];
    } else {
      cin >> p;
      int x = 1;
      int ans = -1;
      for (int i=0; p[i]; ++i) {
        char c = p[i];
        x = A.next(x, c);
        int y = x;
        while (y > 1) {
          //ans = max(ans, A.v[y]); //(A.cid[y] ? suspicion[A.cid[y]]: -1));
          ans = max(ans, (A.cid[y] ? suspicion[A.cid[y]]: -1));
          y = A.v[y];
        }
      }
      cout << ans << "\n";
    }
  }
  return 0;
}