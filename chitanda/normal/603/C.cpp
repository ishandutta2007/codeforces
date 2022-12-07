#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long

int n, k, a[100100];

int get(int x){
    if (x == 0) return 0;
    if (x >= 5 && (x & 1)) return 0;
    if (x == 1 || x == 3) return 1;
    if (x == 2) return 0;
    if (x == 4) return 2;
    if (get(x / 2) == 1) return 2;
    else return 1;
}

int main(){
    scanf("%d%d", &n, &k);
    k %= 2;
    for(int i = 1; i <= n; i++) scanf("%d", a + i);
    int sg = 0;
    if (k == 0){
        for(int i = 1; i <= n; i++){
            if (a[i] <= 2) sg ^= a[i];
            else sg ^= ((a[i] & 1) ^ 1);
        }
    }else{
        for(int i = 1; i <= n; i++){
            sg ^= get(a[i]);
        }
    }
    if (sg) printf("Kevin");
    else printf("Nicky");
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