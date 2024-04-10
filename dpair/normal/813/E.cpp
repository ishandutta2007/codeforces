#include <bits/stdc++.h>
using namespace std;

template <typename T>
inline void read(T &x){
    x = 0;int fu = 1;
    char c = getchar();
    while(c > 57 || c < 48){
        if(c == 45) fu = -1;
        c = getchar();
    }
    while(c <= 57 && c >= 48){
        x = (x << 3) + (x << 1) + c - 48;
        c = getchar();
    }
    x *= fu;
}
template <typename T>
inline void fprint(T x){
    if(x < 0) putchar(45), x = -x;
    if(x > 9) fprint(x / 10);
    putchar(x % 10 + 48);
}
template <typename T>
inline void fprint(T x, char ch){
    fprint(x);putchar(ch);
}
inline char next_char(){
    char ch = getchar();
    while(ch == 9 || ch == 10 || ch == 32) ch = getchar();
    return ch;
}

int n, m;
#define MAXN 100005
#define block 333
const int B = MAXN / block + 5;
int a[MAXN];
int sig[B][MAXN], cnt[MAXN];
int num[B][B];
int ans;
int bel[MAXN], fst[B], lst[B];
int main(){
    read(n);read(m);
    for (register int i = 1;i <= n;i ++) read(a[i]);
    for (register int i = 1;i <= n;i ++){
        bel[i] = (i - 1) / block + 1;
        if(!fst[bel[i]]) fst[bel[i]] = i;
        lst[bel[i]] = i;
    }
    for (register int i = 1;i <= n;i ++){
        cnt[a[i]] ++;
        if(i == lst[bel[i]]){
            for (register int j = 1;j <= n;j ++) sig[bel[i]][j] = cnt[j];
        }
    }
    memset(cnt, 0, sizeof(cnt));
    for (register int i = 1;i <= bel[n];i ++){
        for (register int j = i;j <= bel[n];j ++){
            num[i][j] = num[i][j - 1];
            for (register int k = fst[j];k <= lst[j];k ++){
                cnt[a[k]] ++;
                if(sig[j - 1][a[k]] - sig[i - 1][a[k]] + cnt[a[k]] <= m) num[i][j] ++;
            }
            for (register int k = fst[j];k <= lst[j];k ++) cnt[a[k]] --;
        }
    }
    int q;read(q);
    while(q --){
        int l, r;read(l);read(r);
        l = (l + ans) % n + 1;
        r = (r + ans) % n + 1;
        if(l > r) swap(l, r);
        int L = bel[l], R = bel[r];
        ans = 0;
        if(L == R){
            for (register int i = l;i <= r;i ++){
                cnt[a[i]] ++;
                if(cnt[a[i]] <= m) ans ++;
            }
            for (register int i = l;i <= r;i ++) cnt[a[i]] --;
            fprint(ans, 10);
        }
        else{
            ans = num[L + 1][R - 1];
            for (register int i = l;i <= lst[L];i ++){
                cnt[a[i]] ++;
                if(sig[R - 1][a[i]] - sig[L][a[i]] + cnt[a[i]] <= m) ans ++;
            }
            for (register int i = fst[R];i <= r;i ++){
                cnt[a[i]] ++;
                if(sig[R - 1][a[i]] - sig[L][a[i]] + cnt[a[i]] <= m) ans ++;
            }
            for (register int i = l;i <= lst[L];i ++) cnt[a[i]] --;
            for (register int i = fst[R];i <= r;i ++) cnt[a[i]] --;
            fprint(ans, 10);
        }
    }
}