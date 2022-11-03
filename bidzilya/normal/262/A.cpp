#include <cstdio>
using namespace std;

int n, k;

int cnt_happy_number(int x) {
    int result = 0;
    while (x > 0) {
        int num = x % 10;
        if (num == 4 || num == 7) ++result;
        x /= 10;
    }
    return result;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    while (scanf("%d%d", &n, &k) != EOF) {
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int x;
            scanf("%d", &x);
            if (cnt_happy_number(x) <= k) ++ans;
        }
        printf("%d\n", ans);
    }

    return 0;
}