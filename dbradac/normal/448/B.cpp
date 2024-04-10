#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX = 105;

char a[MAX], b[MAX];
int ima[2][26];

int main()
{
    int la, lb, i, ne=0, ind, da=0, n1, n2;

    scanf("%s%s", a, b);

    la = strlen(a);
    lb = strlen(b);

    for (i=0; i<la; i++)
        ima[0][a[i]-'a']++;

    for (i=0; i<lb; i++)
        ima[1][b[i]-'a']++;

    for (i=0; i<26; i++)
        if (ima[0][i] < ima[1][i])
            ne = 1;

    if (ne)
        printf("need tree\n");
    else {
        ne = 0;
        for (i=ind=0; i<lb; i++) {
            for (da=0; ind<la; ind++)
                if (a[ind] == b[i]) {
                    da = 1;
                    ind++;
                    break;
                }
            if (!da) {
                ne = 1;
                break;
            }
        }

        n1 = ne;

        ne = 0;
        for (i=0; i<26; i++)
            if (ima[0][i] != ima[1][i])
                ne = 1;

        n2 = ne;

        if (n1 && n2)
            printf("both\n");
        else if (n1)
            printf("array\n");
        else
            printf("automaton\n");
    }

    return 0;
}