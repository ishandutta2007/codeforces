#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long

int ansB = 10, ansW = 10;
char s[10][10];

int main(){
    for(int i = 1; i <= 8; i++) scanf("%s", s[i] + 1);
    for(int j = 1; j <= 8; j++){
        for(int i = 1; i <= 8; i++)
            if (s[i][j] == 'B') break;
            else if (s[i][j] == 'W') ansW = min(ansW, i - 1);
        for(int i = 8; i >= 1; i--)
            if (s[i][j] == 'W') break;
            else if (s[i][j] == 'B') ansB = min(ansB, 8 - i);
    }
    printf("%c", ansW <= ansB ? 'A' : 'B');
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