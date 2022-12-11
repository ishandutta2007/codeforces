#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll INF = 1e18;

int main() {
  ll f, t, t0;
  cin >> f >> t >> t0;
  ll a1, p1, t1;
  cin >> a1 >> t1 >> p1;
  ll a2, p2, t2;
  cin >> a2>> t2 >> p2;

  ll res = INF;
  for (int i = 0; i <= f; ++i) {
    ll preu = (i + a1 - 1)/a1;
    preu *= p1;
    ll qued = f - i;
    ll pred = qued*t0 + i*t1;
    if (t < pred and t2 < t0) {
      ll kk = pred-t;
      ll tt = t0 - t2;
      ll nes = (kk + tt - 1)/tt;
      nes = (nes + a2 - 1)/a2;
      if (nes*a2 > qued) continue;
      preu += nes*p2;
      res = min(res, preu);
    }
    else if (t >= pred) res = min(res, preu);
  }
  for (int i = 0; i <= f; ++i) {
    ll preu = (i + a2 - 1)/a2;
    preu *= p2;
    ll qued = f - i;
    ll pred = qued*t0 + i*t2;
    if (t < pred and t1 < t0) {
      ll kk = pred-t;
      ll tt = t0 - t1;
      ll nes = (kk + tt - 1)/tt;
      nes = (nes + a1 - 1)/a1;
      if (nes*a1 > qued) continue;
      preu += nes*p1;
      res = min(res, preu);
    }
    else if (t >= pred) res = min(res, preu);
  }

  if (res == INF) cout << -1 << endl;
  else cout << res << endl;
}