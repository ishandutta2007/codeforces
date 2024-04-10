    #include<bits/stdc++.h>
     
    using namespace std;
     
    typedef long long ll;
    typedef long double ld;
    typedef pair<int, int> pi;
    typedef vector<int> vi;
    typedef vector<ll> vll;
    typedef vector<vll> vvll;
    typedef vector<vi> vvi;
    typedef vector<pi> vpi;
    typedef vector<vpi> vvpi;
     
    vvi G;
    const int L = 20;
    vvi D;
    vi P;
    vpi A;
    vi C;
    int cont;
     
    void dfs(int x, int d = 0, int p = -1) {
      C[cont] = x;
      A[x].first = cont++;
      P[x] = d;
      D[x][0] = p;
      int l = 0;
      while (D[x][l] != -1) {
        D[x][l+1] = D[D[x][l]][l];
        l++;
      }
      for (auto y : G[x]) {
        if (y == p) continue;
        dfs(y, d+1, x);
      }
      C[cont] = x;
      A[x].second = cont++;
    }
     
    int lca(int x, int y) {
      if (P[x] < P[y]) swap(x, y);
      int l = L;
      while (l--) {
        int x0 = D[x][l];
        if (x0 != -1 and P[x0] >= P[y]) x = x0;
      }
      if (x == y) return x;
      l = L;
      while (l--) {
        int x0 = D[x][l];
        int y0 = D[y][l];
        if (x0 != y0) {
          x = x0;
          y = y0;
        }
      }
      return D[x][0];
    }
     
    struct que {
      int a, b, lc;
      int ind;
    };
     
    const int S = 320;
     
    bool comp(que a, que b) {
      int x = a.a/S;
      int y = b.a/S;
      if (x != y) return x < y;
      return (x&1 ? a.b > b.b : a.b < b.b);
    }
     
    inline void fes(int x, vvll& tt, vpi& V, vi& vist, ll& res) {
        vist[x] ^= 1;
        if (vist[x]) {
          res += tt[V[x].first^1][V[x].second];
          ++tt[V[x].first][V[x].second];
        }
        else {
          res -= tt[V[x].first^1][V[x].second];
          --tt[V[x].first][V[x].second];
        }
    }
     
    int main() {
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int n;
      cin >> n;
      G = vvi(n);
      D =vvi(n, vi(L, -1));
      P = vi(n);
      vpi V(n);
      cont = 0;
      C = vi(2*n);
      A = vpi(n);
      for (int i = 0; i < n; ++i) cin >> V[i].first;
      vi cc(n);
      for (int i = 0; i < n; ++i) {
        cin >> V[i].second;
        cc[i] = V[i].second;
      }
      sort(cc.begin(), cc.end());
      int sz = unique(cc.begin(), cc.end()) - cc.begin();
      map<int, int> M;
      for (int i = 0; i < sz; ++i) M[cc[i]] = i;
      for (int i = 0; i < n; ++i) V[i].second = M[V[i].second];
      for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        G[a].push_back(b);
        G[b].push_back(a);
      }
      dfs(0);
      int m;
      cin >> m;
      vector<que> Q(m);
      for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        Q[i].ind = i;
        if (A[b].first < A[a].first) swap(a, b);
        if (A[a].second >= A[b].second) {
          Q[i].a = A[a].first;
          Q[i].b = A[b].first;
          Q[i].lc = -1;
        }
        else {
          Q[i].a = A[a].second;
          Q[i].b = A[b].first;
          Q[i].lc = lca(a, b);
        }
      }
      sort(Q.begin(), Q.end(), comp);
      vll R(m);
      vvll tt(2, vll(sz, 0));
      vi vist(n, 0);
      ll res = 0;
      int b = -1;
      int a = 0;
      for (auto q : Q) {
        while (b < q.b) {
          ++b;
          int x = C[b];
          fes(x, tt, V, vist, res);
        }
        while (a > q.a) {
          --a;
          int x = C[a];
          fes(x, tt, V, vist, res);
        }
        while (b > q.b) {
          int x = C[b];
          fes(x, tt, V, vist, res);
          --b;
        }
        while (a < q.a) {
          int x = C[a];
          fes(x, tt, V, vist, res);
          ++a;
        }
     
        if (q.lc != -1) {
          fes(q.lc, tt, V, vist, res);
        }
        R[q.ind] = res;
        if (q.lc != -1) {
          fes(q.lc, tt, V, vist, res);
        }
      }
      for (auto r : R) cout << r << '\n';
    }