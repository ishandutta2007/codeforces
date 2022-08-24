#include <bits/stdc++.h>
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int N = 100007;
int tlast[N][2];

main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int n, m;
  cin >> n >> m;

  multiset<pair<int, int> > l, r;
  l.insert(mp(0, -1));
  r.insert(mp(0, -1));

  int last = -1;

  for (int i = 0; i < n; ++i) {
    int k;
    cin >> k;

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    bool ll = (l.size() > 0);
    bool rr = (r.size() > 0);

    if (k < a || k > b) {
      r.clear();
      tlast[i][0] = -1;
    }
    else {
      while (r.size()) {
        auto el = (*r.begin()).x;
        if (el < c) r.erase(r.begin());
        else break;
      }

      while (r.size()) {
        auto it = r.end();
        it--;

        auto el = (*it).x;
        if (el > d) r.erase(it);
        else break;
      }

      if (ll && (last >= c && last <= d) && last != -1) {
        r.insert(mp(last, i-1));
      }
      if (!r.size()) tlast[i][0] = -1;
      else {
        tlast[i][0] = (*r.begin()).y;
      }
    }


    if (k < c || k > d) {
      l.clear();
      tlast[i][1] = -1;
    }
    else {
      while (l.size()) {
        auto el = (*l.begin()).x;
        if (el < a) l.erase(l.begin());
        else break;
      }

      while (l.size()) {
        auto it = l.end();
        it--;

        auto el = (*it).x;
        if (el > b) l.erase(it);
        else break;
      }

      if (rr && (last >= a && last <= b) && last != -1) {
        l.insert(mp(last, i-1));
      }

      if (!l.size()) tlast[i][1] = -1;
      else {
        tlast[i][1] = (*l.begin()).y;
      }
    }

    last = k;
    if (!l.size() && !r.size()) {
      cout << "No\n";
      exit(0);
    }

  }

  cout << "Yes\n";
  vector<int> ans(n, 0);

  int a = n-1, b = 0;
  if (tlast[a][b] == -1) b = 1;

  while (a >= 0) {
    int Q = tlast[a][b];
    while (a > Q) {
      ans[a--] = b;
    }
    b ^= 1;
  }

  for (auto x : ans) cout << x << " ";




}