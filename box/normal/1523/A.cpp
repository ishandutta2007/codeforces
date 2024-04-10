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
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    m = min(m, n + 1);
    while (m--) {
      string x;
      for (int i = 0; i < n; i++) {
        if (s[i] == '1')
          x += '1';
        else {
          int c1 = i ? (s[i - 1] == '1') : 0;
          int c2 = (i != n - 1) ? (s[i + 1] == '1') : 0;
          if (c1 ^ c2)
            x += '1';
          else
            x += '0';
        }
      }
      s = x;
    }
    cout << s << endl;
  }
}