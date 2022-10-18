#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

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

char s[200005];
int n;

int Cross, Epic, mini_Cross, mini_Epic, maxi_Cross, maxi_Epic;
int fst_mini_Cross, fst_mini_Epic, fst_maxi_Cross, fst_maxi_Epic;
int lst_mini_Cross, lst_mini_Epic, lst_maxi_Cross, lst_maxi_Epic;
inline void work(){
    scanf("%s", s + 1);
    n = strlen(s + 1);
    Cross = Epic = mini_Cross = mini_Epic = maxi_Cross = maxi_Epic = fst_maxi_Cross = fst_maxi_Epic = fst_mini_Epic = fst_mini_Cross = lst_maxi_Cross = lst_maxi_Epic = lst_mini_Epic = lst_mini_Cross = 0;
    for (register int i = 1;i <= n;i ++){
        if(s[i] == 'W') Epic ++;
        if(s[i] == 'S') Epic --;
        if(s[i] == 'A') Cross --;
        if(s[i] == 'D') Cross ++;
        if(mini_Cross > Cross) mini_Cross = Cross, fst_mini_Cross = i;
        if(mini_Cross == Cross) lst_mini_Cross = i;
        if(mini_Epic > Epic) mini_Epic = Epic, fst_mini_Epic = i;
        if(mini_Epic == Epic) lst_mini_Epic = i;
        if(maxi_Cross < Cross) maxi_Cross = Cross, fst_maxi_Cross = i;
        if(maxi_Cross == Cross) lst_maxi_Cross = i;
        if(maxi_Epic < Epic) maxi_Epic = Epic, fst_maxi_Epic = i;
        if(maxi_Epic == Epic) lst_maxi_Epic = i;
    }
    LL ans = 1ll * (maxi_Epic - mini_Epic + 1) * (maxi_Cross - mini_Cross + 1);
    if(1 < -(lst_mini_Cross - fst_maxi_Cross) || 1 < -(lst_maxi_Cross - fst_mini_Cross)) chmin(ans, 1ll * (maxi_Epic - mini_Epic + 1) * (maxi_Cross - mini_Cross));
    if(1 < -(lst_mini_Epic - fst_maxi_Epic) || 1 < -(lst_maxi_Epic - fst_mini_Epic)) chmin(ans, 1ll * (maxi_Epic - mini_Epic) * (maxi_Cross - mini_Cross + 1));
    fprint(ans, 10);
    return;
}

int main(){
    int ___;
    read(___);
    while(___ --) work();
    return 0;
    printf("I AK IOI forever!!!\n");
}