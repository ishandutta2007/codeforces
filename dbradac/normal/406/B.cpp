#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 1000100, MIL = 1000001;

int p[MAX];

int main()
{
    int n, i, kolko, tmp;

    scanf("%d", &n);

    for (i=0; i<n; i++) {
        scanf("%d", &tmp);
        p[tmp] = 1;
    }

    printf("%d\n", n); kolko=n;

    for (i=1; i<=MIL; i++) {
        if (p[i] && !p[MIL-i]) {
            printf("%d ", MIL-i);
            kolko--;
        }
    }

    for (i=1; i<=MIL && kolko; i++)
        if (!p[i] && !p[MIL-i]) {
            printf("%d %d ", i, MIL-i);
            kolko-=2;
        }

    return 0;
}