#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define len(x) ((int)x.size())

#define maxn 101010
bool mark[maxn];
int cnt = 0;
int n;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  n *= 2;
  int ans = 0;
  while (n--) {
    int u; cin >> u;
    if (mark[u]) --cnt;
    else ++cnt;
    mark[u] ^= 1;
    ans = max(ans, cnt);
  }
  cout << ans;

  return 0;
}