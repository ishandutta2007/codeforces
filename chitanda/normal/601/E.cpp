#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long
#define p 10000019
#define q 1000000007
#define mid ((l + r) >> 1)
#define ls (t << 1)
#define rs ((t << 1) | 1)
#define pb push_back

const int maxn = 40000, maxm = 2100000, maxk = 1013;
int n, k, Q, w[maxn], v[maxn], ins[maxn], del[maxn], ty, x;
bool isq[maxn];
vector<int> tag[maxm];

void modify(int t, int l, int r, int x, int y, int o){
    if (l >= x && r <= y){
        tag[t].pb(o);
        return;
    }
    if (x <= mid) modify(ls, l, mid, x, y, o);
    if (y > mid) modify(rs, mid + 1, r, x, y, o);
}

void ask(int t, int l, int r, int s[]){
    int st[1010]; for(int i = 1; i <= k; i++) st[i] = s[i];
    for(int i = 0; i < (int)tag[t].size(); i++){
        int o = tag[t][i];
        for(int j = k; j >= w[o]; j--)
            st[j] = max(st[j], st[j - w[o]] + v[o]);
    }
    if (l == r){
        if (isq[l]){
            int ans = 0;
            for(int i = 1, pp = 1; i <= k; i++, pp = (ll)pp * p % q)
                ans = (ans + (ll)pp * st[i] % q) % q;
            printf("%d\n", ans);
        }
        return;
    }
    ask(ls, l, mid, st);
    ask(rs, mid + 1, r, st);
}

int main(){
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++){
        scanf("%d%d", v + i, w + i);
        ins[i] = i;
    }
    scanf("%d", &Q);
    int tim = n + 1;
    for(int i = 1; i <= Q; i++, tim++){
        scanf("%d", &ty);
        if (ty == 1){
            n++;
            scanf("%d%d", v + n, w + n);
            ins[n] = tim;
        }else if (ty == 2){
            scanf("%d", &x);
            del[x] = tim;
        }else isq[tim] = 1;
    }
    for(int i = 1; i <= n; i++)
        if (!del[i]) del[i] = tim;
    for(int i = 1; i <= n; i++)
        modify(1, 1, tim, ins[i], del[i], i);
    int s[1010]; memset(s, 0, sizeof(s));
    ask(1, 1, tim, s);
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