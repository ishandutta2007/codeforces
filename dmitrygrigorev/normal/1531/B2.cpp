#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int n;
  cin >> n;

  vector<pair<int, int> > v(n);
  for (auto &x : v) cin >> x.x >> x.y;

  map<int, int> mm;
  map<pair<int, int>, int> nn;

  ll ans = 0;

  for (auto x : v) {

    if (x.x > x.y) swap(x.x, x.y);
    mm[x.x]++;
    if (x.y != x.x) mm[x.y]++;

    nn[x]++;
  }

  for (auto p : mm) {
    ans += (ll) p.y * (p.y - 1) / 2;
  }

  for (auto p : nn) {
    if (p.x.x != p.x.y) ans -= (ll) p.y * (p.y - 1) / 2;
  }

  cout << ans;

}