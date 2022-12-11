#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef ll llint;
typedef vector<llint> vi;
typedef vector<vi> vvi;
typedef pair<llint, llint> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;

ll mod = 998244353;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vi C(n+1);
  for (int i = 1; i <= n; ++i) cin >> C[i];
  vvi D(n+2, vi(n+2, 1));
  for (int l = 2; l <= n; ++l) {
    for (int i = 1; i +l-1 <= n; ++i) {
      int mi = i;
      for (int j = 0; j < l; ++j) {
        if (C[mi] > C[j+i]) mi = j+i;
      }
      ll left = 0;
      for (int j = i; j <= mi; ++j) {
        left = (left + D[i][j-1]*D[j][mi-1])%mod;
      }
      ll right = 0;
      for (int j = mi; j < i+l; ++j) {
        right = (right + D[mi+1][j]*D[j+1][i+l-1])%mod;
      }
      D[i][i+l-1] = left*right%mod;
    }
  }
  cout << D[1][n] << endl;

}