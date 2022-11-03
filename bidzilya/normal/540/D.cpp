#include <bits/stdc++.h>
using namespace std;

const int kMaxN = 100;

double dp[kMaxN + 1][kMaxN + 1][kMaxN + 1];
bool f[kMaxN + 1][kMaxN + 1][kMaxN + 1];
int R, C, P;

int C2(int n)
{
    return n * (n - 1) / 2;
}

double GetDP(int r, int c, int p)
{
    if (f[r][c][p]) {
        return dp[r][c][p];
    }
    f[r][c][p] = true;
    double& ans = dp[r][c][p];
    ans = 0.0;
    if (r + 1 <= R) {
        if (p > 0) {
            int all_pairs = C2(r + 1 + c + p);
            int good_pairs = (r + 1) * p;
            double prob = 1.0 * good_pairs / all_pairs;
            ans += GetDP(r + 1, c, p) * prob;
        }
    }
    if (c + 1 <= C) {
        if (r > 0) {
            int all_pairs = C2(r + c + 1 + p);
            int good_pairs = r * (c + 1);
            double prob = 1.0 * good_pairs / all_pairs;
            ans += GetDP(r, c + 1, p) * prob;
        }
    }
    if (p + 1 <= P) {
        if (c > 0) {
            int all_pairs = C2(r + c + p + 1);
            int good_pairs = c * (p + 1);
            double prob = 1.0 * good_pairs / all_pairs;
            ans += GetDP(r, c, p + 1) * prob;
        } 
    }
    if (r + c + p != r && r + c + p != c && r + c + p != p) {
        ans /= (1.0 - 1.0 * (C2(r) + C2(c) + C2(p)) / C2(r + c + p));
    }
    return ans;
}

int main()
{
    cout << fixed << setprecision(15);
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> R >> C >> P;
    dp[R][C][P] = 1.0 / (1.0 - 1.0 * (C2(R) + C2(C) + C2(P)) / C2(R + C + P));
    f[R][C][P] = true;
    
    for (int r = 0; r <= R; ++r) {
        for (int c = 0; c <= C; ++c) {
            for (int p = 0; p <= P; ++p) {
                if (r + c + p != 0) {
                    //cout << r << " " << c << " " << p << ": ";
                    //cout << GetDP(r, c, p) << endl;
                    GetDP(r, c, p);
                }
            }
        }
    }
    
    double ans[3];
    ans[0] = ans[1] = ans[2] = 0.0;
    for (int i = 1; i <= kMaxN; ++i) {
        if (i <= R) {
            ans[0] += GetDP(i, 0, 0);
        }
        if (i <= C) {
            ans[1] += GetDP(0, i, 0);
        }
        if (i <= P) {
            ans[2] += GetDP(0, 0, i);
        }
    }
    for (int i = 0; i < 3; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
    
    return 0;
}