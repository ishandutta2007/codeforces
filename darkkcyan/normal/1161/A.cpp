#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define all(x) x.begin(), x.end()

#define maxn 101010
int n, m;
int x[maxn];
vector<int> pos[maxn];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    rep(i, m) cin >> x[i];
    rep(i, m) pos[x[i]].push_back(i);
    int ans = 0;
    rep1(i, n) {
      if (!len(pos[i])) ++ans;
      for (int f: {i - 1, i + 1}) {
        if (f <= 0 || f > n) continue;
        if (!len(pos[i])) ++ans;
        else if (!len(pos[f])) ++ans;
        else if (upper_bound(pos[f].begin(), pos[f].end(), pos[i][0]) == pos[f].end()) ++ans;
      }
    }
    cout << ans;

    return 0;
}