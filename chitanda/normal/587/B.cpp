#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long
#define M 1000000007

const int maxn = 1000100;
int n, k, ans, N, a[maxn], w[maxn], f[maxn], c[maxn];
ll l;

bool cmp(int x, int y){
    return a[x] < a[y];
}

void inc(int &a, int b){
    a += b;
    if (a >= M) a -= M;
}

int main(){
    scanf("%d%I64d%d", &n, &l, &k);
    for(int i = 0; i < n; i++) scanf("%d", a + i), w[i] = i;

    sort(w, w + n, cmp);
    int now = a[w[0]]; a[w[0]] = 1;
    for(int i = 1; i < n; i++)
        if (a[w[i]] == now) a[w[i]] = a[w[i - 1]];
        else now = a[w[i]], a[w[i]] = a[w[i - 1]] + 1;
    N = a[w[n - 1]];

    for(int i = 1; i <= N; i++) c[i] = 1;
    for(int i = 1; i <= k; i++){
        for(int j = 0; j < n; j++){
            f[j] = c[a[j]];
            ll num = l / n;
            if (j < l % n) num++;
            num -= i - 1;
            num = max(0LL, num);
            num %= M;
            inc(ans, num * f[j] % M);
        }
        for(int j = 1; j <= N; j++) c[j] = 0;
        for(int j = 0; j < n; j++) inc(c[a[j]], f[j]);
        for(int j = 1; j <= N; j++) inc(c[j], c[j - 1]);
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