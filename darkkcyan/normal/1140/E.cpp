#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define all(x) x.begin(), x.end()

#define rem ((llong)998244353)

int n, k;
vector<int> group[2];

llong solve(vector<int>& a) {
  if (!len(a)) return 1;
  int last_num = k + 1;
  llong dp_eq = 1;
  llong dp_neq = 1;
  if (a[0] != -1) {
    dp_neq = 0;
    last_num = a[0];
  }

  rep1(f, len(a) - 1) {
    int i = a[f];
    if (i == -1) {
      tie(dp_eq, dp_neq) = make_tuple(
        (dp_neq * (k - 1)) % rem,
        (dp_neq * (k - 2) + dp_eq) % rem
      );
    } else {
      if (i == last_num) {
        dp_eq = dp_neq * (k - 1) % rem;
      } else {
        dp_eq = (dp_neq * (k - 2) + dp_eq) % rem;
      }
      dp_neq = 0;
      last_num = i;
    }
  }
  return (dp_eq + dp_neq * (k - 1)) % rem;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    rep(i, n) {
      int a; cin >> a;
      group[i & 1].push_back(a);
    }

    cout << (solve(group[0]) * solve(group[1])) % rem;

    return 0;
}