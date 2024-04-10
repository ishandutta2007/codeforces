#include <bits/stdc++.h>

using namespace std;

vector<double> Transition(vector<double> dp, double prob, int maxx) {
    int n = dp.size();
    vector<double> ndp(n, 0.);

    double rem = 1., sub = prob;
    for (int i = 1; i < maxx; ++i) {
        rem -= sub;
        sub *= 1. - prob;
    }

    double acc = 0;
    for (int i = 0; i < n; ++i) {
        if (i >= maxx) {
            acc -= sub * dp[i - maxx];
            ndp[i] = acc + dp[i - maxx] * rem;
        } else {
            ndp[i] = acc;
        }
        acc *= 1. - prob;
        acc += dp[i] * prob;
    }
    return ndp;
}

int main() {
    int n, t; cin >> n >> t;
    vector<double> dp(t + 1, 0.);
    dp[0] = 1.;

    double ans = 0;
    for (int i = 0; i < n; ++i) {
        double p; int maxx; 
        cin >> p >> maxx;
        dp = Transition(dp, p / 100., maxx);
        for (auto& x : dp)
            ans += x;
    }
    cout << fixed << setprecision(20) << ans << endl;

    return 0;    
}