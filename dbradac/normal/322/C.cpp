#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char ss[105];

int main()
{
    int i, x, y, l, ukx, uky, a, b, rez=0;
    char rje[2][5] = { "No", "Yes" };

    scanf("%d%d%s", &a, &b, ss);
    l = strlen(ss);

    for (i=x=y=0; i<l; i++) {
        if (ss[i] == 'U')
            y++;
        else if (ss[i] == 'D')
            y--;
        else if (ss[i] == 'L')
            x--;
        else
            x++;
    }

    ukx = x;
    uky = y;

    for (i=x=y=0; i<l; i++) {
        if (!ukx) {
            if (!uky) {
                if (x == a && y == b)
                    rez = 1;
            }
            else {
                if (x == a && y % uky == b % uky && (b-y) / uky >= 0)
                    rez = 1;
            }
        }
        else {
            if (!uky) {
                if (x % ukx == a % ukx && y == b && (a-x) / ukx >= 0)
                    rez = 1;
            }
            else {
                if (x % ukx == a % ukx && y % uky == b % uky)
                    if ((a-x) / ukx >= 0 && (a-x) / ukx == (b-y) / uky)
                        rez = 1;
            }
        }

        if (ss[i] == 'U')
            y++;
        else if (ss[i] == 'D')
            y--;
        else if (ss[i] == 'L')
            x--;
        else
            x++;

        if (!ukx) {
            if (!uky) {
                if (x == a && y == b)
                    rez = 1;
            }
            else {
                if (x == a && y % uky == b % uky && (b-y) / uky >= 0)
                    rez = 1;
            }
        }
        else {
            if (!uky) {
                if (x % ukx == a % ukx && y == b && (a-x) / ukx >= 0)
                    rez = 1;
            }
            else {
                if (x % ukx == a % ukx && y % uky == b % uky)
                    if ((a-x) / ukx >= 0 && (a-x) / ukx == (b-y) / uky)
                        rez = 1;
            }
        }
    }

    printf("%s\n", rje[rez]);

    return 0;
}