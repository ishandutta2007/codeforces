//wtf??
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
    template <typename T, typename ...Args>
    inline void print(T x, Args ...args){fprint(x);putcha(32);print(args...);}
    class AutoFlush{
        public:
            ~AutoFlush(){flush();}
    }__AutoFlush;
} // namespace IO
using namespace IO;

#define MAXN 200005
#define MEMORY 40000005
typedef long long LL;
int n, k;
int a[MAXN];
LL ans = 0;
int t[MEMORY], lc[MEMORY], rc[MEMORY], tot;

#define lson lc[rt], l, mid
#define rson rc[rt], mid + 1, r

void modify(int &rt, int l, int r, int x, int y){
    if(!rt) rt = ++ tot;
    t[rt] += y;
    if(l == r) return ;
    int mid = (l + r) >> 1;
    if(x <= mid) modify(lson, x, y);
    else modify(rson, x, y);
}

int query(int rt, int l, int r, int x, int y){
    if(!rt) return 0;
    if(x <= l && r <= y) return t[rt];
    int mid = (l + r) >> 1, ret = 0;
    if(x <= mid) ret = query(lson, x, y);
    if(y > mid) ret += query(rson, x, y);
    return ret;
}

#define LSON rt << 1, l, mid
#define RSON rt << 1 | 1, mid + 1, r

int root[MAXN << 2];

void Modify(int rt, int l, int r, int x, int y, int z){
    modify(root[rt], 1, n, y, z);
    if(l == r) return ;
    int mid = (l + r) >> 1;
    if(x <= mid) Modify(LSON, x, y, z);
    else Modify(RSON, x, y, z);
}

int Query(int rt, int l, int r, int x, int y, int xx, int yy){
    if(x <= l && r <= y) return query(root[rt], 1, n, xx, yy);
    int mid = (l + r) >> 1, ret = 0;
    if(x <= mid) ret = Query(LSON, x, y, xx, yy);
    if(y > mid) ret += Query(RSON, x, y, xx, yy);
    return ret;
}
int main(){
    read(n, k);
    for (int i = 1;i <= n;++ i) Modify(1, 1, n, i, i, 1), a[i] = i;
    while(k --){
        int l, r;read(l, r);
        if(l == r) {
            print(ans);
            continue;
        }
        if(l > r) l ^= r ^= l ^= r;
        if(a[l] > a[r]) ans -= ((Query(1, 1, n, l, r, a[r], a[l]) - 2) << 1) + 1;
        else ans += ((Query(1, 1, n, l, r, a[l], a[r]) - 2) << 1) + 1;
        Modify(1, 1, n, l, a[l], -1);Modify(1, 1, n, r, a[r], -1);
        a[l] ^= a[r] ^= a[l] ^= a[r];
        Modify(1, 1, n, l, a[l], 1);Modify(1, 1, n, r, a[r], 1);
        print(ans);
    }
}