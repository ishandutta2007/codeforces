#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int N = 8;

char board[N + 2][N + 2];

int main() {
    int x1, y1, x2, y2;
    int test;
    scanf("%d", &test);
    while(test--) {
        x1 = -1;
        for(int i = 0; i < N; i++) {
            scanf("%s", board[i]);  
            for(int j = 0; j < N; j++) {
                if (board[i][j] == 'K') {
                    if (x1 == -1) {
                        x1 = i;
                        y1 = j;
                    } else {
                        x2 = i;
                        y2 = j;
                    }
                }
            }
        }
        bool flag = false;
        for(int i = 0; i < N && !flag; i++)
            for(int j = 0; j < N && !flag; j++)
                if (board[i][j] != '#') {
                    if (abs(x1 - i) % 2 != 0 || abs(y1 - j) % 2 != 0 || abs(x2 - i) % 2 != 0 || abs(y2 - j) % 2 != 0)
                        continue;
                    int sx = abs(x1 - i) / 2 % 2, sy = abs(y1 - j) / 2 % 2;
                    int tx = abs(x2 - i) / 2 % 2, ty = abs(y2 - j) / 2 % 2;
                    if (sx != sy || tx != ty || sx != tx)
                        continue;
                    //printf("%d %d\n", i, j); 
                    flag = 1;
                }
        printf("%s\n", flag ? "YES" : "NO");
    }
}