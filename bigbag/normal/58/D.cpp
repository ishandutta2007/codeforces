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

const int max_n = 11111, inf = 111111111;

int n, f[max_n];
string d, s[max_n];

bool cmp(string s1, string s2) {
    return s1 + d + s2 < s2 + d + s1;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    int len = n / 2;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        len += s[i].length();
    }
    len /= (n / 2);
    cin >> d;
    sort(s, s + n, cmp);
    for (int i = 0; i < n; ++i) {
        if (f[i] == 0) {
            for (int j = i + 1; j < n; ++j) {
                if (s[i].length() + s[j].length() + 1 == len && f[j] == 0) {
                    f[j] = 1;
                    cout << s[i] << d << s[j] << endl;
                    break;
                }
            }
        }
    }
    return 0;
}