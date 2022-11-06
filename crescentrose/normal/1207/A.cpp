#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int t, b, p, f, h, c;
int main()
{
    scanf("%d", &t);
    while (t --) {
        int ans = 0;
        scanf("%d %d %d %d %d", &b, &p, &f, &h, &c);
        for (int i = 0; i <= 100; i ++) {
            if (i *2 > b || i > p) break;
            int x = min((b -i * 2) / 2,  f);
            ans = max(ans, x * c + i * h);
        }
        printf("%d\n", ans);
    }
    return 0;
}