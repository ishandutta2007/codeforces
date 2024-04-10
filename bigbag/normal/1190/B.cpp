#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int n, a[max_n];

bool solve() {
    map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
        ++cnt[a[i]];
    }
    int two = -1;
    for (const auto &p : cnt) {
        if (p.second >= 3) {
            return false;
        } else if (p.second == 2) {
            if (two == -1) {
                two = p.first;
            } else {
                return false;
            }
        }
    }
    if (two == 0) {
        return false;
    }
    if (two != -1) {
        if (cnt[two - 1] != 0) {
            return false;
        }
        for (int i = 0; i < n; ++i) {
            if (a[i] == two) {
                --a[i];
                break;
            }
        }
        return solve() ^ 1;
    }
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
        sum -= i;
    }
    if (sum % 2 == 0) {
        return false;
    }
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    if (solve()) {
        puts("sjfnb");
    } else {
        puts("cslnb");
    }
    return 0;
}