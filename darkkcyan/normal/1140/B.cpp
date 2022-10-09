#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define all(x) x.begin(), x.end()

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
      int n; cin >> n;
      string s; cin >> s;
      if (s[0] == '>' || s.back() == '<') cout << "0\n";
      else {
        int u = 0, v = 0;
        for (; u < n and s[u] == '<'; ++u);
        for (; v < n and s[n - v - 1] == '>'; ++v);
        cout << min(u, v) << '\n';
      }
    }

    return 0;
}