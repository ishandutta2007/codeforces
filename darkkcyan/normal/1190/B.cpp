#include <bits/stdc++.h>
using namespace std;
using namespace std::placeholders;

#define llong long long 
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define all(x) x.begin(), x.end()
// #define rand __rand
// mt19937 rand(chrono::system_clock::now().time_since_epoch().count());  // or mt19937_64

#define maxn 101010
llong n;
map<llong, int> cnt;

void winner(bool who) {
    cout << (who ? "cslnb" : "sjfnb");
    exit(0);
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    llong s = 0;
    rep(i, n) {
        llong u; cin >> u;
        cnt[u]++;
        s += u;
    }

    int cnt2 = 0;
    for (auto i = cnt.begin(); i != cnt.end(); ++i) {
        if (i->yy == 1) continue;
        if (i->yy > 2) winner(1);
        cnt2 ++;
        if (i != cnt.begin() and prev(i)->xx == i->xx - 1) winner(1);
        if (i->xx == 0) winner(1);
    }
    if (cnt2 > 1) winner(1);

    s -= n * (n - 1) / 2;
    winner(!(s & 1));

    return 0;
}