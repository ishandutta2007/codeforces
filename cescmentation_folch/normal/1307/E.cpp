#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef int llint;
typedef vector<llint> vi;
typedef vector<vi> vvi;
typedef pair<llint, llint> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vi V(n);
  for (int i= 0; i < n; ++i) {
    cin >> V[i];
    --V[i];
  }
  vvi A(n, vi(n+1, 0));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) A[j][i+1] = A[j][i];
    A[V[i]][i+1]++;
  }
  vvi R(n);
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin>> x >> y;
    --x;
    R[x].push_back(y);
  }
  for (int i= 0; i < n; ++i) sort(R[i].begin(), R[i].end());
  int res = 0;
  ll num = 1;
  ll mod = 1e9+7;
  for (int dif = 0; dif <= n; ++dif) {
    int val = -1;
    int acum = 0;
    if (dif) {
      val = V[dif-1];
      acum = A[val][dif];
      bool existe = false;
      for (auto x : R[val]) {
        if (x == acum) {
          existe = true;
          break;
        }
      }
      if (!existe) continue;
    }
    int sres = 0;
    ll snum = 1;
    for (int v = 0; v < n; ++v) {
      if (v == val) {
        ll sum = 0;
        for (auto x : R[v]) {
          if (x != acum and acum + x <= A[v][n]) ++sum;
        }
        if (sum == 0) sres += 1;
        else {
          sres += 2;
          snum = (snum*sum)%mod;
        }
      }
      else {
        ll ind1 = 0;
        ll ind2 = 0;
        while (ind1 < (int)R[v].size() and R[v][ind1] <= A[v][dif]) ++ind1;
        while (ind2 < (int)R[v].size() and R[v][ind2] <= A[v][n] - A[v][dif]) ++ind2;
        if (ind1 < ind2) swap(ind1, ind2);
        if (ind2 and ind1 > 1) {
          sres += 2;
          snum = (snum*ind2*(ind1-1))%mod;
        }
        else if (ind2) {
          sres += 1;
          snum = (snum*(ind2 + ind1))%mod;
        }
        else if(ind1) {
          sres += 1;
          snum = (snum*ind1)%mod;
        }
      }
    }
    if (res == sres and res) {
      num = (num + snum)%mod;
    }
    else if (res < sres) {
      res = sres;
      num = snum;
    }
  }
  cout << res << ' ' << num << '\n';
}