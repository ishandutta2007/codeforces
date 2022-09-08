#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 11111, inf = 1111111111;

int n, dp[max_n][5];
char s[max_n];
string q;
vector<string> ans;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%s", s);
    n = strlen(s);
    q = s;
    dp[n - 2][2] = 1;
    dp[n - 3][3] = 1;
    dp[n - 4][2] = q.substr(n - 4, 2) != q.substr(n - 2, 2);
    for (int i = n - 4; i >= 0; --i) {
        for (int len = 2; len <= 3; ++len) {
            dp[i][len] |= (dp[i + len][2] && (q.substr(i, len) != q.substr(i + len, 2)));
            dp[i][len] |= (dp[i + len][3] && (q.substr(i, len) != q.substr(i + len, 3)));
        }
    }
    for (int i = 5; i < n; ++i) {
        if (dp[i][2]) {
            ans.push_back(q.substr(i, 2));
        }
        if (dp[i][3]) {
            ans.push_back(q.substr(i, 3));
        }
    }
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i) {
        printf("%s\n", ans[i].c_str());
    }
    return 0;
}