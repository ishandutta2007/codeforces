#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int t, n, x;
char s[max_n];
map<int, int> cnt;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%s", &n, s);
        long long ans = 0;
        cnt.clear();
        int sum = 0;
        cnt[1] = 1;
        for (int i = 0; i < n; ++i) {
            sum += s[i] - '0';
            ans += cnt[sum - i];
            ++cnt[sum - i];
        }
        printf("%I64d\n", ans);
    }
    return 0;
}