#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
using pii = pair<int, int>;
const int N = 2e5+10;
const int M = 600;
 
int a[N];
int b[N];
int typ[N];
int flag[N];
int root[N];
int tmp[N];
int q[N];
int qn;
 
inline int find_root(int u) {
  if(u == root[u]) {
    return u;
  }
  root[u] = find_root(root[u]);
  return root[u];
}
 
int main() {
#ifdef TRUE
  freopen("F.in", "r", stdin);
  freopen("out.out", "w", stdout);
#endif
  int n, m;
  scanf("%d %d", &n, &m);
  for(int i=0; i<m; i++) {
    scanf("%d", typ+i);
    scanf("%d", a+i);
    scanf("%d", b+i);
  }
  int t = 0;
  set<pii> st;
  set<pii> cr;
  int last = 0;
  while(t<m) {
    for(int i=1; i<=n; i++) {
      flag[i] = 0;
      root[i] = i;
    }
    for(int i=t; i<min(m, t+M); ) {
      if(a[i] > b[i]) {
        swap(a[i], b[i]);
      }
      flag[a[i]] = 1;
      flag[b[i]] = 1;
      flag[a[i]+1] = 1;
      flag[b[i]<n ? b[i]+1 : 1] = 1;
      i++;
    }
    qn=0;
    for(int i=1; i<=n; i++) {
      if(flag[i] == 1) {
        q[qn++]=i;
      }
    }
    int u, v, uu, vv;
    cr.clear();
    for(auto r:st) {
      u = r.x;
      v = r.y;
      if(flag[u] && flag[v]) {
        cr.insert(pii(u, v));
        continue;
      }
      u = find_root(u);
      v = find_root(v);
      root[u] = v;
    }
    for(int i=0; i<qn; i++) {
      root[q[i]] = find_root(q[i]);
    }
    sort(q, q+qn, [&](int i, int j) {
      return root[i]<root[j];
    });
    for(int i=0, j; i<qn; i=j) {
      j=i;
      while(j<qn && root[q[j]] == root[q[i]]) {
        tmp[q[j]] = q[i];
        j++;
      }
    }
    for(auto r:cr) {
      uu = find_root(r.x);
      vv = find_root(r.y);
      root[uu] = vv;
    }
    for(int i=t; i<min(m, t+M); i++) {
      u = a[i];
      v = b[i];
      if(last) {
        u ++;
        v < n ? v ++ : v = 1;
      }
      if(u>v) {
        swap(u, v);
      }
      if(typ[i] == 1) {
        if(cr.count(pii(u, v))) {
          cr.erase(pii(u, v));
          st.erase(pii(u, v));
          for(int i=0; i<qn; i++) {
            root[q[i]] = tmp[q[i]];
          }
          for(auto r:cr) {
            uu = find_root(r.x);
            vv = find_root(r.y);
            root[uu] = vv;
          }
        }else {
          cr.insert(pii(u, v));
          st.insert(pii(u, v));
          u = find_root(u);
          v = find_root(v);
          root[u] = v;
        }
      }else {
        u = find_root(u);
        v = find_root(v);
        if(u == v) {
          putchar('1');
          last = 1;
        }else {
          putchar('0');
          last = 0;
        }
      }
    }
    t+=M;
  }
  puts("");
  return 0;
}