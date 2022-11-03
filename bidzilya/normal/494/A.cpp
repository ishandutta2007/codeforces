#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cmath>
#include <set>
#include <string>
#include <cstring>
using namespace std;

int GetValue(char c)
{
    if (c == '(') {
        return 1;
    } else {
        return -1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    string str;

    cin >> str;

    int last_pos = -1;

    int n = str.length();

    for (int i = 0; i < n; ++i) {
        if (str[i] == '#') {
            last_pos = i;
        }
    }

    vector<int> ans;
    vector<int> sum(n);

    sum[0] = GetValue(str[0]);

    for (int i = 1; i < n; ++i) {
        sum[i] = sum[i - 1];
        if (str[i] != '#') {
            sum[i] += GetValue(str[i]);
        } else {
            --sum[i];
        }
    }

    for (int i = 0; i < n; ++i) {
        if (sum[i] < 0) {
            cout << -1 << endl;
            return 0;
        }
    }

    int remain = sum[n - 1];

    for (int i = last_pos; i < n; ++i) {
        sum[i] -= remain;
        if (sum[i] < 0) {
            cout << -1 << endl;
            return 0;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (str[i] == '#') {
            if (i == last_pos) {
                ans.push_back(1 + remain);
            } else {
                ans.push_back(1);
            }
        }
    }

    for (int i = 0; i < (int) ans.size(); ++i) {
        cout << ans[i] << endl;
    }

    return 0;
}