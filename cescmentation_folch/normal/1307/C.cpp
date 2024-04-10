#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef int llint;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<llint, llint> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string a;
  cin >> a;
  int n = (int)a.size();
  ll res = 1;
  vi V(26,0);
  vvi R(26, vi(26,0));
  for (int i = 0; i < n; ++i) {
    int l = a[i] - 'a';
    for (int j = 0; j < 26; ++j) {
      R[j][l] += V[j];
    }
    ++V[l];
  }
  for (int i = 0; i < 26; ++i) {
    res = max(res, V[i]);
    for (int j = 0; j < 26; ++j) {
      res = max(res, R[i][j]);
    }
  }
  cout << res << '\n';
}