#include <cstdio>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

const int MAX = 5010;

char s[MAX];
int polje[MAX][MAX], udesno[MAX][MAX];
vector <int> V;

int main()
{
    int i, j, brred, brstup, poc, kraj, rje=0;

    scanf("%d%d", &brred, &brstup);

    for (i=0; i<brred; i++) {
        scanf("%s", s);
        for (j=0; j<brstup; j++)
            polje[i][j] = s[j] - '0';
        for (poc=0;;) {
            if (poc >= brstup)
                break;
            for (j=poc;; j++) {
                if (!polje[i][j]) {
                    kraj = j;
                    break;
                }
            }
            for (j=poc; j<kraj; j++)
                udesno[i][j] = kraj - j;
            poc = kraj + 1;
        }
    }

    for (i=0; i<brstup; i++) {
        V.clear();
        for (j=0; j<brred; j++)
            V.push_back(udesno[j][i]);
        sort(V.begin(), V.end(), greater<int>());
        for (j=0; j<brred; j++)
            rje = max(rje, (j+1) * V[j]);
    }

    printf("%d\n", rje);

    return 0;
}