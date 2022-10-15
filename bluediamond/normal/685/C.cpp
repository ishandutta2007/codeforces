#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll INF = (ll) 3e18 + 7;

struct Point {
  ll x, y, z;
};

struct T {
  ll mn = +INF;
  ll mx = -INF;

  void add(ll x) {
    mn = min(mn, x);
    mx = max(mx, x);
  }
};

ll dv(ll x) {
  if (x >= 0) return x / 2;
  return (x - 1) / 2;
}

int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
    freopen ("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE


  ll x, y, z;

  int Tests;
  cin >> Tests;
  for (int tc = 1; tc <= Tests; tc++) {
    int n;
    cin >> n;
    vector<Point> points(n);
    for (auto &p : points) {
      cin >> p.x >> p.y >> p.z;
    }
    function<bool(ll)> ok = [&] (ll limit) {
      T tsum, tx, ty, tz;
      for (auto &p : points) {
        /**
        abs(p.x - x) + abs(p.y - y) + abs(p.z - z) <= limit

        (x - p.x) + (y - p.y) + (z - p.z) <= limit ...

        + x + y + z <= limit + p.x + p.y + p.z
        - x + y + z <= limit - p.x + p.y + p.z
        + x - y + z <= limit + p.x - p.y + p.z
        + x + y - z <= limit + p.x + p.y - p.z

        - x - y - z <= limit - p.x - p.y - p.z
        + x - y - z <= limit + p.x - p.y - p.z
        - x + y - z <= limit - p.x + p.y - p.z
        - x - y + z <= limit - p.x - p.y + p.z

        **/

        ll sum = p.x + p.y + p.z;
        ll x = - p.x + p.y + p.z;
        ll y = + p.x - p.y + p.z;
        ll z = + p.x + p.y - p.z;

        tsum.add(sum);
        tx.add(x);
        ty.add(y);
        tz.add(z);
      }
      /**

        + x + y + z
        - x + y + z
        + x - y + z
        + x + y - z


        a = - x + y + z
        b = + x - y + z
        c = + x + y - z

        x + y + z = a + b + c

        x = (b + c) / 2
        y = (a + c) / 2
        z = (a + b) / 2
      **/


      for (ll r = 0; r <= 1; r++) {

        ll low_s = tsum.mx - limit, high_s = tsum.mn + limit;
        ll low_a = tx.mx - limit, high_a = tx.mn + limit;
        ll low_b = ty.mx - limit, high_b = ty.mn + limit;
        ll low_c = tz.mx - limit, high_c = tz.mn + limit;




        low_s -= 3 * r, high_s -= 3 * r;
        low_a -= r, high_a -= r;
        low_b -= r, high_b -= r;
        low_c -= r, high_c -= r;

        low_s = dv(low_s + 1), high_s = dv(high_s);
        low_a = dv(low_a + 1), high_a = dv(high_a);
        low_b = dv(low_b + 1), high_b = dv(high_b);
        low_c = dv(low_c + 1), high_c = dv(high_c);


        if (0) {
          cout << low_s << " " << high_s << "\n";
          cout << low_a << " " << high_a << "\n";
          cout << low_b << " " << high_b << "\n";
          cout << low_c << " " << high_c << "\n";
          cout << " --------------------------------------- \n";
        }

        if (low_s > high_s) continue;
        if (low_a > high_a) continue;
        if (low_b > high_b) continue;
        if (low_c > high_c) continue;

        /**

        low_a <= 2 * a + r <= high_a
        low_b <= 2 * b + r <= high_c
        low_c <= 2 * c + r <= high_c


        2 * (a + b + c) + 3 * r <=

        **/


        ll l1 = low_a + low_b + low_c, r1 = high_a + high_b + high_c;
        ll l2 = low_s, r2 = high_s;

        if (r1 < l2 || r2 < l1) {
          continue;
        }


        ll a = low_a, b = low_b, c = low_c;
        ll need = low_s - (a + b + c);


        if (need > 0) {

          ll take;
          take = min(high_a - a, need); need -= take; a += take;
          take = min(high_b - b, need); need -= take; b += take;
          take = min(high_c - c, need); need -= take; c += take;
        }

        a = 2 * a + r;
        b = 2 * b + r;
        c = 2 * c + r;


        x = (b + c) / 2;
        y = (a + c) / 2;
        z = (a + b) / 2;

        return 1;
      }
      return 0;
    };
    ll low = 0, high = (ll) 3e18 + 7, sol = -1;
    while (low <= high) {
      ll mid = (low + high) / 2;
      if (ok(mid)) {
        sol = mid;
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    ok(sol);
    assert(ok(sol));
    cout << x << " " << y << " " << z << "\n";
  }


  return 0;
}