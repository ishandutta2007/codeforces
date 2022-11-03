#include <bits/stdc++.h>
#define ll long long
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
#define dbg(a) cerr << #a << " = " << a << endl; 
#define forn(i, n) for (int i = 0; i < (n); ++i)
 
using namespace std;

int l, r;
 
int WW = 20;

int main(){
#ifdef LOCAL
  freopen("C_input.txt", "r", stdin);
  //freopen("C_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> l >> r;
  int add = l - 1;
  r -= add;

  cout << "YES\n";


  if (r == 1) {
    cout << "32 1\n1 32 " << 1 + add;
    return 0;
  }

  if (r == 2) {
    cout << "32 3\n1 32 " << 1 + add;
    cout << "1 2 1" << endl;
    cout << "2 32 " << 1 + add << endl;
    return 0;
  }

  int s = 1, t = 32;
  int dd = 30;
  vector<pair<pair<int, int>, int>> ed;

  r -= 2;
  add += 2;

  ed.pb(mp(mp(s, t), 1 + add - 2));
  ed.pb(mp(mp(s, 3), 1 + add - 2));
  ed.pb(mp(mp(3, t), 1));


  vector<int> pred = { t };

  for (int st = 0; st < WW; ++st) {
    int v = dd--;

    for (int to : pred) ed.pb(mp(mp(v, to), 1 << st));

    pred.pb(v);
  }

  int ex = 0;
  for (int v = 20; v >= 0; --v) if ((r >> v) & 1) {

    if (ex == 0) {

      ed.pb(mp(mp(s, 2), add - 1));

//      cout << v << ' ' << r << endl;

      for (int i = 0; i < v; ++i) ed.pb(mp(mp(2, pred[i + 1]), 1));

    } else {

  //    cout << ex << ' ' << v << ' ' << add << endl;

      ed.pb(mp(mp(s, pred[v + 1]), ex - (1 << v) + add));

    }

    ex ^= 1 << v;
  }

  ed.pb(mp(mp(s, 4), r + add - 1));
  ed.pb(mp(mp(4, t), 1));

  cout << 32 << ' ' << ed.size() << endl;
  for (auto [w, c] : ed) cout << w.x << ' ' << w.y << ' ' << c << endl;
}