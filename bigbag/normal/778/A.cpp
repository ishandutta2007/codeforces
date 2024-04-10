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

const int max_n = 222222, inf = 1011111111;

int a[max_n], used[max_n];
char S[max_n];
string s, t;

string read() {
    scanf("%s", S);
    return S;
}

bool check(int cnt) {
    memset(used, 0, sizeof(used));
    for (int i = 0; i < cnt; ++i) {
        used[a[i]] = 1;
    }
    int pos = 0;
    for (int i = 0; i < t.length(); ++i) {
        while (pos < s.length() && (s[pos] != t[i] || used[pos] == 1)) {
            ++pos;
        }
        if (pos == s.length()) {
            return false;
        }
        ++pos;
    }
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    s = read();
    t = read();
    for (int i = 0; i < s.length(); ++i) {
        scanf("%d", &a[i]);
        --a[i];
    }
    int l = 0, r = s.length();
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    printf("%d\n", l);
    return 0;
}