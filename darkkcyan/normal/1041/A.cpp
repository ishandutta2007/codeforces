#include <bits/stdc++.h>
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
  int n; cin >> n;
  int mina, maxa;
  cin >> mina; maxa = mina;
  rep(i, n - 1) {
    int u; cin >> u;
    mina = min(mina, u);
    maxa = max(maxa, u);
  }

  cout << (maxa - mina + 1) - n << endl;

  return 0;
}