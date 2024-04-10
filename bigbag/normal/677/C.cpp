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

const int max_n = 111111, mod = 1000000007;

int n, c[11][11];
char s[max_n];

bool get_bit(int x, int poz) {
    return (bool) (x & (1 << poz));
}

int get(char c) {
    if ('0' <= c && c <= '9') {
        return c - '0';
    }
    if ('A' <= c && c <= 'Z') {
        return c - 'A' + 10;
    }
    if ('a' <= c && c <= 'z') {
        return c - 'a' + 36;
    }
    if (c == '-') {
        return 62;
    }
    return 63;
}

void get_all_c() {
    c[0][0] = 1;
    for (int i = 1; i < 11; ++i) {
        c[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    get_all_c();
    scanf("%s", s);
    n = strlen(s);
    int ans = 1;
    for (int i = 0; i < n; ++i) {
        int x = get(s[i]), cnt = 6;
        for (int j = 0; j < 6; ++j) {
            cnt -= get_bit(x, j);
        }
        int res = 0;
        for (int j = 0; j <= cnt; ++j) {
            res += ((1LL << (cnt - j)) * c[cnt][j]) % mod;
            res %= mod;
        }
        ans = (1LL * ans * res) % mod;
    }
    printf("%d\n", ans);
    return 0;
}