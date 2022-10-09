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
    int n; cin >> n;
    int cnt[3] = {0,0 , 0};
    rep(i, n) {
      int u; cin >> u;
      cnt[u]++;
    }
    if (cnt[1] == 0) rep(i, n) cout << "2 ";
    else if (cnt[2] == 0) rep(i, n) cout << "1 ";
    else { 
      cout << "2 1 ";
      rep(i, cnt[2] - 1) cout << "2 ";
      rep(i, cnt[1] - 1) cout << "1 ";
    }

    return 0;
}