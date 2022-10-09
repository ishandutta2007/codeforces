#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define len(x) ((int)x.size())

bool isbeau(int x) {
  int t = 0;
  for (int g = x; ~g & 1; g >>= 1, ++t);
  clog << x << ' ' << t << endl;
  return ((1 << (t + 1))- 1) * (1 << (t)) == x;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  llong x; cin >> x;
  for (int t = x; t >= 1; --t) {
    if (x % t == 0 and isbeau(t)) {
      cout << t;
      break;
    }
  }

  return 0;
}