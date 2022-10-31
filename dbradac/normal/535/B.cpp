#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    char s[50];

    scanf("%s", s);

    int polje[10];
    polje[7] = 1;
    polje[4] = 0;

    int tmp=0;
    int rje=0;
    for (int i=0; i<(int) strlen(s); i++)
        rje = rje * 2 + polje[s[i] - '0'];

    for (int i=1; i<(int) strlen(s); i++)
        rje += (1<<i);

    printf("%d\n", rje + 1);

    return 0;
}