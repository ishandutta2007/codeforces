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

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<pair<int, int>> a(n);
    for (auto& i: a) cin >> i.xx >> i.yy;
    sort(a.begin(), a.end());

    int prev = -1;
    for (auto i: a) {
        if (i.yy < prev) prev = i.xx;
        else prev = i.yy;
    }
    cout << prev;

    return 0;
}