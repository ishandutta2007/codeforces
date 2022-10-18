/*
    author: DPair
    language: C++

    description:
    2CF436E Cardboard Box
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
typedef long long LL;
int n, m;
int a[300005], b[300005], c[300005];
struct NODE{
    int val, id;
    NODE (int tmp1, int tmp2) : val(tmp1), id(tmp2) {}
    inline bool operator < (const NODE &tmp) const{
        return val < tmp.val;
    }
    inline bool operator > (const NODE &tmp) const{
        return val > tmp.val;
    }
};

typedef priority_queue <NODE> bh;
typedef priority_queue <NODE, vector <NODE>, greater <NODE> > sh;

bh h1, h2, h5;
sh h3, h4;
LL ans;

inline void to0(int x){
    c[x] = 0;
    h4.push(NODE(a[x], x));
}
inline void to1(int x){
    c[x] = 1;
    h2.push(NODE(a[x], x));
    h3.push(NODE(b[x] - a[x], x));
}
inline void to2(int x){
    c[x] = 2;
    h1.push(NODE(b[x], x));
    h5.push(NODE(b[x] - a[x], x));
}
inline void del(){
    m ++;
    while(!h1.empty() && (c[h1.top().id] ^ 2)) h1.pop();
    while(!h2.empty() && (c[h2.top().id] ^ 1)) h2.pop();
    while(!h3.empty() && (c[h3.top().id] ^ 1)) h3.pop();
    while(!h5.empty() && (c[h5.top().id] ^ 2)) h5.pop();
    int num1 = -0x3f3f3f3f, num2 = -0x3f3f3f3f, num3 = -0x3f3f3f3f, num4 = -0x3f3f3f3f;
    if(!h5.empty()) num3 = h5.top().val;
    if(!h1.empty()){
        if(!h3.empty()) num1 = h1.top().val - h3.top().val;
        if(!h4.empty()) num4 = h1.top().val - h4.top().val;
    }
    if(!h2.empty()) num2 = h2.top().val;
    int p = max(max(num1, num2), max(num3, num4));
    // printf("p = %d\n", p);
    // printf("%d %d %d %d\n", num1, num2, num3, num4);
    ans -= p;
    if(num1 == p){
        to0(h1.top().id);
        h1.pop();
        to2(h3.top().id);
        h3.pop();
    }
    else if(num2 == p){
        to0(h2.top().id);
        h2.pop();
    }
    else if(num3 == p){
        to1(h5.top().id);
        h5.pop();
    }
    else {
        to0(h1.top().id);
        h1.pop();
        to1(h4.top().id);
        h4.pop();
    }

}

int main(){
    read(n);read(m);
    for (register int i = 1;i <= n;i ++){
        read(a[i]);read(b[i]);ans += b[i];
        to2(i);m -= 2;
        while(m < 0) del();
    }
    fprint(ans, 10);
    for (register int i = 1;i <= n;i ++){
        putchar(c[i] + 48);
    }
    putchar(10);
}