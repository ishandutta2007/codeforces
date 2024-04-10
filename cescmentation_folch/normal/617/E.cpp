#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

struct que {
  ll arr;
  ll l;
  ll r;
  ll idx;
};

bool comp(que a, que b) {
  if (a.arr != b.arr) return a.arr < b.arr;
  if (a.r != b.r) return a.r < b.r;
  return a.l < b.l;
}

typedef vector<que> vq;

const ll N = 4e6;
const ll sN = 350;

ll F[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ll n, m, k;
  cin >> n >> m >> k;
  ll A[n + 1];
  A[0] = 0;
  for (ll i = 1; i <= n; ++i) { 
    cin >> A[i];
    A[i] ^= A[i - 1];
  }
  ll R[m];
  vq V(m);
  for (ll i = 0; i < m; ++i) {
    cin >> V[i].l >> V[i].r;
    V[i].l--;
    V[i].idx = i;
    V[i].arr = V[i].l/sN;
  }
  sort(V.begin(), V.end(), comp);
  ll res = 0;
  ll in = 0;
  ll out = -1;
  for (ll i = 0; i < m; ++i) {
//     cerr << res << endl;
    while (out < V[i].r) {
      ++out;
      res += F[A[out] ^ k];
      ++F[A[out]];
    }
//     cerr << res << endl;
    while (out > V[i].r) {
      --F[A[out]];
      res -= F[A[out] ^ k];
      --out;
    }
//     cerr << res << endl;
    while (in < V[i].l) {
      --F[A[in]];
      res -= F[A[in] ^ k];
      ++in;
    }
//     cerr << res << endl;
    while (in > V[i].l) {
      --in;
      res += F[A[in] ^ k];
      ++F[A[in]];
    }
//     cerr << res << endl << endl;
    R[V[i].idx] = res;
  }
  for(ll i = 0; i < m; ++i) cout << R[i] << endl;
}