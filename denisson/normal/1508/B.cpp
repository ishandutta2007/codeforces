#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

ll n, k;

void solve() {
  cin >> n >> k;

  if (((ll)1 << min(n - 1, (ll)61)) < k) {
    cout << "-1\n";
    return;
  }

  vector<int> res;

  int last = 1;
  int ost_len = n;
  while (ost_len > 0) {
    if (ost_len == 1) {
      res.pb(last);
      break;
    }
    int cur = last;

   // cout << "===" << last << ' ' << ost_len << endl;

    while (ost_len > 1) {
      ll cnt = ((ll)1 << min(ost_len - 2, 61));
      if (cnt < k) {
        k -= cnt;
        ++cur;
        --ost_len;
      } else break;
    }
    --ost_len;
  //  cout << "ASDSADSADAS " << cur << ' ' << last << ' ' << k << endl;
    for (int i = cur; i >= last; --i) res.pb(i);
    last = cur + 1;
  }

  for (int x : res) cout << x << ' ';
  cout << "\n";
}

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int tt;cin >> tt;
  while (tt--) {
    solve();
  }
}