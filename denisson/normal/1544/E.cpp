#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;


void solve() {
  map<char, int> was;
  string s;
  cin >> s;
  for (char c : s) was[c]++;
  vector<pair<char, int>> t;
  for (auto c : was) t.pb(c);
  if (t.size() == 1) {
    cout << s << "\n";
    return;
  }
  int v = -1;
  for (int i = 0; i < t.size(); ++i) if (t[i].y == 1) {
    v = i;
    break;
  }
  if (v != -1) {
    cout << t[v].x;
    for (int i = 0; i < t.size(); ++i) if (i != v) {
      for (int j = 0; j < t[i].y; ++j) cout << t[i].x;
    }
  } else {

  //  cout << t[0].x << ' ' << t[0].y << endl;

    int sum = (int)s.size() - (t[0].y) - (t[0].y - 2);

  //  cout << sum << endl;

    if (sum >= 0) {
      cout << t[0].x << t[0].x;
      int ost = t[0].y - 2;
      for (int i = 1; i < t.size(); ++i) {
        for (int j = 0; j < t[i].y; ++j) {
          cout << t[i].x;
          if (ost > 0) cout << t[0].x, --ost;
        }
      }
    } else {

      if (t.size() == 2) {
        cout << t[0].x;
        for (int j = 0; j < t[1].y; ++j) cout << t[1].x;
        for (int j = 0; j < t[0].y - 1; ++j) cout << t[0].x;
      } else {

        cout << t[0].x << t[1].x;
        for (int j = 0; j + 1 < t[0].y; ++j) cout << t[0].x;

          cout << t[2].x;

        for (int j = 0; j + 1 < t[1].y; ++j) cout << t[1].x;

        for (int j = 0; j + 1 < t[2].y; ++j) cout << t[2].x;

        for (int i = 3; i < t.size(); ++i) if (i != v) {
          for (int j = 0; j < t[i].y; ++j) cout << t[i].x;
        }

      }



    }
  }
    cout << "\n";
}

int main(){
#ifdef LOCAL
	freopen("F_input.txt", "r", stdin);
	//freopen("F_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
}