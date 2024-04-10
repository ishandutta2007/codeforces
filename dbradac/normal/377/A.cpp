#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 505;

int polje[MAX][MAX], bio[MAX][MAX], uk, brred, brstup;
int k1[4] = {1, 0, -1, 0}, k2[4] = {0, 1, 0, -1};
char s[MAX];

int Moze(int r, int s)
{
    if (r < 0 || s < 0 || r >= brred || s >= brstup || bio[r][s] || !polje[r][s])
        return 0;
    return 1;
}

void Dfs(int red, int stup)
{
    int i;

    if (!uk)
        return;

    for (i=0; i<4; i++) {
        if (Moze(red + k1[i], stup + k2[i])) {
            bio[red + k1[i]][stup + k2[i]] = 1;
            uk--;
            if (!uk)
                return;
            Dfs(red + k1[i], stup + k2[i]);
            if (!uk)
                return;
        }
    }
}

int main()
{
    int i, j, mak, slob=0, done=0;

    scanf("%d%d%d", &brred, &brstup, &mak);

    for (i=0; i<brred; i++) {
        scanf("%s", s);
        for (j=0; j<brstup; j++) {
            if (s[j] == '#')
                polje[i][j] = 0;
            else {
                polje[i][j] = 1;
                slob++;
            }
        }
    }

    uk = slob - mak - 1;

    for (i=0; i<brred; i++) {
        for (j=0; j<brstup; j++) {
            if (polje[i][j]) {
                bio[i][j] = 1;
                Dfs(i, j);
                done = 1;
                break;
            }
        }
        if (done)
            break;
    }

    for (i=0; i<brred; i++) {
        for (j=0; j<brstup; j++) {
            if (polje[i][j] && !bio[i][j])
                printf("X");
            else if (!polje[i][j])
                printf("#");
            else
                printf(".");
        }
        printf("\n");
    }

    return 0;
}