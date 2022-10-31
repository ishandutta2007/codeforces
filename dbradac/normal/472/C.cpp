#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int MAX = 1<<17;

string s[2][MAX];
char ss[60];

int main()
{
    int n, i, j, ne=0, tmp;
    string zadnji;

    scanf("%d", &n);

    for (i=0; i<n; i++) {
        for (j=0; j<2; j++) {
            scanf(" %s", ss);
            s[j][i] = ss;
        }
        if (s[0][i] > s[1][i])
            swap(s[0][i], s[1][i]);
    }

    for (i=0; i<n; i++) {
        scanf("%d", &tmp); tmp--;
        if (!i)
            zadnji = s[0][tmp];
        else {
            if (s[0][tmp] > zadnji)
                zadnji = s[0][tmp];
            else if (s[1][tmp] > zadnji)
                zadnji = s[1][tmp];
            else {
                ne = 1;
                break;
            }
        }
    }

    if (!ne)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}