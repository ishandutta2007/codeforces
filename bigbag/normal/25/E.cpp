#include <set>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_l = 100011, inf = 111111111;

int l1, l2, l3, p[2 * max_l];
string s1, s2, s3;

void pref_fun(string s) {
    p[0] = 0;
    int l = s.length();
    for (int i = 1; i < l; ++i) {
        int q = p[i - 1];
        while (q > 0 && s[q] != s[i]) {
            q = p[q - 1];
        }
        if (s[q] == s[i]) {
            ++q;
        }
        p[i] = q;
    }
}

bool is_in(string s1, string s2) {
    int l1 = s1.length(), l2 = s2.length();
    if (l1 > l2) {
        return false;
    }
    pref_fun(s1 + "#" + s2);
    for (int i = 0; i <= l1 + l2; ++i) {
        if (p[i] == l1) {
            return true;
        }
    }
    return false;
}

int max_len(string s1, string s2) {
    int l1 = s1.length(), l2 = s2.length();
    pref_fun(s2 + "#" + s1);
    return p[l1 + l2];
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> s1 >> s2 >> s3;
    if (is_in(s1, s2) || is_in(s1, s3)) {
        s1 = "";
    }
    if (is_in(s2, s1) || is_in(s2, s3)) {
        s2 = "";
    }
    if (is_in(s3, s1) || is_in(s3, s2)) {
        s3 = "";
    }
    int ans = inf;
    l1 = s1.length(), l2 = s2.length(), l3 = s3.length();
    int x1 = max_len(s1, s2), x2 = max_len(s1, s3), x3 = max_len(s2, s1), x4 = max_len(s2, s3), x5 = max_len(s3, s1), x6 = max_len(s3, s2);
    ans = min(ans, l1 + l2 + l3 - x1 - x4);
    ans = min(ans, l1 + l2 + l3 - x2 - x6);
    ans = min(ans, l1 + l2 + l3 - x3 - x2);
    ans = min(ans, l1 + l2 + l3 - x4 - x5);
    ans = min(ans, l1 + l2 + l3 - x5 - x1);
    ans = min(ans, l1 + l2 + l3 - x6 - x3);
    cout << ans << endl;
    return 0;
}