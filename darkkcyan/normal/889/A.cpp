#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++i < n; )
#define rep1(i,n) for (int i = 0; i++ < n; )

#define maxn 201010
int n;
int cnt[maxn] = {0};

int main() {
  srand(time(0));
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin >> n;
  rep1(i, n) {
    int u; cin >> u;
    cnt[u]++;
  }

  int ans = 0;
  rep1(i, n) if (!cnt[i]) ++ans;
  cout << ans;

  return 0;
}