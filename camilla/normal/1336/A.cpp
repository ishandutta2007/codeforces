#include <cstdio>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

const int N = 200000 + 10;
vector<int> a[N];
int dep[N], f[N], cnt[N], acc[N];

void DFS(int u, int parent) {
  f[u] = parent;
  dep[u] = parent < 0 ? 0 : dep[parent] + 1;
  cnt[u] = 0;
  for (int k = 0; k < (int)a[u].size(); ++k) {
    int v = a[u][k];
  //for (auto& v : a[u]) {
    if (v == parent) continue;
    DFS(v, u);
    ++cnt[u];
  }
}

typedef long long int64;
typedef pair<int, int> ii;

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i < n; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    --x; --y;
    a[x].push_back(y);
    a[y].push_back(x);
  }
  DFS(0, -1);
  set<ii, greater<ii> > A;
  for (int i = 0; i < n; ++i) {
    if (!cnt[i]) A.insert(make_pair(dep[i], i));
    acc[i] = 1;
  }
  int64 ret = 0; 
  while (m--) {
    set<ii>::iterator it = A.begin();
    ret += it->first;
    int u = it->second;
    //cout << u << " " << it->first << endl;
    A.erase(it);
    int p = f[u];
    if (p != -1) {
      acc[p] += acc[u];
      if (--cnt[p] == 0) {
        A.insert(make_pair(dep[p] + 1 - acc[p], p));
      }
    }
  }
  printf("%lld\n", ret);
  
  return 0;
}