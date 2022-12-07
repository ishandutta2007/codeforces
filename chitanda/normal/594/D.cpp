#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long
#define M 1000000007

const int N = 1000000;
const int maxn = N + 10;
int n, Q, tot, a[maxn], pri[maxn], s[maxn], la[maxn], c[maxn], lap[maxn], ans[maxn];
bool nop[maxn];
vector<int> g[maxn];
struct node{
    int l, r, w;
}q[maxn];

void prepare(){
    ll num;
    for(int i = 2; i <= N; i++){
        if (!nop[i]) pri[++tot] = i, lap[i] = tot;
        for(int j = 1; j <= tot && (num = (ll)i * pri[j]) <= N; j++){
            nop[num] = 1;
            lap[num] = j;
            if (i % pri[j] == 0) break;
        }
    }
}

int pow(int a, int b){
    int ans = 1;
    for(; b; b >>= 1, a = (ll)a * a % M)
        if (b & 1) ans = (ll)ans * a % M;
    return ans;
}

int inv(int x){
    return pow(x, M - 2);
}

bool cmp(node a, node b){
    return a.r < b.r;
}

void modify(int x, int v){
    if (!x) return;
    for(; x <= N; x += x & (-x)) c[x] = (ll)c[x] * v % M;
}

int ask(int x){
    int ans = 1;
    for(; x; x -= x & (-x)) ans = (ll)ans * c[x] % M;
    return ans;
}

int main(){
    prepare();

    scanf("%d", &n);
    s[0] = 1;
    for(int i = 1; i <= n; i++){
        scanf("%d", a + i);
        int x = a[i];
        while(x > 1){
            int y = lap[x];
            while(x % pri[y] == 0) x /= pri[y];
            g[i].push_back(y);
        }
        s[i] = (ll)s[i - 1] * a[i] % M;
    }

    scanf("%d", &Q);
    for(int i = 1; i <= Q; i++){
        scanf("%d%d", &q[i].l, &q[i].r);
        q[i].w = i;
        ans[i] = (ll)s[q[i].r] * inv(s[q[i].l - 1]) % M;
    }

    sort(q + 1, q + Q + 1, cmp);
    for(int i = 1; i <= N; i++) c[i] = 1;
    for(int i = 1, now = 1; i <= n; i++){
        for(int j = 0; j < g[i].size(); j++){
            modify(la[g[i][j]], (ll)pri[g[i][j]] * inv(pri[g[i][j]] - 1) % M);
            modify(i, (ll)inv(pri[g[i][j]]) * (pri[g[i][j]] - 1) % M);
            la[g[i][j]] = i;
        }
        while(q[now].r == i){
            int tmp = ask(i);
            tmp = (ll)tmp * inv(ask(q[now].l - 1)) % M;
            ans[q[now].w] = (ll)ans[q[now].w] * tmp % M;
            now++;
        }
    }
    for(int i = 1; i <= Q; i++) printf("%d\n", ans[i]);
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