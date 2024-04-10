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

const int max_n = 11, inf = 111111111;

int n, cnt, a[max_n], b[max_n];
string s[max_n], ans;

bool good(string q) {
    int used[11];
    memset(used, 0, sizeof(used));
    for (int j = 0; j < 4; ++j) {
        ++used[q[j] - '0'];
    }
    for (int j = 0; j <= 9; ++j) {
        if (used[j] > 1) {
            return false;
        }
    }
    for (int i = 0; i < n; ++i) {
        int x = 0, y = 0;
        for (int j = 0; j < 4; ++j) {
            if (q[j] == s[i][j]) {
                ++x;
            }
        }
        int used1[11], used2[11];
        memset(used1, 0, sizeof(used1));
        memset(used2, 0, sizeof(used2));
        for (int j = 0; j < 4; ++j) {
            ++used1[s[i][j] - '0'];
            ++used2[q[j] - '0'];
        }
        for (int j = 0; j <= 9; ++j) {
            y += min(used1[j], used2[j]);
        }
        y -= x;
        if (x != a[i] || y != b[i]) {
            return false;
        }
    }
    return true;
}

void gener(string q) {
    if (q.length() == 4) {
        if (good(q)) {
            ++cnt;
            ans = q;
        }
        return;
    }
    for (int i = 0; i < 10; ++i) {
        string qq = q;
        qq += i + '0';
        gener(qq);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s[i] >> a[i] >> b[i];
    }
    cnt = 0;
    gener("");
    if (cnt == 0) {
        cout << "Incorrect data" << endl;
        return 0;
    }
    if (cnt > 1) {
        cout << "Need more data" << endl;
        return 0;
    }
    cout << ans << endl;
    return 0;
}