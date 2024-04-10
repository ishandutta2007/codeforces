#include<bits/stdc++.h>

using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define sz(v) ((int)v.size())
#define rep(i,n) for (int i = -1; ++i < n; )

int n;

vector<int> t;
set<int> se;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  int ans = 0;
  int x = 1;
  rep(step, 2 * n) {
    string s; cin >> s;
    if (s[0] == 'r') {
      if (sz(t) == 0) {
        se.erase(se.begin());
      } else if (t.back() == x) t.pop_back();
      else {
        for (auto i: t) se.insert(i);
        t.clear();
        se.erase(se.begin());
        ++ans;
      }
      ++x;
    } else {
      int num; cin >> num;
      t.push_back(num);
    }
  }
  cout << ans;

  return 0;
}