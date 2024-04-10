/*
    author: DPair
    language: C++

    description:
    Duel!
*/
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
// int a[100005], b[15], cnt, tot[100005];
// const int m = 6;
int n;

// pair <int, int> c[1000005];
stack <int> s;
int tot = 0;
char opt[1000005][2];
int x[1000005];
vector <int> ans;
int main(){
    read(n);
    for (register int i = 1;i <= (n << 1);i ++){
        scanf("%s", opt[i]);
        if(opt[i][0] == '-') read(x[i]);
    }
    for (register int i = (n << 1);i >= 1;i --){
        if(opt[i][0] == '-'){
            if(s.empty() || s.top() > x[i]) s.push(x[i]);
            else{
                printf("NO\n");
                return 0;
            }
        }
        else {
            if(s.empty()){
                printf("NO\n");
                return 0;
            }
            ans.push_back(s.top());s.pop();
        }
    }
    reverse(ans.begin(), ans.end());
    printf("YES\n");
    for (register int i = 0;i < n;i ++) fprint(ans[i], 32);
    putchar(10);
}