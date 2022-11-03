#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#include <cstdlib>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int max_n = 1e5 + 100;
string s;

ull ans_cnt[max_n];
int ans[max_n];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> s;
    ans[s.length()] = 0;
    ans_cnt[s.length()] = 1;
    for (int i = s.length() - 1; i >= 0; --i) {
        ans[i] = ans[i + 1];
        ans_cnt[i] = ans_cnt[i + 1];
        if (i + 1 < s.length() && s[i] - '0' + s[i + 1] - '0' == 9) {
            if (1 + ans[i + 2] > ans[i]) {
                ans[i] = 1 + ans[i + 2];
                ans_cnt[i] = ans_cnt[i + 2];
            } else if (1 + ans[i + 2] == ans[i]) {
                ans_cnt[i] += ans_cnt[i + 2];
            }
        }
    }
    cout << ans_cnt[0] << endl;
    return 0;
}