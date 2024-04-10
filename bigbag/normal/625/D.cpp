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

const int max_n = 111111, inf = 1111111111;

int dp[max_n][2][2], a[max_n], ans[max_n];
pair<int, pair<int, int> > p[max_n][2][2];
string s;

bool get_dp(int poz, int p1, int p2, int fff) {
    if (dp[poz][p1][p2] != -1) {
        return dp[poz][p1][p2];
    }
    int rpoz = fff + s.length() - 1 - poz;
    //cout << poz << " " << rpoz << "   " << p1 << " " << p2 << "  fff = " << fff << endl;
    if (poz > rpoz) {
        dp[poz][p1][p2] = (p1 == p2);
        return dp[poz][p1][p2];
    } else if (poz == rpoz) {
        for (int x = 0; x <= 9; ++x) {
            int s = (x + x + p2);
            if (s % 10 == a[poz] && s / 10 == p1) {
                p[poz][p1][p2] = make_pair(x, make_pair(0, 0));
                dp[poz][p1][p2] = 1;
                return 1;
            }
        }
        dp[poz][p1][p2] = 0;
        return 0;
    } else {
        int st = 0;
        if (poz == fff) {
            st = 1;
        }
        for (int x = st; x <= 9; ++x) {
            for (int y = 0; y <= 9; ++y) {
                for (int p3 = 0; p3 < 2; ++p3) {
                    int s1 = (x + y + p3);
                    int s2 = (x + y + p2);
                    if (s1 % 10 == a[poz] && s2 % 10 == a[rpoz] && s1 / 10 == p1) {
                        if (get_dp(poz + 1, p3, s2 / 10, fff)) {
                            dp[poz][p1][p2] = 1;
                            p[poz][p1][p2] = make_pair(x, make_pair(y, p3));
                            return true;
                        }
                    }
                }
            }
        }
    }
    dp[poz][p1][p2] = 0;
    return false;
}

void get_ans(int poz, int p1, int p2, int fff) {
    int rpoz = fff + s.length() - 1 - poz;
    if (poz > rpoz) {
        return;
    } else if (poz == rpoz) {
        ans[poz] = p[poz][p1][p2].first;
    } else {
        ans[poz] = p[poz][p1][p2].first;
        ans[rpoz] = p[poz][p1][p2].second.first;
        get_ans(poz + 1, p[poz][p1][p2].second.second, (ans[poz] + ans[rpoz] + p2) / 10, fff);
    }
}

void check(int len) {
    memset(dp, -1, sizeof(dp));
    if (len == s.length()) {
        if (get_dp(0, 0, 0, 0)) {
            get_ans(0, 0, 0, 0);
            for (int i = 0; i < s.length(); ++i) {
                printf("%d", ans[i]);
            }
            printf("\n");
            exit(0);
        }
    } else if (s[0] == '1') {
        if (get_dp(1, 1, 0, 1)) {
            get_ans(1, 1, 0, 1);
            for (int i = 1; i < s.length(); ++i) {
                printf("%d", ans[i]);
            }
            printf("\n");
            exit(0);
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> s;
    for (int i = 0; i < s.length(); ++i) {
        a[i] = s[i] - '0';
    }
    check(s.length());
    if (s.length() > 1) {
        check(s.length() - 1);
    }
    printf("0\n");
    return 0;
}