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
 
int n;
int a[111111];
 
int main(){
#ifdef LOCAL
  freopen("C_input.txt", "r", stdin);
  //freopen("C_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);
 
  cin >> n;
 
  vector<pair<int, int> > t;
 
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (t.size() == 0 || t.back().x != a[i]) {
      t.pb(mp(a[i], 1));
    } else {
      t.back().y++;
    }
  }
 
  int res = t.size();
 
  int last = -1;
 
  vector<int> d;
 
  for (int i = 0; i < t.size(); ++i) {
    if (t[i].y > 1) d.pb(i);
  }
 
 
  res += d.size() > 0;
 
  for (int i = 0; i + 1 < d.size(); ++i) {
    int w1 = d[i], w2 = d[i + 1];
 
    if (t[w1].x != t[w2].x) {
      ++ res;
    } else {

      if ((w2 - w1) % 2 == 1) ++res; else {

        for (int j = w1 + 2; j + 2 <= w2; j += 2) if (t[j].x != t[w1].x) {
          ++res;
          break;
        }

      }
    }
  }
 
 
  cout << res;
 
}