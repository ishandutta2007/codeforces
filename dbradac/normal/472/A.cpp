#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 1<<20;

int sito[MAX];

int main()
{
    int i, j, n;

    for (i=2; i<MAX; i++) {
        if (!sito[i]) {
            for (j=2*i; j<MAX; j+=i)
                sito[j] = 1;
        }
    }

    scanf("%d", &n);

    for (i=2; i<n; i++) {
        if (sito[i] && sito[n-i]) {
            printf("%d %d\n", i, n-i);
            break;
        }
    }

    return 0;
}