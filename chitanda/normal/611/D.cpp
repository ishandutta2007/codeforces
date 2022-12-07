#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long
#define M 1000000007

int n;
char s[5100];
int f[5100][5100], g[5100][5100], nex[5100][5100];

void init(){
    for(int i = n - 1; i; i--)
        for(int j = n; j > i; j--)
            if (s[i] != s[j]) nex[i][j] = 0;
            else nex[i][j] = nex[i + 1][j + 1] + 1;
}

bool check(int x, int y, int l){
    if (x < 1) return 0;
    if (nex[x][y] < l && s[x + nex[x][y]] < s[y + nex[x][y]]) return 1;
    return 0;
}

int main(){
    scanf("%d", &n);
    scanf("%s", s + 1);
    s[n + 1] = '*';
    memset(nex, 0, sizeof(nex));
    init();
    for(int i = 1; i <= n; i++){
        for(int j = i - 1; j; j--){
            f[i][j] = g[j][max(j - (i - j) + 1, 0)];
            if (check(j - (i - j) + 1, j + 1, i - j)) (f[i][j] += f[j][j - (i - j)]) %= M;
            if (s[j + 1] == '0') f[i][j] = 0;
            g[i][j] = (g[i][j + 1] + f[i][j]) % M;
        }
        f[i][0] = 1;
        g[i][0] = (g[i][1] + 1) % M;
    }
    printf("%d\n", g[n][0]);
  return 0;
}
/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
                BUG
*/