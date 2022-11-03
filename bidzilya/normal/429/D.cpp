#include <iostream>
#include <iomanip>
#include <vector>
#include <map>

#include <cassert>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

typedef long long ll;

const int max_n = 1e5 + 10;

int a[max_n];
int s[max_n];
int n;

inline int sqr(int x) { return x * x; }
inline int abs(int x) { return (x < 0 ? -x : x); }

int main()
{
    /*
    srand(time(NULL));
    freopen("input.txt", "w", stdout);
    printf("100000\n");
    for (int i = 0; i < 100000; ++i)
        printf("%d ", rand() % 20001 - 10000);
    printf("\n");
    return 0;
    */
 //   freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);

    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", a + i);

    s[0] = a[0];
    for (int i = 1; i < n; ++i)
        s[i] = s[i - 1] + a[i];

    int ans = sqr(a[1]);
    for (int i = 2; i < n; ++i)
        ans = min(ans, sqr(a[i]));
    ++ans;

    for (int len = 1; len * len <= ans; ++len) {
        int len2 = sqr(len);
        for (int i = 0; i + len < n; ++i)
            if (abs(s[i + len] - s[i]) <= 10010)
                ans = min(ans, len2 + sqr(s[i + len] - s[i]));
    }

    printf("%d\n", ans);

    return 0;
}