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
template <typename T, typename ...Args>
inline void read(T &x, Args &...args){
    read(x);read(args...);
}

struct Dat{
    int pos, len, num;
    Dat(int pos, int len, int num) : pos(pos), len(len), num(num) {}
    inline bool operator < (const Dat &tmp) const{return len > tmp.len || (len == tmp.len && pos < tmp.pos);}
};

struct Tri{
    int pos, len, num;
    Tri(int pos, int len, int num) : pos(pos), len(len), num(num) {}
    inline bool operator < (const Tri &tmp) const{return pos < tmp.pos;}
};

set <Dat> s;
set <Tri> p;

inline Dat dat(Tri x){return Dat(x.pos, x.len, x.num);}
inline Tri tri(Dat x){return Tri(x.pos, x.len, x.num);}

#define MAXN 200005
int n;
int a[MAXN];
int main(){
    read(n);
    for (int i = 1;i <= n;++ i) read(a[i]);
    int pos = 1, num = a[1], len = 0;
    while(pos <= n){
        while(a[pos] == num) ++ pos, ++ len;
        s.emplace(Dat(pos - len, len, num));
        p.emplace(Tri(pos - len, len, num));
        len = 0;num = a[pos];
    }
    int ans = 0;
    while(!s.empty()){
        ++ ans;
        auto it = s.begin();
        s.erase(it);Tri P(it -> pos, it -> len, it -> num);
        p.erase(P);
        auto pp = p.lower_bound(P);
        Tri p1(0, 0, 0), p2(0, 0, 0);
        if(pp == p.end()) p2 = Tri(-1, 0, 0);
        else p2 = *pp;
        if(pp == p.begin()) p1 = Tri(-1, 0, 0);
        else p1 = *(-- pp);
        if(p1.pos == -1 || p2.pos == -1) continue;
        if(p1.num ^ p2.num) continue;
        int Len = p1.len + p2.len;
        it = s.find(dat(p2));
        s.erase(it);
        it = s.find(dat(p1));
        s.erase(it);
        s.emplace(Dat(p1.pos, Len, p1.num));
        auto itt = p.find(p2);
        p.erase(itt);
        itt = p.find(p1);
        p.erase(itt);
        p.emplace(Tri(p1.pos, Len, p1.num));
    }
    fprint(ans, 10);
}