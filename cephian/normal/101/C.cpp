#include <iostream>

using namespace std;
typedef long long ll;

ll det(ll a, ll b, ll c, ll d) {
  return a*d - b*c;
}

ll x[3],y[3];

int main() {
  ios::sync_with_stdio(0);
  for(int i = 0; i < 3; ++i) cin >> x[i] >> y[i];
  for(int i = 0; i < 4; ++i) {
    swap(x[0], y[0]);
    y[0] = -y[0];
    ll a = x[1] - x[0];
    ll b = y[1] - y[0];
    ll dt = det(x[2], y[2], y[2], -x[2]);
    ll d1 = det(a, y[2], b, -x[2]);
    ll d2 = det(x[2], a, y[2], b);
    if(dt == 0) {
      if(a == 0 && b == 0) {
        cout << "YES\n";
        return 0;
      }
    } else {
      if(d1%dt == 0 && d2%dt == 0) {
        cout << "YES\n";
        return 0;
      }
    }
  }
  cout << "NO\n";
  return 0;
}