#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX = 100100;

int period[MAX], zadnji[MAX], moze[MAX];

int main()
{
    int n, i, tmp, br=0;

    memset(zadnji, -1, sizeof zadnji);

    scanf("%d", &n);

    for (i=0; i<n; i++) {
        scanf("%d", &tmp);
        if (zadnji[tmp] != -1) {
            if (!period[tmp])
                period[tmp] = i - zadnji[tmp];
            else if (period[tmp] != i - zadnji[tmp])
                moze[tmp] = 0;
        }
        else
            moze[tmp] = 1;

        zadnji[tmp] = i;
    }

    for (i=0; i<MAX; i++)
        if (moze[i])
            br++;

    printf("%d\n", br);

    for (i=0; i<MAX; i++)
        if (moze[i])
            printf("%d %d\n", i, period[i]);

    return 0;
}