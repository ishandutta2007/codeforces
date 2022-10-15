#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll INF = (ll) 1e18;
const int N = (int) 2e5 + 7;
int n;

ll dp[10];
ll new_dp[10];

void upd_dp(vector <ll> keks) {
        for (int cur = 0; cur < 10; cur++) {
                int j = cur;
                ll value = dp[cur];
                for (auto &x : keks) {
                        j++;
                        if (j >= 10) j -= 10;
                        if (j == 0) {
                                value += 2 * x;
                        } else {
                                value += x;
                        }
                }
                new_dp[j] = max(new_dp[j], value);
        }
}

int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);

        for (int i = 0; i < 10; i++) {
                dp[i] = -INF;
                new_dp[i] = -INF;
        }
        dp[0] = 0LL;

        cin >> n;
        for (int it = 1; it <= n; it++) {
                int ln;
                cin >> ln;
                vector <vector <ll>> cc(4);
                for (int i = 1; i <= ln; i++) {
                        int b;
                        ll x;
                        cin >> b >> x;
                        cc[b].push_back(x);
                }
                sort(cc[1].rbegin(), cc[1].rend());
                sort(cc[2].rbegin(), cc[2].rend());
                sort(cc[3].rbegin(), cc[3].rend());
                int sz1 = (int) cc[1].size();
                int sz2 = (int) cc[2].size();
                int sz3 = (int) cc[3].size();
              //  cout << " : " << it << "\n";
                for (int a = 0; a * 1 <= 3 && a <= sz1; a++) {
                        for (int b = 0; a * 1 + b * 2 <= 3 && b <= sz2; b++) {
                                for (int c = 0; a * 1 + b * 2 + c * 3 <= 3 && c <= sz3; c++) {
                                        vector <ll> keks;
                                        for (int i = 0; i < a; i++) keks.push_back(cc[1][i]);
                                        for (int i = 0; i < b; i++) keks.push_back(cc[2][i]);
                                        for (int i = 0; i < c; i++) keks.push_back(cc[3][i]);
                                        sort(keks.begin(), keks.end());
                                        upd_dp(keks);
                                        while (next_permutation(keks.begin(), keks.end())) {
                                                upd_dp(keks);
                                        }
                                }
                        }
                }
                for (int i = 0; i < 10; i++) {
                        dp[i] = new_dp[i];
                        new_dp[i] = -INF;
                }
        }

        ll mex = -INF;
        for (int i = 0; i < 10; i++) {
                mex = max(mex, dp[i]);
        }

        cout << mex << "\n";

        return 0;
}
/**

**/