#include <cstdio>
#include <algorithm>

using namespace std;

int br[20], p[6];

int main()
{
    int i, r, tmp, ok=0;

    for (i=0; i<6; i++)
        scanf("%d", &p[i]);

    for (i=0; i<6; i++)
        br[p[i]]++;

    for (i=0; i<6; i++)
        if (br[p[i]] >= 4)
            ok = 1;

    if (!ok) {
        printf("Alien\n");
        return 0;
    }

    tmp = -1;

    for (i=0; i<6; i++) {
        if (br[p[i]] != 4) {
            br[p[i]]--;
            if (tmp == -1)
                tmp = p[i];
            else if (p[i] != tmp)
                r = 1;
            else
                r = 2;
        }
    }

    if (r == 1)
        printf("Bear\n");
    else
        printf("Elephant\n");

    return 0;
}