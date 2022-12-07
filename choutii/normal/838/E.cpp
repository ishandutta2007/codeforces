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

const int NX = 5005;

int n, x[NX], y[NX]; 
double f[2][NX], g[2][NX];

double dis(int i, int j) {
  double dx = x[i] - x[j];
  double dy = y[i] - y[j];
  return sqrt(dx * dx + dy * dy);
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d%d", x + i, y + i);
  
  for (int i = 0; i < n; i++)
    x[i + n] = x[i], 
    y[i + n] = y[i];
  double ans = 0;
  for (int l = 1; l < n; l++) {
    for (int i = 0; i + l < n * 2; i++) {
      int j = i + l;
      f[1][i] = max(f[0][i + 1] + dis(i, i + 1), g[0][i + 1] + dis(i, j));
      g[1][i] = max(f[0][i] + dis(i, j), g[0][i] + dis(j - 1, j));
      if(l + 1 == n) {
        cmax(ans, f[1][i]);
        cmax(ans, f[0][i]);        
      }
    }
    swap(f[0], f[1]);
    swap(g[0], g[1]);
  }
  printf("%.10lf\n", ans);
  return 0;
}