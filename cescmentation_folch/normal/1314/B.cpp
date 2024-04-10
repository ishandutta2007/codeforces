#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;

vpi fes(int mx, int my) {
  if (mx == 3 or my == 3) {
    return vpi(1,pi(3,3));
  }
  if (mx == my) {
    if (mx == 1) return vpi(1,pi(3,2));
    if (mx == 2) return vpi(1,pi(2,2));
    return vpi(1,pi(0,0));
  }
  if (mx and my) return vpi(1,pi(3,3));
  if (max(mx, my) == 2) return vpi(1,pi(2,2));
  return vpi({pi(1,1),pi(2,2)});
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  int N = (1<<(n-1));
  vvi V(N, vi(4,0));
  vi D(2*N, 0);
  for (int i = 0; i < k; ++i) {
    int x;
    cin >> x; --x;
    D[x] = 1;
  }
  for (int i = 0; i < N; ++i) {
    int x = 2*i;
    int y = 2*i + 1;
    if (D[x] and D[y]) {
      V[i][3] = 1;
    }
    else if (D[x] or D[y]) {
      V[i][1] = V[i][2] = 1;
    }
  }
  while (N > 1) {
    int nn = N/2;
    vvi V2(nn, vi(4,0));
    for (int i = 0; i < nn; ++i) {
      int x = 2*i;
      int y = 2*i + 1;
      for (int j1 = 0; j1 < 4; ++j1) {
        if (j1 and !V[x][j1]) continue;
        for (int j2 = 0; j2 < 4; ++j2) {
          if (j2 and !V[y][j2]) continue;
          auto tt = fes(j1, j2);
          for (auto s : tt) {
            V2[i][s.first] = max(V2[i][s.first], s.second + V[x][j1] + V[y][j2]);
          }
        }
      }
    }
    V = V2;
    N = nn;
  }
  int res = 0;
  for (int i = 0; i < 4; ++i) res = max(res, V[0][i]);
  if (k) ++res;
  cout << res << endl;
}