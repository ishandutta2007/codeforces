#include <cstdio>
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
    template <typename T>
    inline void readp(T &x){
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
        if(c == 46) {
            double y = 1;c = getcha();
            while(c <= 57 && c >= 48){
                x = x + (y *= 0.1) * (c - 48);
                c = getcha();
            }
        }
        x *= fu;
    }
    template <typename T, typename ...Args>
    inline void read(T &x, Args &...args){
        read(x);read(args...);
    }
    template <typename T, typename ...Args>
    inline void readp(T &x, Args &...args){
        readp(x);readp(args...);
    }
    inline void readc(char &x){
        char c = getcha();
        while(c == ' ' || c == '\n' || c == '\r') c = getcha();
        x = c;
    }
    inline void reads(char x[], int pos = 0){
        char c = getcha();
        while(c == ' ' || c == '\n' || c == '\r') c = getcha();
        while(c ^ ' ' && c ^ '\n' && c ^ '\r') x[pos ++] = c, c = getcha();
        x[pos] = '\0';
    }
    inline void readl(char x[], int pos = 0){
        char c = getcha();
        while(c == '\n' || c == '\r') c = getcha();
        while(c ^ '\n' && c ^ '\r') x[pos ++] = c, c = getcha();
        x[pos] = '\0';
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
    inline void fprint(T x, char ch){
        fprint(x);putcha(ch);
    }
    inline void prints(char c[]){
        int pos = 0;
        while(c[pos] != '\0') putcha(c[pos ++]);
    }
    inline void prints(char c[], char ch){
        int pos = 0;
        while(c[pos] != '\0') putcha(c[pos ++]);
        putcha(ch);
    }
    inline void prints(const char c[]){
        int pos = 0;
        while(c[pos] != '\0') putcha(c[pos ++]);
    }
    inline void prints(const char c[], char ch){
        int pos = 0;
        while(c[pos] != '\0') putcha(c[pos ++]);
        putcha(ch);
    }
    class AutoFlush{
        public:
            ~AutoFlush(){flush();}
    }__AutoFlush;
} // namespace IO
using namespace IO;
#define MAXN 100005
#define block 350
const int B = MAXN / block;
int n, m;
int pos[MAXN], a[MAXN], t[MAXN];
int bel[MAXN], fst[B], lst[B];

inline void rebuild(int x){
    for (register int i = lst[x];i >= fst[x];-- i){
        if(i + a[i] > lst[x]){
            pos[i] = i + a[i];
            t[i] = 1;
        }
        else{
            pos[i] = pos[i + a[i]];
            t[i] = t[i + a[i]] + 1;
        }
    }
}

inline void query(int x){
    int res = 0;
    while(pos[x] <= n){
        res += t[x];
        x = pos[x];
    }
    while(x + a[x] <= n){
        res ++;
        x += a[x];
    }
    fprint(x, 32);fprint(res + 1, 10);
}

int main(){
    read(n);read(m);
    for (register int i = 1;i <= n;i ++){
        read(a[i]);
        bel[i] = (i - 1) / block + 1;
        if(!fst[bel[i]]) fst[bel[i]] = i;
        lst[bel[i]] = i;
    }
    for (register int i = 1;i <= bel[n];i ++) rebuild(i);
    while(m --){
        int opt, x, y;
        read(opt);read(x);
        if(opt == 1) query(x);
        else read(y), a[x] = y, rebuild(bel[x]);
    }
}