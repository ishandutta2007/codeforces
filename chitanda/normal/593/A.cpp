#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long

int n, a[200], b[200][200], cal[200];
char s[2000];

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%s", s + 1);
        int l = strlen(s + 1);
        memset(cal, 0, sizeof(cal));
        for(int j = 1; j <= l; j++)
            cal[s[j]] = 1;
        int tt = 0;
        for(int j = 'a'; j <= 'z'; j++)
            if (cal[j]) tt++;
        if (tt > 2) continue;
        else if (tt == 1) a[s[1]] += l;
        else{
            for(int j = 2; j <= l; j++)
                if (s[j] != s[1]) { b[s[1]][s[j]] += l; break; }
        }
    }
    int ans = 0;
    for(int i = 'a'; i < 'z'; i++)
        for(int j = i + 1; j <= 'z'; j++)
            ans = max(ans, a[i] + a[j] + b[i][j] + b[j][i]);
    printf("%d\n", ans);    
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