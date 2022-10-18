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

pair <int, int> a[200005];
int dp[200005];
int n;

int stk[200005], tp;

int main(){
    read(n);
    for (register int i = 1;i <= n;i ++){
        read(a[i].first);read(a[i].second);
    }
    sort(a + 1, a + n + 1);
    for (register int i = 1;i <= n;i ++){
        if(!tp) stk[++ tp] = a[i].first + a[i].second;
        else{
            if(a[i].first - a[i].second >= stk[tp]) stk[++ tp] = a[i].first + a[i].second;
            else{
                int l = 1, r = tp, pos = -1;
                while(l <= r){
                    int mid = (l + r) >> 1;
                    if(stk[mid] >= a[i].first + a[i].second) pos = mid, r = mid - 1;
                    else l = mid + 1;
                }
                if(~pos) stk[pos] = a[i].first + a[i].second;
            }
        }
    }
    fprint(tp, 10);
    return 0;
}