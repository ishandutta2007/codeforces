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

int n, col[NX]; vector<int> edge[NX];
int siz[NX], prefer[NX];

void init_prefer(int x, int fa) {
  siz[x] = 1;
  for (int y : edge[x]) {
    if (y == fa) continue;
    init_prefer(y, x);
    siz[x] += siz[y];
    if (siz[y] > siz[prefer[x]])
      prefer[x] = y;
  }
}

int pivot, bucket[NX], mx; LL sum, ans[NX];
void calculate(int x, int fa, int type) {
  if (cmax(mx, bucket[col[x]] += type)) 
    sum = 0;
  if(bucket[col[x]] == mx)
    sum += col[x];
  for (int y : edge[x]) {
    if (y == fa || y == pivot)
      continue;
    calculate(y, x, type);
  } 
}
void dfs(int x, int fa, int type) {
  for (int y : edge[x]) {
    if (y == fa || y == prefer[x])
      continue;
    dfs(y, x, -1);
  }  
  if(prefer[x]) {
    dfs(prefer[x], x, 1);
    pivot = prefer[x];
  }
  calculate(x, fa, 1);
  pivot = 0;
  ans[x] = sum;
  if (!~type) {
    calculate(x, fa, -1);
    sum = mx = 0;
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d", col + i);
  for (int i = 1, u, v; i < n; i++) {
    scanf("%d%d", &u, &v);
    edge[u].push_back(v);
    edge[v].push_back(u); 
  }
  
  init_prefer(1, 0); dfs(1, 0, 1);
  for (int i = 1; i <= n; i++)
    printf("%lld ", ans[i]);
  return 0;
}