#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MaxN = 1000010;
const int mod = 1e9 + 7;
 
int n, prod[MaxN], p[MaxN], l[MaxN], r[MaxN], s1[MaxN], s2[MaxN];
vector <int> factor[MaxN];

bool add(int *l, int a, int b) {
  if (l[a] && l[a] != b) return false;
  l[a] = b; return true;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d", p + i), prod[i] = 1;
  factor[1].push_back(1); 
  for (int i = 2; i <= n; i++)
    if (!factor[i].size())  
      for (int j = i; j <= n; j += i)
        factor[j].push_back(i), prod[j] *= i;
  
  for (int i = 1; i <= n; i++) {
    if (!p[i]) continue;
    vector<int> a = factor[i], b = factor[p[i]];
    if (a.size() != b.size()) {
      return puts("0"), 0;
    }
    for (unsigned _ = 0; _ < a.size(); _++) {
      int x = a[_], y = b[_];
      if ((x == 1 ? 1 : n / x) != (y == 1 ? 1 : n / y))
        return puts("0"), 0;
      if (!add(l, x, y) || !add(r, y, x))
        return puts("0"), 0;
    }
  } 
  
  int ans = 1;
  for (int i = 1; i <= n; i++) {
    if (!l[i] && factor[i][0] == i) {
      ++s1[i == 1 ? 1 : n / i];
      ans = (ll) ans * s1[i == 1 ? 1 : n / i] % mod;
    } 
    if (!p[i]) {
      ++s2[prod[i]];
      ans = (ll) ans * s2[prod[i]] % mod;
    }
  }
  cout << ans << "\n";
  return 0;
}