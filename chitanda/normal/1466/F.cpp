#include <cstdio>
#include <vector>
#define M 1000000007

int n, m;
int fa[500005];

int two(int n) {
  int ret = 1, base = 2;
  for(; n; n >>= 1, base = (long long)base * base % M)
     if (n & 1) ret = (long long)ret * base % M;
  return ret;
}

int find(int x) {
  return fa[x] == x ? x : fa[x] = find(fa[x]);
}

int merge(int x, int y) {
  fa[find(x)] = find(y);
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    fa[i] = i;
  }
  std::vector<int> ans;
  for (int i = 1; i <= n; ++i) {
    static int k, x, y;
    scanf("%d", &k);
    if (k == 1) {
      scanf("%d", &x);

      if (find(x) != find(0)) {
        merge(x, 0);
        ans.push_back(i);
      }
    } else {
      scanf("%d%d", &x, &y);
      if(find(x) != find(y)) {
        merge(x, y);
        ans.push_back(i);
      }
    }
  }
  printf("%d %d\n", two(ans.size()), ans.size());
  for (int v : ans)
    printf("%d ", v);
  puts("");
}