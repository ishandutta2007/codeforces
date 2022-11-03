#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int n;
    n = (s.length() + 1) / 2;

    vector<int> digits;
    vector<char> signs;

    for (int i = 0; i < (int) s.length(); i += 2) {
        digits.push_back(s[i] - '0');
    }
    for (int i = 1; i < (int) s.length(); i += 2) {
        signs.push_back(s[i]);
    }

    vector<long long> left_mult(n), right_mult(n),
        left_amount(n), right_amount(n);

    for (int i = 0; i < n; ++i) {
        left_mult[i] = digits[i];

        int j = i;
        while (j > 0 && signs[j - 1] == '*') {
            --j;
            left_mult[i] *= digits[j];
        }

        left_amount[i] = i - j + 1;

        right_mult[i] = digits[i];

        j = i;
        while (j + 1 < n && signs[j] == '*') {
            ++j;
            right_mult[i] *= digits[j];
        }

        right_amount[i] = j - i + 1;
    }

    vector<long long> left_value(n), right_value(n);
    for (int i = 0; i < n; ++i) {
        left_value[i] = left_mult[i];

        int j = i - left_amount[i];

        if (j >= 0) {
            left_value[i] += left_value[j];
        }
    }

    vector<vector<long long> > g_middle_value(n, vector<long long>(n));
    for (int i = 0; i < n; ++i) {
        g_middle_value[i][i] = digits[i];

        for (int j = i + 1; j < i + right_amount[i]; ++j) {
            g_middle_value[i][j] = g_middle_value[i][j - 1] * digits[j];
        }

        int j = i + right_amount[i];
        while (j < n) {
            for (int t = j; t < j + right_amount[j]; ++t) {
                g_middle_value[i][t] = g_middle_value[i][j - 1] + left_mult[t];
            }

            j += right_amount[j];
        }
    }

    for (int i = n - 1; i >= 0; --i) {
        right_value[i] = right_mult[i];

        int j = i + right_amount[i];

        if (j < n) {
            right_value[i] += right_value[j];
        }
    }

/*
    for (int i = 0; i < n; ++i) {
        cout << digits[i] << " ";
    }
    cout << endl;

    for (int i = 0; i + 1 < n; ++i) {
        cout << signs[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < n; ++i) {
        cout << i << ": " << endl;
        cout << "  " << left_mult[i] << " " << left_amount[i] << endl;
        cout << "  " << right_mult[i] << " " << right_amount[i] << endl;
    }
*/
    long long answer = right_value[0];
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            long long middle_value = g_middle_value[i][j];

            if (i == 0 && j + 1 == n) {
                continue;
            }

            int lb = i;
            int rb = j;

            long long mv = middle_value;
            if (lb - 1 >= 0 && signs[lb - 1] == '*') {
                mv *= left_mult[lb - 1];
                lb -= left_amount[lb - 1];
            }
            if (rb + 1 < n && signs[rb] == '*') {
                mv *= right_mult[rb + 1];
                rb += right_amount[rb + 1];
            }

            long long lv = 0;
            if (lb - 1 >= 0) {
                lv = left_value[lb - 1];
            }

            long long rv = 0;
            if (rb + 1 < n) {
                rv = right_value[rb + 1];
            }

            // cout << i << "..." << j << ": " << lv + mv + rv << endl;

            answer = max(answer, lv + mv + rv);
        }
    }

    cout << answer << endl;

    return 0;
}