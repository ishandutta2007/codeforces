#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 1<<11;

struct str {
    int val, ind;
    str (int val, int ind) : val(val), ind(ind) {}
    str () {}
} p[MAX];

bool operator < (str a, str b)
{
    return a.val < b.val;
}

int r[3][MAX];

int main()
{
    int i, j, n, tmp, br=0;

    scanf("%d", &n);

    for (i=0; i<n; i++) {
        scanf("%d", &tmp);
        p[i] = str(tmp, i+1);
    }

    sort(p, p+n);

    for (i=0; i<3; i++)
        for (j=0; j<n; j++)
            r[i][j] = p[j].ind;

    for (i=0; i<n-1; i++) {
        if (p[i].val == p[i+1].val) {
            if (!br) {
                br = 1;
                swap(r[1][i], r[1][i+1]);
            }
            else {
                br = 2;
                swap(r[2][i], r[2][i+1]);
            }
        }
    }

    if (br < 2)
        printf("NO\n");
    else {
        printf("YES\n");
        for (i=0; i<3; i++) {
            for (j=0; j<n; j++)
                printf("%d ", r[i][j]);
            printf("\n");
        }
    }

    return 0;
}