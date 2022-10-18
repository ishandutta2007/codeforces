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
inline char next_char(){
    char ch = getchar();
    while(ch == 9 || ch == 10 || ch == 32) ch = getchar();
    return ch;
}
struct NODE{
    int l, r;
    mutable int val;
    NODE (int tmp1, int tmp2 = -1, int tmp3 = 0) : l(tmp1), r(tmp2), val(tmp3){}
    inline bool operator < (const NODE &tmp) const{return l < tmp.l;}
};
set <NODE> ODT;
typedef set<NODE> :: iterator IT;
inline IT split(int x){
    IT it = ODT.lower_bound(NODE(x));
    if(it != ODT.end() && it -> l == x) return it;
    -- it;
    int L = it -> l, R = it -> r;
    int Val = it -> val;
    ODT.erase(it);
    ODT.insert(NODE(L, x - 1, Val));
    return ODT.insert(NODE(x, R, Val)).first;
}
inline void assign(int l, int r, int val){
    IT R = split(r + 1), L = split(l);
    ODT.erase(L, R);
    ODT.insert(NODE(l, r, val));
}
inline int query(int l, int r){
    IT R = split(r + 1), L = split(l);
    LL ret = 0;
    while(L != R){
        ret = ret + (L -> r - L -> l + 1) * L -> val;
        ++ L;
    }
    return ret;
}
int n, m;
int main(){
    read(n);read(m);
    ODT.insert(NODE(1, n, 1));
    int ans = n;
    while(m --){
        int opt, l, r;read(l);read(r);
        read(opt);
        int num = query(l, r); 
        if(opt == 1){
            ans -= num;
            assign(l, r, 0);
        }
        if(opt == 2){
            ans += r - l + 1 - num;
            assign(l, r, 1);
        }
        fprint(ans, 10);
    }
}