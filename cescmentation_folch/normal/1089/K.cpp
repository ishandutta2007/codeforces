#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;

const int N = 1010;
int D[N][N];
pi T[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int q;
  cin>> q;
  vpi V(q);
  for (int ii = 0; ii < q; ++ii) {
    char a;
    cin >> a;
    if (a == '+') {
      int t, d;
      cin >> t >> d;
      V[ii] = pi(t,d);
      int p = t/N;
      int tt = t%N;
      T[p].first += d;
      D[p][tt] = d;
      ll val = 0;
      for (int i = 0; i < N; ++i) {
        if (!D[p][i]) continue;
        if (val < i) val = i;
        val += D[p][i];
      }
      T[p].second = ll(p)*N + val; 
    }
    else if (a == '-') {
      int ind;
      cin >> ind;
      --ind;
      int t = V[ind].first;
      int d = V[ind].second;
      int p = t/N;
      int tt = t%N;
      T[p].first -= d;
      D[p][tt] = 0;
      ll val = 0;
      for (int i = 0; i < N; ++i) {
        if (!D[p][i]) continue;
        if (val < i) val = i;
        val += D[p][i];
      }
      T[p].second = ll(p)*N + val; 
    }
    else {
      int t;
      cin >> t;
      int p = t/N;
      int tt = t%N;
      ll val = 0;
      for (int i = 0; i < p; ++i) {
        val = max(val + T[i].first, T[i].second);
      }
      for (int i = 0; i <= tt; ++i) {
        if (val - p*N < i) val = i + p*N;
        val += D[p][i];
      }
      cout << val - t << '\n';

    }
  }
}