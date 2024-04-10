#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <memory.h>

using namespace std;

long long n;
long long r;
int k;
vector<int> a;

const int INF = 1 << 16;
long long memo[101][INF][2];

long long go(int d, long long x, int c) {
    if (!x) return 0;
    if (x < INF && memo[d][x][c & 1] != -1) return memo[d][x][c & 1];

    long long res = 0;
    if (d == k) {
        res = x;
        if (c & 1) res = -res;
    } else {
        res += go(d + 1, x / a[d], c + 1);
        res += go(d + 1, x, c);
    }

    if (x < INF) memo[d][x][c&1] = res;
    return res;
}

bool is_prime(int x) {
    for (int i = 2; i < x; i++) if (x % i == 0) return false;
    return true;
}

int main() {
    memset(memo, -1, sizeof memo);
    cin >> n >> k;
    a.resize(k);
    for (int i = 0; i < k; i++) cin >> a[i];
/*
    n = 10000000000000LL;
    k = 100;
    a.resize(k);
    int d = 2;
    for (int i = 0; i < k; i++) {
        while (!is_prime(d)) d++;
        a[i] = d;
        d++;
    }
*/
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    if (a[0] == 1) {
        cout << 0 << endl;
    }else {
        long long r = go(0, n, 0);
        cout << r << endl;
    }
    return 0;
}