#include<bits/stdc++.h>
using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  string s; cin >> s;
  int a[len(s)] = {0};
  rep(i, len(s)) {
    if (s[i] == '.') continue;
    a[i] |= 1 << (s[i] - 'A');
    if (i) a[i - 1] |= 1 << (s[i] - 'A');
    if (i < len(s) - 1) a[i + 1] |= 1 << (s[i] - 'A');
  }
  rep(i, len(s)) {
    if (a[i] == 7) {
      cout << "Yes";
      return 0;
    }
  }
  cout << "No";

  return 0;
}