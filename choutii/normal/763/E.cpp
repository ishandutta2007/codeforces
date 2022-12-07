#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
#define T_ template
#define Tn typename
T_ <Tn T> inline bool cmin(T & a, const T & b) { return a > b ? a = b, 1 : 0;}
T_ <Tn T> inline bool cmax(T & a, const T & b) { return a < b ? a = b, 1 : 0;}
T_ <Tn L, Tn R> ostream & operator << (ostream &out, pair<L, R> t) {
   return out << "(" << t.first << "," << t.second << ")";
}
T_ <Tn T> ostream & operator << (ostream &out, vector<T> t) {
  for (unsigned i = 0; i < t.size(); i++)
    out << (" ("[!i]) << t[i] << (",)"[i == t.size() - 1]);
  return out;
}

const int NX = 101234;

int n, m, k, q;
int fa[NX], edge[NX][6], intree[NX][6], f[NX], g[NX];

int find(int x) {
  return fa[x] == x ? x : fa[x] = find(fa[x]);
}

int main() {
  scanf("%d%d%d", &n, &k, &m);
  for (int i = 1; i <= m; i++) {
    int u, v; scanf("%d%d", &u, &v);
    if (u > v) swap(u, v);
    int width = v - u;
    edge[u][width] = true;
  }
  
  for (int i = 1; i <= n; i++) 
    fa[i] = i;
  
  for (int i = 1; i <= k; i++) {
    for (int j = 1; j <= n; j++) {
      if (!edge[j][i])
        continue;
      int u = find(j), v = find(j + i);
      if (u != v) {
        fa[u] = v;
        intree[j][i] = true;
        ++f[i + j];
        ++g[j];
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    f[i] += f[i - 1];
    g[i] += g[i - 1];
  }
  
  int q; scanf("%d", &q);
  while (q--) {
    int l, r; scanf("%d%d", &l, &r);
    int ans = r - l + 1 - (f[r] - g[l - 1]);
    for (int i = l - 1; i + k > r; i--)
      for (int j = k; i + j > r; j--) {
        if(intree[i][j])
          --ans;
      }
    printf("%d\n", ans);
  }
  return 0;
}