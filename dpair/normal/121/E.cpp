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
template <typename T>
inline T mn(T x, T y) {return x < y ? x : y;}
template <typename T>
inline T mx(T x, T y) {return x > y ? x : y;}
template <typename T>
inline void chmin(T &x, T y) {(x > y) && (x = y);}
template <typename T>
inline void chmax(T &x, T y) {(x < y) && (x = y);}
#define MAXN 100005
int n, m;
const int block = 405;
inline int lst(int x){return mn(x * block, n);}
inline int fst(int x){return lst(x - 1) + 1;}
inline int idb(int x){return (x - 1) / block + 1;}
inline bool LST(int x){return x == lst(idb(x));}

int a[MAXN], cnt[(MAXN / block) + 5][10005], tag[(MAXN / block) + 5];
int lucky[35], tt;
bool b[100005];
inline void init(){
    for (register int i = 1;i <= 10000;i ++){
        bool ck = 1;int tmp = i, num;
        while(tmp){
            num = tmp % 10;
            if(num != 4 && num != 7){
                ck = 0;
                break;
            }
            tmp /= 10;
        }
        if(ck) lucky[++ tt] = i, b[i] = 1;
    }
}

int main(){
    init();
    read(n);read(m);
    for (register int i = 1;i <= n;i ++) read(a[i]);
    const int tot = idb(n);
    for (register int i = 1;i <= tot;i ++){
        for (register int j = fst(i);j <= lst(i);j ++){
            cnt[i][a[j]] ++;
        }
    }
    char opt[10];
    int l, r, L, R;
    while(m --){
        scanf("%s", opt);read(l);read(r);
        L = idb(l);R = idb(r);
        if(opt[0] == 'c'){
            int ans = 0;
            if(L == R){
                for (register int i = l;i <= r;i ++) ans += b[a[i] + tag[L]];
                fprint(ans, 10);
            }
            else{
                for (register int i = l;i <= lst(L);i ++) ans += b[a[i] + tag[L]];
                for (register int i = r;i >= fst(R);i --) ans += b[a[i] + tag[R]];
                for (register int i = L + 1;i < R;i ++) {
                    for (register int j = 1;j <= tt;j ++){
                        if(lucky[j] < tag[i]) continue;
                        ans += cnt[i][lucky[j] - tag[i]];
                    }
                }
                fprint(ans, 10);
            }
        }
        else{
            int x;read(x);
            if(L == R){
                for (register int i = l;i <= r;i ++) {
                    cnt[L][a[i]] --;
                    a[i] += x;
                    cnt[L][a[i]] ++;
                }
            }
            else{
                for (register int i = l;i <= lst(L);i ++) {
                    cnt[L][a[i]] --;
                    a[i] += x;
                    cnt[L][a[i]] ++;
                }
                for (register int i = r;i >= fst(R);i --){
                    cnt[R][a[i]] --;
                    a[i] += x;
                    cnt[R][a[i]] ++;
                }
                for (register int i = L + 1;i < R;i ++) tag[i] += x;
            }
        }
    }
}