/*
    author: DPair
    language: C++11

    description:
    
*/
#include <bits/stdc++.h>
using namespace std;

namespace IO{
    #define getcha() (SS == TT && (TT = (SS = BB) + fread(BB, 1, 1 << 23, stdin), SS == TT) ? EOF : *SS++)
    char BB[1 << 23], *SS = BB, *TT = BB;
    template <typename T>
    inline void read(T &x){
        x = 0;int fu = 1;
        char c = getcha();
        while(c > 57 || c < 48){
            if(c == 45) fu = -1;
            c = getcha();
        }
        while(c <= 57 && c >= 48){
            x = x * 10 + c - 48;
            c = getcha();
        }
        x *= fu;
    }
    template <typename T, typename ...Args>
    inline void read(T &x, Args &...args){
        read(x);read(args...);
    }
    char out[1 << 22], *Out = out;
    #define flush() fwrite(out, 1, Out - out, stdout)
    inline void putcha(char x) {*Out++ = x;if(Out - out >= (1 << 22)) flush(), Out = out;}
    template <typename T>
    inline void fprint(T x){
        if(x < 0) putcha(45), x = -x;
        if(x > 9) fprint(x / 10);
        putcha(x % 10 + 48);
    }
    template <typename T>
    inline void print(T x){fprint(x);putcha(10);}
    inline void print(const char *ch){while(*ch != '\0') putcha(*(ch ++));}
    inline void put(const char *ch){while(*ch != '\0') putcha(*(ch ++));putcha(10);}
    template <typename T, typename ...Args>
    inline void print(T x, Args ...args){fprint(x);putcha(32);print(args...);}
    template <typename T>
    inline void sprint(T x){fprint(x);putcha(32);}
    template <typename T, typename ...Args>
    inline void sprint(T x, Args ...args){fprint(x);putcha(32);sprint(args...);}
    class AutoFlush{
        public:
            ~AutoFlush(){flush();}
    }__AutoFlush;
} // namespace IO
using namespace IO;

typedef pair <int, int> pi;
typedef long long LL;
map <pi, int> ans;
int it;
map <LL, int> h;
set <pi> s[200005];
int tot;

int n;

inline int gcd(int x, int y){return !y? x : gcd(y, x % y);}

inline pi fix(pi x){
    int g = gcd(x.first, x.second);
    return make_pair(x.first / g, x.second / g);
}

inline pi mid(pi x, pi y){return fix(make_pair(x.first + y.first, x.second + y.second));}

inline void solve(int x, int y, int tag){
    tot += tag;
    LL r = 1ll * x * x + 1ll * y * y;
    if(!h[r]) h[r] = ++ it;
    int p = h[r];

    pi t = make_pair(x, y);
    ans[fix(t)] += tag;
    if(tag < 0) s[p].erase(t);
    for (auto i : s[p]) ans[mid(i, t)] += tag * 2;
    if(tag > 0) s[p].emplace(t);
}

int main(){
    read(n);
    while(n --){
        int opt, x, y;read(opt, x, y);
        if(opt == 1) solve(x, y, 1);
        else if(opt == 2) solve(x, y, -1);
        else print(tot - ans[fix(make_pair(x, y))]);
    }
}