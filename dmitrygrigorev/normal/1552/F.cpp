#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int mod = 998244353;

void add(int& a, int b) {
  a += b;
  if (a >= mod) a -= mod;
  if (a < 0) a += mod;
}

int mult(int a, int b) {
  return a * (ll)b % mod;
}

int bp(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = mult(res, a);
    a = mult(a, a);
    b >>= 1;
  }
  return res;
}

int main(){
#ifdef LOCAL
	freopen("F_input.txt", "r", stdin);
	//freopen("F_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  vector<pair<int, int> > events;
  int n;
  cin >> n;

  vector<bool> active(n, false);

  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    events.pb(mp(x, i));
    events.pb(mp(y, i));
    int w;
    cin >> w;

    if (w == 1) active[i] = 1;
  }

  vector<int> kek(n, -1);

  sort(all(events), greater<pair<int, int> > ());
  int ans = 1;

  int jumps = active[events[0].y];
  kek[events[0].y] = jumps;

  for (int i = 1; i < 2*n; ++i) {

    int delta = (events[i-1].x - events[i].x) % mod;
    add(ans, mult(delta, jumps + 1));

    if (kek[events[i].y] != -1) {
      add(jumps, -kek[events[i].y]);
    }

    else {
      if (active[events[i].y]) {
        int tut = jumps + 1;
        add(jumps, tut);
        kek[events[i].y] = tut;
      }
      else {
        int tut = jumps;
        add(jumps, tut);
        kek[events[i].y] = tut;
      }
    }

  }

  add(ans, events.back().x);
  cout << ans;

}