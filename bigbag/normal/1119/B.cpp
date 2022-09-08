#include <bits/stdc++.h>

using namespace std;

const int max_n = 1011, inf = 1000111222;

int n, h, a[max_n];

bool check(int k) {
    vector<int> v(a, a + k);
    sort(v.begin(), v.end());
    long long sum = 0;
    for (int i = ((int) v.size()) - 1; i >= 0; i -= 2) {
        sum += v[i];
    }
    return sum <= h;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &h);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    int l = 1, r = n + 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    printf("%d\n", l);
    return 0;
}