#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, inf = 1000111222;

int n;
vector<long long> ans;

void add(int d) {
    int cnt = n / d;
    long long res = (1LL * cnt * (cnt - 1)) / 2;
    res *= d;
    res += cnt;
    ans.push_back(res);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            add(i);
            if (i * i != n) {
                add(n / i);
            }
        }
    }
    sort(ans.begin(), ans.end());
    for (long long x : ans) {
        printf("%I64d ", x);
    }
    printf("\n");
    return 0;
}