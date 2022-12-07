#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long

const int maxn = 520;
int h, w, x, xx, y, yy, q;
char s[maxn][maxn];
int H[maxn][maxn], W[maxn][maxn], cal[maxn][maxn];

int main(){
    scanf("%d%d", &h, &w);
    for(int i = 1; i <= h; i++){
        scanf("%s", s[i] + 1);
        for(int j = 1; j <= w; j++){
            cal[i][j] = cal[i][j - 1] + cal[i - 1][j] - cal[i - 1][j - 1] + (s[i][j] == '.' && s[i][j - 1] == '.') + (s[i][j] == '.' && s[i - 1][j] == '.');
            if (i > 1) H[i][j] = H[i][j - 1] + (s[i][j] == '.' && s[i - 1][j] == '.');
            if (j > 1) W[i][j] = W[i - 1][j] + (s[i][j] == '.' && s[i][j - 1] == '.');
        }
    }
    scanf("%d", &q);
    for(int i = 1; i <= q; i++){
        scanf("%d%d%d%d", &x, &y, &xx, &yy);
        printf("%d\n", cal[xx][yy] - cal[x - 1][yy] - cal[xx][y - 1] + cal[x - 1][y - 1] - (H[x][yy] - H[x][y - 1]) - (W[xx][y] - W[x - 1][y]));
    }
  return 0;
}