/*
    author: DPair
    language: C++11

    description:

*/
#include <bits/stdc++.h>
using namespace std;

namespace MyMinMax{
    template <typename T>
    inline T mn(T x, T y) {return x < y ? x : y;}
    template <typename T>
    inline T mx(T x, T y) {return x > y ? x : y;}
    template <typename T>
    inline void chmin(T &x, T y) {(x > y) && (x = y);}
    template <typename T>
    inline void chmax(T &x, T y) {(x < y) && (x = y);}
}
using namespace MyMinMax;
namespace IO{
    #define getcha() (SS == TT && (TT = (SS = BB) + fread(BB, 1, 1 << 22, stdin), SS == TT) ? EOF : *SS++)
    char BB[1 << 22], *SS = BB, *TT = BB;
    inline char next_char(){
        char ch = getcha();
        while(ch != '+' && ch != '-' && ch != '?' && !isalpha(ch)) ch = getcha();
        return ch;
    }
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
    template <typename ...Args>
    inline void print(const char *ch, Args ...args){while(*ch != '\0') putcha(*(ch ++));putcha(32);print(args...);}
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
typedef long long LL;
int n, m;
int c1, c2;
typedef pair <int, int> pi;
inline pi rev(pi x){return make_pair(x.second, x.first);}
map <pi, int> h;
int main(){
    read(n, m);
    while(m --){
        char opt = next_char();
        if(opt == '+'){
            int u, v;read(u, v);
            pi e = make_pair(u, v);
            h[e] = next_char();
            if(h[e] && h[rev(e)]){
                ++ c2;
                if(h[e] == h[rev(e)]) ++ c1;
            }
        }
        else if (opt == '-'){
            int u, v;read(u, v);
            pi e = make_pair(u, v);
            if(h[e] && h[rev(e)]){
                -- c2;
                if(h[e] == h[rev(e)]) -- c1;
            }
            h[e] = 0;
        }
        else{
            int k;read(k);
            if(c1) printf("YES\n");
            else if((k & 1) && c2) printf("YES\n");
            else printf("NO\n");
        }
    }
}