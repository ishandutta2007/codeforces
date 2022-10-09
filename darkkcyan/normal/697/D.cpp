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
int n;
vector<int> children[maxn];
long double ans[maxn];
int subtreeSize[maxn];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 2; i <= n; ++i) {
      int p; cin >> p;
      children[p].push_back(i);
    }
    
    for (int i = n + 1; i-- > 0; ) {
      subtreeSize[i] = 1;
      for (auto f: children[i]) subtreeSize[i] += subtreeSize[f];
    }

    ans[1] = 1;
    rep1(i, n) {
      cout << fixed << setprecision(8) << ans[i] << ' ';
      clog << subtreeSize[i] << endl;
      for (auto f: children[i])
        ans[f] = ans[i] + 0.5 * (subtreeSize[i] - 1 - subtreeSize[f]) + 1;
    }

    return 0;
}