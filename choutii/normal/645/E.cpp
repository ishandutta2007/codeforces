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

const int NX = 1001234 << 1, KX = 26 + 1;
const int mod = 1e9 + 7;

int n, m, k, last[KX], f[KX], g[KX]; char s[NX];

int main() {
  scanf("%d%d%s", &n, &k, s + 1); m = strlen(s + 1);
  
  for (int i = 1; i <= m; i++) {
    int sum = 1;
    for (int j = 0; j < k; j++)
      sum= (sum + f[j]) % mod;
    f[s[i] - 'a'] = sum;
  }
  
  for (int i = 1; i <= m; i++)
    g[s[i] - 'a'] = i;
  
  for (int i = 1; i <= n; i++) {
    int t = min_element(g, g + k) - g, u = 1;
    for (int j = 0; j < k; j++)
      (u += f[j]) %= mod;
    f[t] = u; g[t] = i + m;
  }
  
  int ans = 1;
  for (int i = 0; i < k; i++)
    (ans += f[i]) %= mod;
  cout << ans << "\n";
  return 0;
}