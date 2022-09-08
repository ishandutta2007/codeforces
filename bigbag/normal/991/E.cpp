#include <bits/stdc++.h>

using namespace std;

long long n, ans, fact[22];
int cnt[11], a[11];

long long add() {
    int len = 0;
    for (int i = 0; i < 10; ++i) {
        len += a[i];
    }
    long long res = fact[len];
    for (int i = 0; i < 10; ++i) {
        res /= fact[a[i]];
    }
    return res;
}

void rec(int pos) {
    if (pos == 10) {
        ans += add();
        if (a[0]) {
            --a[0];
            ans -= add();
            ++a[0];
        }
        return;
    }
    if (cnt[pos] == 0) {
        rec(pos + 1);
    } else {
        for (int i = 1; i <= cnt[pos]; ++i) {
            a[pos] = i;
            rec(pos + 1);
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fact[0] = 1;
    for (int i = 1; i < 22; ++i) {
        fact[i] = fact[i - 1] * i;
    }
    cin >> n;
    while (n) {
        ++cnt[n % 10];
        n /= 10;
    }
    rec(0);
    cout << ans << endl;
    return 0;
}