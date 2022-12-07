#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
#define ll long long

int n;
int c[620];
int f[520][510];

int work(int l, int r, int k){
    if (l > r) return k;
    if (f[l][r]) return f[l][r];
    f[l][r] = r - l + 1;
    f[l][r] = min(f[l][r], work(l + 1, r, 0) + 1);
    for(int i = l + 1; i <= r; i++)
        if (c[i] == c[l]) f[l][r] = min(f[l][r], work(l + 1, i - 1, 1) + work(i + 1, r, 0));
    return f[l][r];
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", c + i);
    printf("%d\n", work(1, n, 0));
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