#include <iostream>

using namespace std;

int n, t[200000], dp[200000], li;

int binsearch(int l, int r, int x) {
    if (l == r) return l;
    int m = (l+r) / 2;
    if (t[m] > x) return binsearch(l, m, x);
    else return binsearch(m+1, r, x);
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> t[i];
    }
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i-1] + 20;
        li = binsearch(1, i, t[i] - 90);
        dp[i] = min(dp[i], dp[li-1] + 50);
        li = binsearch(1, i, t[i] - 1440);
        dp[i] = min(dp[i], dp[li-1] + 120);
    }
    for (int i = 1; i <= n; ++i) {
        cout << dp[i] - dp[i-1] << endl;
    }
    return 0;
}