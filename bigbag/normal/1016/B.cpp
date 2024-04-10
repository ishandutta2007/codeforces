#include <bits/stdc++.h>

using namespace std;

const int max_n = 1111, inf = 1000111222;

int n, m, q, sum[max_n];
string a, b;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m >> q >> a >> b;
    for (int i = 0; i + b.length() <= a.length(); ++i) {
        sum[i] = (a.substr(i, b.length()) == b);
        if (i) {
            sum[i] += sum[i - 1];
        }
    }
    while (q--) {
        int l, r;
        scanf("%d%d", &l, &r);
        --l;
        --r;
        int ans = 0;
        if (l + b.length() <= r + 1) {
            ans = sum[r - b.length() + 1];
            if (l) {
                ans -= sum[l - 1];
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}