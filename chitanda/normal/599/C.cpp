#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
#define ll long long

int n, h[100100];
multiset<int> q;

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", h + i);
        q.insert(h[i]);
    }
    
    int ans = 1, now = 0;
    for(int i = 1; i < n; i++){
        multiset<int>::iterator it = q.find(h[i]);
        q.erase(it);
        now = max(now, *it);
        if (*q.begin() >= now) ans++;
    }

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