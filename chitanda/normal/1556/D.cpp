#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define y1 y114514
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define all(a) a.begin(), a.end()
const int M = 1000000007;

int n, k;
int a[10005];

int get_or(int i, int j) {
    printf("or %d %d\n", i, j);
    fflush(stdout);
    static int x;
    scanf("%d", &x);
    return x;
}

int get_and(int i, int j) {
    printf("and %d %d\n", i, j);
    fflush(stdout);
    static int x;
    scanf("%d", &x);
    return x;
}

int get_sum(int i, int j) { return get_or(i, j) + get_and(i, j); }

int main() {
    scanf("%d%d", &n, &k);
    int s1 = get_sum(1, 2);
    int s2 = get_sum(1, 3);
    int s3 = get_sum(2, 3);
    a[1] = (s1 + s2 - s3) / 2;
    a[2] = s1 - a[1];
    a[3] = s2 - a[1];

    for (int i = 4; i <= n; ++i) {
        int s = get_sum(1, i);
        a[i] = s - a[1];
    }
    sort(a + 1, a + n + 1);
    printf("finish %d\n", a[k]);
    fflush(stdout);
    return 0;
}