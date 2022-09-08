#include <bits/stdc++.h>

using namespace std;

const int max_n = 1000111, inf = 1000111222;

int n, q, a[max_n];
long long sum;
long double pw = 1;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &q);
    for (int i = 0; i < (1 << n); ++i) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    pw = (1 << n);
    printf("%.10f\n", (double) (sum / pw));
    while (q--) {
        int pos, x;
        scanf("%d%d", &pos, &x);
        sum -= a[pos];
        a[pos] = x;
        sum += a[pos];
        printf("%.10f\n", (double) (sum / pw));
    }
    return 0;
}