#include <stdio.h>
#define BSIZE 8

int main()
{
    char board[BSIZE][BSIZE + 2];
    int i, j;
    for (i = 0; i < BSIZE; ++i) gets(board[i]);
    int a = 0x7fffffff, b = 0x7fffffff;
    for (i = 0; i < BSIZE; ++i) {
        // Scan downwards
        for (j = 0; j < BSIZE && board[j][i] == '.'; ++j);
        if (j < BSIZE && board[j][i] == 'W' && j < a) a = j;
        // Scan upwards
        for (j = BSIZE - 1; j >= 0 && board[j][i] == '.'; --j);
        if (j >= 0 && board[j][i] == 'B' && BSIZE - 1 - j < b) b = BSIZE - 1 - j;
    }
    putchar(a <= b ? 'A' : 'B');
    return 0;
}