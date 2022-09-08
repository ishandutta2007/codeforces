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

const int max_n = 1111, inf = 1011111111;

int n;
string a, b;

int solve_min(string a, string b) {
    sort(a.begin(), a.end());
    int cnt[11];
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < b.length(); ++i) {
        ++cnt[b[i] - '0'];
    }
    int res = 0;
    for (int i = 0; i < a.length(); ++i) {
        int f = 0;
        for (int j = a[i] - '0'; j <= 9; ++j) {
            if (cnt[j]) {
                --cnt[j];
                f = 1;
                break;
            }
        }
        if (f == 0) {
            ++res;
        }
    }
    return res;
}

int solve_max(string a, string b) {
    sort(a.begin(), a.end());
    int cnt[11];
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < b.length(); ++i) {
        ++cnt[b[i] - '0'];
    }
    int res = 0;
    for (int i = 0; i < a.length(); ++i) {
        int f = 0;
        for (int j = a[i] - '0' + 1; j <= 9; ++j) {
            if (cnt[j]) {
                --cnt[j];
                f = 1;
                break;
            }
        }
        if (f == 1) {
            ++res;
        }
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> a >> b;
    cout << solve_min(a, b) << endl;
    cout << solve_max(a, b) << endl;
    return 0;
}