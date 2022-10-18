#pragma GCC optimize(2, 3, "Ofast")
#include <bits/stdc++.h>
using namespace std;

int n;
int a[5005], ans, nxt;
unordered_map <int, int> re;
int cnt[5005];
inline void fix(int &x){
    int fu = 1;
    if(x < 0) fu = -1, x = -x;
    for (register int i = 2;i * i <= x;i ++)
        while(x && x % (i * i) == 0)
            x /= (i * i);
    x = x * fu;
}
inline void add(int x){
    if(!cnt[x]) ans ++;
    cnt[x] ++;
}
int ret[5005];
int main(){
    scanf("%d", &n);
    re[0] = ++ nxt;
    for (register int i = 1;i <= n;i ++){
        scanf("%d", &a[i]);
        fix(a[i]);if(!re[a[i]]) re[a[i]] = ++ nxt;
    }
    for (register int i = 1;i <= n;i ++){
        memset(cnt, 0, sizeof(cnt));ans = 0;
        for (register int j = i;j <= n;j ++){
            add(re[a[j]]);
            if(cnt[re[0]] && ans > 1) ret[ans - 1] ++;
            else ret[ans] ++;
        }
    }
    for (register int i = 1;i <= n;i ++) printf("%d%c", ret[i], 32);
    putchar(10);
    return 0;
}