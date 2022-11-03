#include <algorithm>
#include <iostream>
#include <utility>
#include <iomanip>
#include <vector>
#include <queue>
using namespace std;

const int kModulus = 1e9 + 7;

vector<int> GetZFunction(const string& s)
{
    int n = s.length();
    vector<int> z(n);
    z[0] = 0;
    for (int i = 1, l = -1, r = -1; i < n; ++i) {
        if (i <= r) {
            z[i] = min(z[i - l], r - i);
        } else {
            z[i] = 0;
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            ++z[i];
        }
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

int main()
{
    ios_base::sync_with_stdio(false);

    string s, t;
    cin >> s >> t;

    int n = s.length();
    int m = t.length();

    vector<int> z = GetZFunction(t + "#" + s);

    vector<bool> good_pos(n, false);
    for (int i = 0; i < n; ++i) {
        if (z[m + 1 + i] == m) {
            good_pos[i] = true;
        }
    }

    vector<int> closest_good_pos(n);

    for (int i = n - 1; i >= 0; --i) {
        if (good_pos[i]) {
            closest_good_pos[i] = i;
        } else {
            if (i == n - 1) {
                closest_good_pos[i] = -1;
            } else {
                closest_good_pos[i] = closest_good_pos[i + 1];
            }
        }
    }

    vector<int> ans(n), sum_ans(n);

    for (int i = n - 1; i >= 0; --i) {
        if (i != n - 1) {
            ans[i] = ans[i + 1];
        } else {
            ans[i] = 0;
        }
        if (closest_good_pos[i] != -1) {
            int k = closest_good_pos[i] + m - 1;

            ans[i] += (n - k);
            if (ans[i] >= kModulus) {
                ans[i] -= kModulus;
            }

            if (k + 1 < n) {
                ans[i] += sum_ans[k + 1];
                if (ans[i] >= kModulus) {
                    ans[i] -= kModulus;
                }
            }
        }
        if (i == n - 1) {
            sum_ans[i] = ans[i];
        } else {
            sum_ans[i] = sum_ans[i + 1] + ans[i];
            if (sum_ans[i] >= kModulus) {
                sum_ans[i] -= kModulus;
            }
        }
    }

    cout << ans[0] << endl;

    return 0;
}