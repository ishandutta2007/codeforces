#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int i, j, da, tt;
    long long n, k, p[3], d1, d2, tmp;
    char rje[2][10] = { "no", "yes" };

    scanf("%d", &tt);

    for (; tt; tt--) {
        scanf("%I64d%I64d%I64d%I64d", &n, &k, &d1, &d2);
        da = 0;
        for (i=0; i<2; i++) {
            for (j=0; j<2; j++) {
                p[0] = 0;
                if (!i)
                    p[1] = p[0] + d1;
                else
                    p[1] = p[0] - d1;
                if (!j)
                    p[2] = p[1] + d2;
                else
                    p[2] = p[1] - d2;
                tmp = -min(min(p[0], p[1]), p[2]);
                p[0] += tmp;
                p[1] += tmp;
                p[2] += tmp;

                tmp = k - p[0] - p[1] - p[2];
                if (tmp % 3 || tmp < 0)
                    continue;
                tmp /= 3;
                p[0] += tmp;
                p[1] += tmp;
                p[2] += tmp;

                if (n % 3)
                    continue;

                sort(p, p+3);
                if (2 * p[2] - p[1] - p[0] > n - k)
                    continue;
                da = 1;
            }
        }
        printf("%s\n", rje[da]);
    }

    return 0;
}