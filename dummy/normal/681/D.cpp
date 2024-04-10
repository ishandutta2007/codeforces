#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector< int > ch[N];
int n, m, a[N], lv[N], to[N];
vector< int > val;
bool dfs(int v, int l) {
  bool ret = true;
  lv[v] = l;
  for(int u : ch[v]) {
    ret &= dfs(u, l+1);
    if(a[u] != u && a[u] != a[v])
      ret = false;
    // cerr << u << " " << a[u] << " " << v << " " << a[v] << " " << ret << endl;
  }
  if(a[v] == v)
    val.push_back(v+1);
  return ret;
}

int main() {
  scanf("%d%d", &n, &m);
  for(int i = 0; i<m; i++) {
    int p,q ;
    scanf("%d%d", &p, &q);
    p--; q--;
    ch[p].push_back(q);
    to[q]++;
  }
  for(int i = 0; i<n; i++) {
    scanf("%d", a+i); a[i]--;
  }
  memset(lv, -1, sizeof lv);
  bool ans = true;
  for(int i = 0; i<n; i++) if(to[i] == 0) {  
    ans &= dfs(i, 0); 
  }
  if(ans) {
    printf("%d\n", val.size());
    for(int i = 0; i<val.size(); i++)
      printf("%d\n", val[i]);
  }
  else
    printf("-1\n");
  return 0;
}