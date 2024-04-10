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

const int max_n = 1111, inf = 111111111;

string int_to_str(int x) {
    string ret = "";
    while (x != 0) {
        ret += x % 10 + '0';
        x /= 10;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

string s1, s2;
vector <string> ans;
int len1, len2, dp[max_n][max_n], sd, used[max_n][max_n];

int get_cnt(int a, int b) {
    if (a == len1 && b == len2) {
        return 0;
    }
    if (used[a][b] != 0) {
        return dp[a][b];
    }
    int ret = inf;
    if (a < len1 && b < len2 && s1[a] == s2[b]) {
        ret = min(ret, get_cnt(a + 1, b + 1));
    }
    if (a < len1 && b < len2) {
        ret = min(ret, get_cnt(a + 1, b + 1) + 1);
    }
    if (a < len1) {
        ret = min(ret, get_cnt(a + 1, b) + 1);
    }
    if (b < len2) {
        ret = min(ret, get_cnt(a, b + 1) + 1);
    }
    dp[a][b] = ret;
    used[a][b] = 1;
    return ret;
}

void get_ans(int a, int b) {
    if (a == len1 && b == len2) {
        return;
    }
    int ret = inf, f;
    if (a < len1 && b < len2 && s1[a] == s2[b]) {
        if (ret > get_cnt(a + 1, b + 1)) {
            ret = get_cnt(a + 1, b + 1);
            f = 1;
        }
    }
    if (a < len1 && b < len2) {
        if (ret > get_cnt(a + 1, b + 1) + 1) {
            ret = get_cnt(a + 1, b + 1) + 1;
            f = 2;
        }
    }
    if (a < len1) {
        if (ret > get_cnt(a + 1, b) + 1) {
            ret = get_cnt(a + 1, b) + 1;
            f = 3;
        }
    }
    if (b < len2) {
        if (ret > get_cnt(a, b + 1) + 1) {
            ret = get_cnt(a, b + 1) + 1;
            f = 4;
        }
    }
    if (f == 1) {
        get_ans(a + 1, b + 1);
    }
    if (f == 2) {
        ans.push_back("REPLACE " + int_to_str(sd + a + 1) + " " + s2[b]);
        get_ans(a + 1, b + 1);
    }
    if (f == 3) {
        ans.push_back("DELETE " + int_to_str(sd + a + 1));
        --sd;
        get_ans(a + 1, b);
    }
    if (f == 4) {
        ans.push_back("INSERT " + int_to_str(sd + a + 1) + " " + s2[b]);
        ++sd;
        get_ans(a, b + 1);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> s1 >> s2;
    len1 = s1.length();
    len2 = s2.length();
    get_cnt(0, 0);
    get_ans(0, 0);
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << endl;
    }
    return 0;
}