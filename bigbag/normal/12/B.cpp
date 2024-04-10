#include <map>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

char s[11], s1[11], s2[11], m[333];
vector <int> x;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    gets(s);
    gets(s1);
    if (strcmp(s, "0") == 0 && strcmp(s1, "0") == 0) {
        cout << "OK";
        return 0;
    }
    int l = strlen(s), l1 = strlen(s1);
    if (l != l1 || s1[0] == '0') {
        cout << "WRONG_ANSWER";
        return 0;
    }
    int cnt = 0;
    for (int i = 0; i < l; ++i) {
        m[s[i]]++;
        m[s1[i]]--;
        if (s1[i] != '0') x.push_back(s1[i] - '0');
        else cnt++;
    }
    for (int i = 0; i < 333; ++i) {
        if (m[i] != 0) {
            cout << "WRONG_ANSWER";
            return 0;
        }
    }
    sort(x.begin(), x.end());
    s2[0] = x[0] + '0';
    for (int i = 1; i <= cnt; ++i) {
        s2[i] = '0';
    }
    for (int i = cnt + 1; i < cnt + x.size(); ++i) {
        s2[i] = x[i - cnt] + '0';
    }
    if (strcmp(s1, s2) == 0) cout << "OK";
    else cout << "WRONG_ANSWER";
    return 0;
}