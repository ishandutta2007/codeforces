#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long

int n, a, b, c, t1, t2, t3, t4;
bool ok[200100];
int t[200100], cal[8];

int greedy(int o, int x = 0, int y = 0){
    int ta = 0;
    for(int i = 1; i <= n; i++)
        if (t[i] > o && !ok[i]) { ta++; ok[i] = 1; }
    int tt = ta;
    for(int i = 1; i <= n; i++)
        if (t[i] <= x && t[i] > y && !ok[i] && ta) { ta--; ok[i] = 1; }
    for(int i = 1; i <= n; i++)
        if (t[i] <= y && !ok[i] && ta) { ta--; ok[i] = 1; }
    return tt;
}

bool check(int d){
    if (d < t4) return 0;
    int x = d, y = d, z = d;
    if (a + b > c){
        x -= t4, y -= t4;
        if (x + z < t3) return 0;
        if (z < t3){
            x -= t3 - z, y -= t3 - z;
            z = 0;
        }else z -= t3;
    }else{
        z -= t4;
        if (x + z < t3) return 0;
        x -= t3 - min(t3, z), y -= t3 - min(t3, z);
        z -= min(z, t3);
        if (x < 0) return 0;
    }
    y += z;
    if (y < t2) return 0;
    y -= t2;
    x += y;
    if (x < t1) return 0;
    return 1;
}

int main(){
    scanf("%d%d%d%d", &n, &a, &b, &c);
    for(int i = 1; i <= n; i++)
        scanf("%d", t + i);
    for(int i = 1; i <= n; i++)
        if(a + b + c < t[i]) { printf("-1\n"); return 0; }
    if(a > b) swap(a, b);
    if(a > c) swap(a, c);
    if(b > c) swap(b, c);

    memset(ok, 0, sizeof(ok));
    int d = 0;
    d += greedy(b + c);
    d += greedy(a + c, a);
    d += greedy(max(c, a + b), b, a);
    int l = -1, r = n;
    for(int i = 1; i <= n; i++)
        if (!ok[i]){
            if (t[i] <= a) t1++;
            else if (t[i] <= b) t2++;
            else if (t[i] <= min(a + b, c)) t3++;
            else t4++;
        }
    while(l + 1 < r){
        int mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid;
    }
    printf("%d\n", d + r);
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