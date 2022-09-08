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

const int max_n = 100111, inf = 1011111111;

int n;
string s, a[max_n];

long long get(const string &s) {
    long long res = 0;
    int cnt = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == 's') {
            ++cnt;
        } else {
            res += cnt;
        }
    }
    return res;
}

bool cmp(const string &a, const string &b) {
    return get(a + b) > get(b + a);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n, cmp);
    for (int i = 0; i < n; ++i) {
        s += a[i];
    }
    cout << get(s) << "\n";
    return 0;
}