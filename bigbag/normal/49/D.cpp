#include <map>
#include <set>
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

int n;
string s, o1, o2, k;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> s;
    k = s;
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            o1 = o1 + "1";
        } else {
            o1 = o1 + "0";
        }
        if (i % 2 == 0) {
            o2 = o2 + "0";
        } else {
            o2 = o2 + "1";
        }
    }
    int cnt = 0;
    while (1) {
        int f = 0;
        if (s == o1) {
            break;
        }
        ++cnt;
        f = 0;
        for (int i = 0; i < n; ++i) {
            if (i + 1 < n && s[i] == s[i + 1]) {
                if (s[i] != o1[i] && s[i + 1] != o1[i + 1]) {
                    s[i] = o1[i];
                    s[i + 1] = o1[i + 1];
                    f = 1;
                    break;
                }
            }
        }
        if (f == 0) {
            for (int i = 0; i < n; ++i) {
                if (i + 1 < n && s[i] == s[i + 1]) {
                    s[i] = o1[i];
                    s[i + 1] = o1[i + 1];
                    break;
                }
            }
        }
        if (cnt > 1000) {
            break;
        }
    }
    int ans = cnt;
    cnt = 0;
    s = k;
    o1 = o2;
    while (1) {
        int f = 0;
        if (s == o1) {
            break;
        }
        ++cnt;
        f = 0;
        for (int i = 0; i < n; ++i) {
            if (i + 1 < n && s[i] == s[i + 1]) {
                if (s[i] != o1[i] && s[i + 1] != o1[i + 1]) {
                    s[i] = o1[i];
                    s[i + 1] = o1[i + 1];
                    f = 1;
                    break;
                }
            }
        }
        if (f == 0) {
            for (int i = 0; i < n; ++i) {
                if (i + 1 < n && s[i] == s[i + 1]) {
                    s[i] = o1[i];
                    s[i + 1] = o1[i + 1];
                    break;
                }
            }
        }
        if (cnt > 1000) {
            break;
        }
    }
    if (min(ans, cnt) > 1000) {
        cout << -1 << endl;
        return 0;
    }
    cout << min(ans, cnt) << endl;
    return 0;
}