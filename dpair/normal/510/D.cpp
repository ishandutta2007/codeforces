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

int gcd(int x, int y){return !y? x : gcd(y, x % y);}

map <int, int> dp;

int n;
int a[305], c[305];


int main(){
    read(n);
    int YOLO = 0;
    for (register int i = 1;i <= n;i ++){
        read(a[i]);
        YOLO = gcd(YOLO, a[i]);
    }
    if(YOLO ^ 1) return printf("-1\n"), 0;
    dp[0] = 0;
    for (register int i = 1;i <= n;i ++){
        read(c[i]);
        map <int, int> ch;
        for (auto it = dp.begin();it != dp.end();++ it){
            int num = it -> first, val = it -> second;
            int tar = gcd(num, a[i]);
            if(dp.find(tar) == dp.end()){
                if(ch.find(tar) == ch.end()) ch[tar] = c[i] + val;
                else ch[tar] = min(ch[tar], c[i] + val);
            }
            else if(dp[tar] > val + c[i]) dp[tar] = val + c[i];
        }
        for (auto it = ch.begin();it != ch.end();++ it) dp[it -> first] = it -> second;
    }
    fprint(dp[1], 10);
    return 0;
}