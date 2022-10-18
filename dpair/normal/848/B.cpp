/*
    author: DPair
    language: C++

    description:
    1: CF848B Rooter's Song
    T11900
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
int n, w, h;

typedef pair <int, int> pi;
pi ans[100005];
struct NODE{
    int dir, pos, t, id;
    inline int calc(){return pos - t;}
    inline bool operator < (const NODE &tmp) const{
        return pos < tmp.pos;
    }
}a[100005];

map <int, stack <int> > s[2];

int main(){
    read(n);read(w);read(h);
    for (register int i = 1;i <= n;i ++){
        read(a[i].dir);read(a[i].pos);read(a[i].t);
        a[i].dir --;
        a[i].id = i;
    }
    sort(a + 1, a + n + 1);
    for (register int i = n;i >= 1;i --) s[a[i].dir][a[i].calc()].push(a[i].id);
    for (register int i = 1;i <= n;i ++) s[a[i].dir ^ 1][a[i].calc()].push(a[i].id);
    for (register int i = 1;i <= n;i ++){
        int num = s[a[i].dir][a[i].calc()].top();
        s[a[i].dir][a[i].calc()].pop();
        if(a[i].dir) ans[num] = make_pair(w, a[i].pos);
        else ans[num] = make_pair(a[i].pos, h);
    }
    for (register int i = 1;i <= n;i ++){
        fprint(ans[i].first, 32);
        fprint(ans[i].second, 10);
    }
}