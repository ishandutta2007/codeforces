#include <bits/stdc++.h>
using namespace std;

#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair

using ll = long long;
using pii = pair<int, int>;
//#define int ll

const int MOD = 1000000007;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    deque<int> cur;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      int s;
      cin >> s;
      if (s == 1)
        cur.push_back(1);
      else {
        while (cur.size() && cur.back() + 1 != s)
          cur.pop_back();
        assert(cur.size());
        cur.back()++;
      }
      string z;
      for (int i : cur)
        z += to_string(i) + ".";
      z.pop_back();
      cout << z << '\n';
    }
  }
  return 0;
}