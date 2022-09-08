#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const int max_n = 100111, inf = 1000111222;

int n, m, a[max_n];
pair<int, int> b[max_n];
long long sum[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &b[i].first, &b[i].second);
    }
    sort(b, b + m);
    sum[0] = b[0].second;
    for (int i = 1; i < m; ++i) {
        sum[i] = sum[i - 1] + b[i].second;
    }
    for (int i = 0; i < n; ++i) {
        int pos = upper_bound(b, b + m, make_pair(a[i], inf)) - b - 1;
        if (pos == -1) {
            printf("0 ");
        } else {
            printf("%I64d ", sum[pos]);
        }
    }
    return 0;
}