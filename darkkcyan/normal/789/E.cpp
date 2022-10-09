#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define all(x) x.begin(), x.end()

#define maxk 1001
#define maxval (1000100 * 2)
#define zero (maxval / 2)
int n, k;
bool has[maxk];
vector<int> edges;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;

    rep(i, k) {
      int u; cin >> u;
      has[u] = 1;
    }

    bool has_sign[3];
    rep(i, maxk) if (has[i]) {
      edges.push_back(i - n);
      has_sign[edges.back() < 0 ? 0 : 1 + (edges.back() > 0)] = 1;
    }
    if (has_sign[1]) {
      cout << 1;
      return 0;
    }
    if (!has_sign[0] or !has_sign[2]) {
      cout << -1;
      return 0;
    }

    bitset<maxval> cur;
    cur[zero] = 1;
    rep1(i, maxk) {
      bitset<maxval> new_mask;
      for (auto e: edges) new_mask |= e >= 0 ? cur << e : cur >> (-e);
      if (new_mask[zero]) {
        cout << i;
        return 0;
      }
      cur = move(new_mask);
    }
    assert(false);

    return 0;
}