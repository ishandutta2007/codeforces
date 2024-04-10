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

template <typename T>
inline T mn(T x, T y) {return x < y ? x : y;}
template <typename T>
inline T mx(T x, T y) {return x > y ? x : y;}
template <typename T>
inline void chmin(T &x, T y) {(x > y) && (x = y);}
template <typename T>
inline void chmax(T &x, T y) {(x < y) && (x = y);}

int n, m;
int a[100005];
int dp[100005], ans;
int stk[100005], tp;


int main(){
    read(n);read(m);
    while(n --){
        int u, v;read(u);read(v);
        a[u] ++;a[v + 1] --;
    }
    for (register int i = 1;i <= m;i ++) a[i] += a[i - 1];
    for (register int i = 1;i <= m;i ++){
        if(!tp || stk[tp] <= a[i]) stk[++ tp] = a[i];
        else{
            int l = 1, r = tp, pos;
            while(l <= r){
                int mid = (l + r) >> 1;
                if(stk[mid] > a[i]) pos = mid, r = mid - 1;
                else l = mid + 1;
            }
            stk[pos] = a[i];
        }
        dp[i] = tp;
    }
    tp = 0;reverse(a + 1, a + m + 1);
    for (register int i = 1;i <= m;i ++){
        if(!tp || stk[tp] <= a[i]) stk[++ tp] = a[i];
        else{
            int l = 1, r = tp, pos;
            while(l <= r){
                int mid = (l + r) >> 1;
                if(stk[mid] > a[i]) pos = mid, r = mid - 1;
                else l = mid + 1;
            }
            stk[pos] = a[i];
        }
        chmax(ans, tp + dp[m - i]);
    }
    fprint(ans, 10);
    return 0;
}