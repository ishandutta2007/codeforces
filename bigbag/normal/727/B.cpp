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

const int max_n = 1, inf = 1111111111;

string s;
long long a, b;

int get(string s) {
    int x = 0;
    for (int i = 0; i < s.length(); ++i) {
        if ('0' <= s[i] && s[i] <= '9') {
            x = x * 10 + s[i] - '0';
        }
    }
    return x;
}

void add(string s) {
    int len = s.length(), x = 0, y = 0;
    if (len >= 4 && s[len - 3] == '.') {
        x = get(s.substr(0, len - 3));
        y = get(s.substr(len - 2, 2));
    } else {
        x = get(s);
    }
    a += x;
    b += y;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> s;
    for (int i = 0; i < s.length(); ++i) {
        if ('0' <= s[i] && s[i] <= '9') {
            string q = "";
            while (i < s.length() && (s[i] == '.' || ('0' <= s[i] && s[i] <= '9'))) {
                q += s[i];
                ++i;
            }
            //cout << q << endl;
            add(q);
            --i;
        }
    }
    a += b / 100;
    b %= 100;
    string ans = "", res = "";
    if (a == 0) {
        ans = "0";
    } else {
        int cnt = 0;
        while (a) {
            if (cnt == 3) {
                cnt = 0;
                ans += ".";
            }
            ans += a % 10 + '0';
            a /= 10;
            ++cnt;
        }
        reverse(ans.begin(), ans.end());
    }
    if (b) {
        while (b) {
            res += b % 10 + '0';
            b /= 10;
        }
        if (res.length() == 1) {
            res += "0";
        }
        res += ".";
        reverse(res.begin(), res.end());
    }
    cout << ans + res << endl;
    return 0;
}