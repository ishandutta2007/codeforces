#include <cstdio>
#include <algorithm>

using namespace std;

int p[105], natovar[105], used[105];

int main()
{
    int n, i, j, r=0;

    scanf("%d", &n);

    for (i=0; i<n; i++)
        scanf("%d", &p[i]);

    sort(p, p+n);

    for (i=0; i<n; i++) {
        natovar[i] = 1;
        p[i]++;
    }

    for (i=0; i<n; i++) {
        for (j=i+1; j<n; j++) {
            if (!used[j] && natovar[i] + natovar[j] <= p[j]) {
                used[j] = 1;
                natovar[j] += natovar[i];
                natovar[i] = 0;
                break;
            }
        }
    }

    for (i=0; i<n; i++)
        if (natovar[i])
            r++;

    printf("%d\n", r);

    return 0;
}