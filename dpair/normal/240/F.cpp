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

#define MAXN 100005

char a[MAXN];
int n, m;

struct Dat{
    int cnt[27];
    inline void init(){memset(cnt, 0, sizeof(cnt));}
    inline Dat operator + (const Dat &b) const{
        Dat ret;
        for (register int i = 0;i < 26;i ++) ret.cnt[i] = cnt[i] + b.cnt[i];
        return ret;
    }
}t[MAXN << 2];

int lazy[MAXN << 2];

inline void pushup(int rt){t[rt] = t[rt << 1] + t[rt << 1 | 1];}
inline void update(int rt, int l, int r, int x){
    lazy[rt] = x;
    t[rt].init();
    t[rt].cnt[x] = r - l + 1;
}
#define LSON rt << 1, l, mid
#define RSON rt << 1 | 1, mid + 1, r
inline void pushdown(int rt, int l, int r){
    if(~lazy[rt]){
        int mid = (l + r) >> 1;
        update(LSON, lazy[rt]);
        update(RSON, lazy[rt]);
        lazy[rt] = -1;
    }
}
void build(int rt, int l, int r){
    lazy[rt] = -1;
    if(l == r){
        t[rt].init();
        t[rt].cnt[a[l] - 'a'] = 1;
        return ;
    }
    int mid = (l + r) >> 1;
    build(LSON);build(RSON);
    pushup(rt);
}
void modify(int rt, int l, int r, int x, int y, int z){
    if(x <= l && r <= y) return update(rt, l, r, z);
    pushdown(rt, l, r);
    int mid = (l + r) >> 1;
    if(x <= mid) modify(LSON, x, y, z);
    if(y > mid) modify(RSON, x, y, z);
    pushup(rt);
}
Dat query(int rt, int l, int r, int x, int y){
    if(x <= l && r <= y) return t[rt];
    pushdown(rt, l, r);
    int mid = (l + r) >> 1;
    if(x <= mid && y > mid) return query(LSON, x, y) + query(RSON, x, y);
    if(x <= mid) return query(LSON, x, y);
    else return query(RSON, x, y);
}
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    read(n);read(m);
    scanf("%s", a + 1);
    build(1, 1, n);
    while(m --){
        int l, r;read(l);read(r);
        Dat ret = query(1, 1, n, l, r);
        int num = -1;
        bool ck = 0;
        for (register int i = 0;i < 26;i ++){
            if(ret.cnt[i] & 1){
                if(~num) {ck = 1;break;}
                num = i;
            }
        }
        if(ck) continue;
        if(~num){
            for (register int i = 0;i < 26;i ++){
                int x = ret.cnt[i];
                if(!x) continue;
                x >>= 1;
                modify(1, 1, n, l, l + x - 1, i);
                modify(1, 1, n, r - x + 1, r, i);
                l += x;r -= x;
            }
            modify(1, 1, n, l, r, num);
        }
        else{
            for (register int i = 0;i < 26;i ++){
                int x = ret.cnt[i];
                if(!x) continue;
                x >>= 1;
                modify(1, 1, n, l, l + x - 1, i);
                modify(1, 1, n, r - x + 1, r, i);
                l += x;r -= x;
            }
        }
    }
    for (register int i = 1;i <= n;i ++){
        Dat ret = query(1, 1, n, i, i);
        for (register int j = 0;j < 26;j ++){
            if(ret.cnt[j]){
                putchar(j + 97);
                break;
            }
        }
    }
    putchar(10);
}
/*
dhlvqqddhqqllqhdllddhdvllqdlvhlqvvvvlvlddlqqvqlvvdhhvqhvhdlqvhqvvlvlqhvdqdhvldqvqqhlhhdhqlhvqvvdqvlvqqhqdvldvvvddldqvllqhdvhldlhvlhllhqddddlhhlvhqhhvqvvdhhvdhhqdlhhdlqqvhlddhhhvvdvhddqhhvdqddqqqdllqqdllvhdqdhlqllqvvdlhqvlvhdvhdlvdldqdldqdqvhqvlvqvldvvdddvldldllldqdhhqqqdqqqlhlhqdlqqqldlhqqlldhlhvhhhvqlvlvdlqhvddqvhqhqhqdldddhhhqllhhlvdvvdhhdlqlhqqqdvhhhddlllqqqvhhhhhvqqqllldvqqlqlhlhhvhlhllqhdhhldhdqldqlvvdvlqhqqhqlvvdvqvqvlqvqvlqddlqhvhhlhqhvqqlddhldqldvqvldqlqhhhqqllvqdvddqdqqvhvvhhdddlqlqqqql
dhlvqqddhqqllqhdllddhdvllqdlvhlqvvvvlvlddlqqvqlvvdhhvqhvhdlqvhqvvlvlqhvdqdhvldqvqqhlhhdhqlhvqvvdqvlvqqhqdvldvvvddldqvllqhdvhldlhvlhllhqddddlhhlvhqhhvqvvdhhvdhhqdlhhdlqqvhlddhhhvvdvhddqhhvdqddqqqdllqqdllvhdqdhlqllqvvdlhqvlvhdvhdlvdldqdldqdqvhqvlvqvldvvdddvldldllldqdhhqqqdqqqlhlhqdlqqqldlhqqlldhlhvhhhvqlvlvdlqhvddqvhqhqhqdldddhhhqllhhlvdvvdhhdlqlhqqqdvhhhddhhlllqqqvhvqqqlllhhdvqqlqlhlhhvhlhllqhdhhldhdqldqlvvdvlqhqqhqlvvdvqvqvlqvqvlqddlqhvhhlhqhvqqlddhldqldvqvldqlqhhhqqllvqdvddqdqqvhvvhhdddlqlqqqql
*/