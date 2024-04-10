#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 998244353;

int mul(unsigned long long a, unsigned long long b) {
    return (int)(a * b % MOD);
}

void add(int& a, int b) {
    a += b;
    if (a >= MOD) {
        a -= MOD;
    }
}

int getInverse(unsigned long long x) {
    unsigned long long res = 1;
    int p = MOD - 2;
    while (p) {
        if (p & 1) {
            res *= x;
            res %= MOD;
        }
        x *= x;
        x %= MOD;
        p /= 2;
    }
    return (int) res;
}

int fact[200020];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    fact[0] = 1;
    for (int i = 1; i <= n * 2; i++) {
        fact[i] = mul(fact[i - 1], i);
    }
    int zeroes = 0, ones = 0, qs = 0, qqs = 0;
    bool seenFull = false, no01 = false, no10 = false;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (char c : s) {
            (c == 'W' ? zeroes : (c == 'B' ? ones : qs))++;
        }
        if (s == "??") {
            qqs++;
        }
        if (s[0] == 'W' || s[1] == 'B') {
            no10 = true;
        }
        if (s[1] == 'W' || s[0] == 'B') {
            no01 = true;
        }
        if (s[0] == s[1] && s[0] != '?') {
            seenFull = true;
        }
    }
    if (abs(zeroes - ones) > qs) {
        cout << "0\n";
    } else {
        int answer = mul(fact[qs], mul(getInverse(fact[n - zeroes]), getInverse(fact[qs - n + zeroes])));
        if (!seenFull) {
            int p = 1;
            for (int i = 0; i < qqs; i++) {
                add(p, p);
            }
            add(answer, MOD - p);
        }
        add(answer, !no10 + !no01);
        cout << answer << '\n';
    }
}