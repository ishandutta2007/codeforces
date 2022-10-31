#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 1<<17;

int p[MAX];

int Ok(int poc, int n)
{
    int i;

    for (i=poc; i<n; i++)
        if (p[i] > p[i+1])
            return 0;
    return 1;
}

int main()
{
    int n, i, br=0, poc, kraj;

    scanf("%d", &n);

    for (i=1; i<=n; i++)
        scanf("%d", &p[i]);
    p[0] = -1;
    p[n+1] = 1000000005;

    for (i=1; i<n; i++) {
        if (p[i] > p[i+1]) {
            br++;
            poc = i;
            for (; i<n; i++) {
                if (p[i] < p[i+1])
                    break;
            }
            if (!Ok(i+1, n) || p[poc] > p[i+1] || p[i] < p[poc-1]) {
                br=2;
                break;
            }
            else {
                kraj = i;
                break;
            }
        }
    }

    if (!br)
        printf("yes\n1 1\n");
    else if (br == 1)
        printf("yes\n%d %d\n", poc, kraj);
    else
        printf("no\n");

    return 0;
}