#include <stdio.h>
#define ALPHABET 26

int min(int a, int b)
{ return a < b ? a : b; }

int main()
{
    int s[ALPHABET][2] = {{0}}, t[ALPHABET][2] = {{0}};
    char ch;
    while ((ch = getchar()) != '\n')
        if (ch >= 'a') ++s[ch - 'a'][1];
        else ++s[ch - 'A'][0];
    while ((ch = getchar()) != '\n')
        if (ch >= 'a') ++t[ch - 'a'][1];
        else ++t[ch - 'A'][0];
    int yay = 0, whoops = 0, i;
    for (i = 0; i < ALPHABET; i++) {
        int cut = min(s[i][0], t[i][0]);
        s[i][0] -= cut; t[i][0] -= cut; yay += cut;
        cut = min(s[i][1], t[i][1]);
        s[i][1] -= cut; t[i][1] -= cut; yay += cut;
        cut = min(s[i][0], t[i][1]);
        s[i][0] -= cut; t[i][1] -= cut; whoops += cut;
        cut = min(s[i][1], t[i][0]);
        s[i][1] -= cut; t[i][0] -= cut; whoops += cut;
    }
    printf("%d %d\n", yay, whoops);
    return 0;
}