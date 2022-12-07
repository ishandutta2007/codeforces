#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long

char s[200100];
int n, m;
struct node{
    char ch;
    int to;
}p[600100];
int tot;
int now[200];
char x, y;

node find(int x){
    if (p[x].to != x) p[x] = find(p[x].to);
    return p[x];
}

int main(){
    scanf("%d%d", &n, &m);
    scanf("%s\n", s + 1);
    for(int i = 'a'; i <= 'z'; i++){
        now[i] = ++tot;
        p[tot].ch = i;
        p[tot].to = tot;
    }
    for(int i = 1; i <= m; i++){
        scanf("%c %c\n", &x, &y);
        p[++tot].ch = y;
        p[tot].to = tot;
        p[now[x]].to = tot;

        p[++tot].ch = x;
        p[tot].to = tot;
        p[now[y]].to = tot;
        now[y] = tot - 1;
        now[x] = tot;
    }
    for(int i = 1; i <= n; i++){
        s[i] = find(s[i] - 'a' + 1).ch;
    }
    printf("%s", s + 1);
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