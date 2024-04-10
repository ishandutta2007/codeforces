#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const int max_n = 200222, inf = 1000111222;

int n, used[max_n], res[max_n], ans;
char s[max_n];

int solve(int g) {
    if (used[g]) {
        return res[g];
    }
    used[g] = 1;
    res[g] = 1;
    for (int i = 0; i < g; ++i) {
        int x = 0;
        for (int j = i; j < n; j += g) {
            x ^= s[j] - '0';
        }
        if (x) {
            res[g] = 0;
            break;
        }
    }
    return res[g];
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%s", &n, s);
    for (int i = 0; i < n; ++i) {
        int g = __gcd(i, n);
        ans += solve(g);
    }
    printf("%d\n", ans);
    return 0;
}