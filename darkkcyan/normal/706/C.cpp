#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#define cin fin
#define cout fout
ifstream cin("inp.txt");
ofstream cout("out.txt");
#endif

#define long long long
#define pii pair<int, int>
#define pll pair<long, long>

#define ve vector
#define vi ve<int>
#define vl ve<long>

#define sz(v) ((int) v.size())
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define xx first
#define yy second
#define mp make_pair
#define pb push_back

#define f0(i, a, b) for (i = a; i < b; ++i)
#define f1(i, a, b) for (i = a; i <= b; ++i)

int n;
vi cost;
ve<pll> dp;
string a, b;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int i, f, g;

    cin >> n;
    cost.resize(n);
    f0 (i, 0, n) cin >> cost[i];

    cin >> ws >> a;
    dp.resize(n, mp(LLONG_MAX, LLONG_MAX));
    dp[0] = mp(0, cost[0]);
    f0 (i, 1, n) {
        cin >> ws >> b;

        #define lc lexicographical_compare
        if (!lc(all(b), all(a))) dp[i].xx = min(dp[i].xx, dp[i - 1].xx);
        if (!lc(all(b), rall(a))) dp[i].xx = min(dp[i].xx, dp[i - 1].yy);

        if (!lc(rall(b), all(a))) dp[i].yy = min(dp[i].yy, dp[i - 1].xx);
        if (!lc(rall(b), rall(a))) dp[i].yy = min(dp[i].yy, dp[i - 1].yy);
        if (dp[i].yy != LLONG_MAX) dp[i].yy += cost[i];

        if (dp[i] == mp(LLONG_MAX, LLONG_MAX)) break;
        a = b;
    }

//    f0 (i, 0, n) clog << dp[i].xx << ':' << dp[i].yy << ' ';

    if (dp[n - 1] == mp(LLONG_MAX, LLONG_MAX)) {
        cout << -1;
    } else {
        cout << min(dp[n - 1].xx, dp[n - 1].yy);
    }

    return 0;
}