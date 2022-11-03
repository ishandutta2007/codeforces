#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>
#include <sstream>
#include <cstdlib>
using namespace std;

const long long kNotDefined = 1e18;
const string kFailed = "Incorrect sequence";

long long GetArithmetic(long long n)
{
    return n * (1 + n) / 2;
}

void Solve(vector<long long>& a)
{
    int n = a.size();
    for (int i = 0; i < n; ) {
        if (a[i] != kNotDefined) {
            ++i;
            continue;
        }
        int j = i;
        while (j + 1 < n && a[j + 1] == kNotDefined) {
            ++j;
        }

        long long mn = -1e18;
        if (i != 0) {
            mn = a[i - 1] + 1;
        }
        long long mx = 1e18;
        if (j + 1 != n) {
            mx = a[j + 1] - 1;
        }

        if (mn > mx) {
            cout << kFailed << endl;
            exit(0);
        }

        int amount = j - i + 1;

        if (mx - mn + 1 < amount) {
            cout << kFailed << endl;
            exit(0);
        }

        if (mn >= 0) {
            for (int t = i; t <= j; ++t) {
                a[t] = mn + (t - i);
            }
            i = j + 1;
            continue;
        }

        if (mx <= 0) {
            for (int t = i; t <= j; ++t) {
                a[t] = mx - (j - t);
            }
            i = j + 1;
            continue;
        }

        // mx > 0 and mn < 0
        long long lf = -mn;
        long long rg = mx;

        int best_pos = -1;
        long long best_ans;
        for (int t = i; t <= j; ++t) {
            int cur_lf = t - i;
            int cur_rg = j - t;

            if (cur_lf <= lf && cur_rg <= rg) {
                long long cur_ans = GetArithmetic(cur_lf) + GetArithmetic(cur_rg);

                if (best_pos == -1 || cur_ans < best_ans) {
                    best_pos = t;
                    best_ans = cur_ans;
                }
            }
        }

        for (int t = i; t <= j; ++t) {
            a[t] = t - best_pos;
        }

        i = j + 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<long long> r(n);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        if (s.length() == 1 && s == "?") {
            r[i] = kNotDefined;
        } else {
            bool is_sign = false;
            if (s[0] == '-') {
                s = s.substr(1);
                is_sign = true;
            }
            r[i] = 0;
            for (int j = 0; j < (int) s.length(); ++j) {
                r[i] = r[i] * 10 + s[j] - '0';
            }
            if (is_sign) {
                r[i] *= -1;
            }
        }
    }

    for (int rm = 0; rm < k; ++rm) {
        vector<long long> t;
        for (int j = 0; j * k + rm < n; ++j) {
            t.push_back(r[j * k + rm]);
        }
        Solve(t);
        for (int j = 0; j * k + rm < n; ++j) {
            r[j * k + rm] = t[j];
        }
    }

    vector<long long> sr(n);
    sr[0] = r[0];
    for (int i = 1; i < n; ++i) {
        sr[i] = sr[i - 1] + r[i];
    }

    vector<long long> tr(n - k + 1);
    for (int i = 0; i + k - 1 < n; ++i) {
        long long cur_s = sr[i + k - 1];
        if (i != 0) {
            cur_s -= sr[i - 1];
        }
        tr[i] = cur_s;
    }

    for (int i = 1; i < n - k + 1; ++i) {
        if (tr[i - 1] >= tr[i]) {
            cout << kFailed << endl;
            exit(0);
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << r[i] << " ";
    }
    cout << endl;

    return 0;
}