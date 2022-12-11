#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pi;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;

const int N = 1000000;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  vi P;
  vi V(N, 0);
  for (int i = 2; i < N; ++i) {
    if (!V[i]) {
      P.push_back(i);
      for (int j = 2*i; j < N; j += i) V[j] = 1;
    }
  }
  int n;
  cin >> n;
  vi A(n);
  for (auto& a : A) cin >> a;
  random_shuffle(A.begin(), A.end());
  int iter = 50;
  ll res = n;
  for (int cct = 0; cct < min(n,iter); ++cct) {
    ll s = A[cct];
    set<ll> F;
    for (ll x = max(1ll,s-1); x <= s+1; ++x) {
      ll y = x;
      for (auto p : P) {
        if (y%p == 0) F.insert(p);
        while (y%p == 0) y /= p;
      }
      if (y > 1) F.insert(y);
    }
    for (auto f : F) {
      ll rr = 0;
      for (auto a : A) {
        if (a < f) rr += f - a;
        else rr += min(a%f, f - a%f);
      }
      res = min(res, rr);
    }
  }
  cout << res << endl;
}