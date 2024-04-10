#include <cstdio>
#include <algorithm>
#include <cstring>
using std :: sort;
using std :: lower_bound;
using std :: unique;
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


typedef long long LL;
int tot;

struct BIT{
    int c[100005];
    inline void init(){memset(c, 0, sizeof(c));}
    BIT(){init();}
    inline int lowbit(int x){return x & -x;}
    inline void modify(int x, int y){for (;x <= tot;x += lowbit(x)) c[x] += y;}
    inline int query(int x){int ret = 0;for (;x;x -= lowbit(x)) ret += c[x];return ret;}
}t, s;
LL k;
int n;
int a[100005], b[100005];

int main(){
    read(n, k);
    for (int i = 1;i <= n;++ i) read(a[i]), b[i] = a[i];
    sort(b + 1, b + n + 1);
    tot = unique(b + 1, b + n + 1) - b - 1;
    for (int i = 1;i <= n;++ i) a[i] = lower_bound(b + 1, b + tot + 1, a[i]) - b;
    LL ans = 0;
    for (int i = 1;i <= n;++ i){
        t.modify(a[i], 1);
        ans += i - t.query(a[i]);
    }
    if(ans <= k){
        print(1ll * n * (n - 1) >> 1);
        return 0;
    }
    t.modify(a[1], -1);
    ans -= t.query(a[1] - 1);
    LL res = 0;
    for (int l = 1, r = 2;l <= n;++ l){
        s.modify(a[l], 1);
        ans += t.query(a[l] - 1);
        ans += l - s.query(a[l]);
        while(r <= n && ans > k){
            t.modify(a[r], -1);
            ans -= t.query(a[r] - 1);
            ans -= l - s.query(a[r]);
            ++ r;
        }
        if(r > n) break;
        res += n - r + 1;
    }
    print(res);
}