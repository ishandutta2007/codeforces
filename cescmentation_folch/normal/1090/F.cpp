#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pi;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ll n;
  cin >> n;
  ll V1;
  cout << "? 1 2 3" << endl;
  cin >> V1;
  ll mival;
  ll a = 1, b = 2, c = 3;
  bool pot = false;
  ll v1,v2, valor;
  for (ll i = 4; i <= n; ++i) {
    ll d = i;
    ll V2,V3,V4;
    cout << "? " << a << ' ' << b << ' ' << d << endl;
    cin >> V2;
    cout << "? " << a << ' ' << c << ' ' << d << endl;
    cin >> V3;
    cout << "? " << b << ' ' << c << ' ' << d << endl;
    cin >> V4;
    ll ma = max({V1,V2,V3,V4});
    ll mi = min({V1,V2,V3,V4});
    if (mi == ma) {
      pot = true;
      ll e = 1;
      while (e == a or e == b or e == c or e == d) ++e;
      assert(e <= n);
      ll maxi, mini;
      ll val[6];
      cout << "? " << e << ' ' << a << ' ' << b << endl;
      cin >> val[0];
      cout << "? " << e << ' ' << a << ' ' << c << endl;
      cin >> val[1];
      cout << "? " << e << ' ' << a << ' ' << d << endl;
      cin >> val[2];
      cout << "? " << e << ' ' << b << ' ' << c << endl;
      cin >> val[3];
      cout << "? " << e << ' ' << b << ' ' << d << endl;
      cin >> val[4];
      cout << "? " << e << ' ' << c << ' ' << d << endl;
      cin >> val[5];
      maxi = mini = val[0];
      for (ll w = 1; w < 6; ++w) {
        mini = min(mini, val[w]);
        maxi = max(maxi, val[w]);
      }

      ll xy = ma;
      ll yz = maxi;
      ll xz = mini;
      //cerr << xy << ' '<< xz << ' ' << yz << endl;
      ll x = (xz + xy - yz)/2;
      ll y = (yz + xy - xz)/2;
      ll z = (xz + yz - xy)/2;
      //cerr << x << ' ' << y << ' ' << z << endl;
      if (y > z) {
        valor = x;
        if (val[0] == xz) {
          v1 = a;
          v2 = b;
        }
        else if (val[1] == xz) {
          v1 = a;
          v2 = c;
        }
        else if (val[2] == xz) {
          v1 = a;
          v2 = d;
        }
        else if (val[3] == xz) {
          v1 = b;
          v2 = c;
        }
        else if (val[4] == xz) {
          v1 = b;
          v2 = d;
        }
        else {
          v1 = c;
          v2 = d;
        }
      }
      else {
        valor = y;
        if (val[0] == yz) {
          v1 = a;
          v2 = b;
        }
        else if (val[1] == yz) {
          v1 = a;
          v2 = c;
        }
        else if (val[2] == yz) {
          v1 = a;
          v2 = d;
        }
        else if (val[3] == yz) {
          v1 = b;
          v2 = c;
        }
        else if (val[4] == yz) {
          v1 = b;
          v2 = d;
        }
        else {
          v1 = c;
          v2 = d;
        }
      }
      break;
    }
    if (V1 == ma) mival = d;
    else if (V2 == ma) mival = c;
    else if (V3 == ma) mival = b;
    else mival = a;
    if (V2 == mi) swap(c,d);
    else if (V3 == mi) swap(b,d);
    else if (V4 == mi) swap(a,d);
    V1 = mi;
    //cerr << "demoment " << a << ' ' << b << ' ' << c << " (" << mival << ")" << endl;
  }
  vi V(n+1,0);
  if (pot) {
    assert(v1 > 0 and v1 <= n and v2 > 0 and v2 <= n);
    for (ll i = 1; i <= n; ++i) {
      if (i == v1 or i == v2) V[i] = valor;
      else {
        cout << "? " << i << ' ' << v1 << ' ' << v2 << endl;
        cin >> V[i];
        V[i] -= valor;
      }
    }
    cout << "!";
    for (ll i = 1; i <= n; ++i) cout << ' ' << V[i];
    cout << endl;
  }
  else {
    if (b == mival) swap(b,a);
    else if (c == mival) swap(c,a);
    ll val1 = -1;
    ll val2 = -1;
    for (ll i = 1; i <= n; ++i) {
      if (i == a or i == b or i == c) continue;
      ll k;
      cout << "? " << a << ' ' << b << ' ' << i << endl;
      cin >> k;
      V[i] = k - V1;
      if (val1 == -1 or V[val1] <= V[i]) {
        val2 = val1;
        val1 = i;
      }
      else if (val2 == -1 or V[val2] < V[i]) val2 = i;
    }
    assert(val1 != -1 and val2 != -1);
    ll Va,Vb,Vc;
    cout << "? " << a << ' ' << val1 << ' ' << val2 << endl;
    cin >> Va;
    cout << "? " << b << ' ' << val1 << ' ' << val2 << endl;
    cin >> Vb;
    cout << "? " << c << ' ' << val1 << ' ' << val2 << endl;
    cin >> Vc;
    ll x = (max({Va,Vb,Vc}) - V[val1]);
    //cerr << x << endl;
    assert(x%2 == 0);
    x /= 2;
    V[a] = Va - V[val1] -2*x;
    V[b] = Vb - V[val1] -2*x;
    V[c] = Vc - V[val1] -2*x;
    cout << "!";
    for (ll i = 1; i <= n; ++i) cout << ' ' << V[i] + x;
    cout << endl;
  }
}