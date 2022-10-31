#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
    int row, col, n;
    scanf("%d%d%d", &row, &col, &n);
    int a[row + 1][col + 1];
    for(int j = 1; j <= row; j++)
        for(int k = 1; k <= col ; k++)
            scanf("%d", &a[j][k]);
    char cmd[4];
    int x, y;
    int r[row + 1], c[col + 1];
    for(int k = 1; k <= row; k++) r[k] = k;
    for(int k = 1; k <= col; k++) c[k] = k;
    while(n--)
    {
        scanf("%s%d%d", cmd, &x, &y);
        switch(cmd[0])
        {
            case 'r':
            {
                swap(r[x], r[y]);
                break;
            }
            case 'c':
            {
                swap(c[x], c[y]);
                break;
            }
            case 'g':
            {
                printf("%d\n",a[r[x]][c[y]]);
                break;
            }
        }

    }
    return 0;
}