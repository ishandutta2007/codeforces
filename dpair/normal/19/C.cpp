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
int n;
#define MAXN 100005
int a[MAXN], b[MAXN], c[MAXN];
vector <int> pos[MAXN];
const LL MOD1 = 998244353;
const LL MOD2 = 1000000007;
const LL MOD3 = 19260817;
const LL base1 = 131;
const LL base2 = 2;
const LL base3 = 311;
LL b1[MAXN], b2[MAXN], b3[MAXN];
LL h1[MAXN], h2[MAXN], h3[MAXN];

struct DPair{
    int len;
    int p;
    DPair (int tmp1, int tmp2) : len(tmp1), p(tmp2) {}
    inline bool operator < (const DPair &tmp) const{
        return len > tmp.len || (len == tmp.len && p > tmp.p);
    }
};
priority_queue <DPair> q;

inline void init(){
    b1[0] = b2[0] = b3[0] = 1;
    for (register int i = 1;i <= n;i ++) {
        b1[i] = (b1[i - 1] * base1) % MOD1;
        b2[i] = (b2[i - 1] * base2) % MOD2;
        b3[i] = (b3[i - 1] * base3) % MOD3;
    }
}

inline bool check(int l, int r, int ll, int rr){
    int len = (r - l + 1);
    LL num1 = (h1[r] - (h1[l - 1] * b1[len] % MOD1) + MOD1) % MOD1;
    LL num2 = (h2[r] - (h2[l - 1] * b2[len] % MOD2) + MOD2) % MOD2;
    LL num3 = (h3[r] - (h3[l - 1] * b3[len] % MOD3) + MOD3) % MOD3;
    LL num4 = (h1[rr] - (h1[ll - 1] * b1[len] % MOD1) + MOD1) % MOD1;
    LL num5 = (h2[rr] - (h2[ll - 1] * b2[len] % MOD2) + MOD2) % MOD2;
    LL num6 = (h3[rr] - (h3[ll - 1] * b3[len] % MOD3) + MOD3) % MOD3;
    return num1 == num4 && num2 == num5 && num3 == num6;
}

int main(){
    read(n);
    init();
    for (register int i = 1;i <= n;i ++) read(a[i]), b[i] = a[i], c[i] = a[i];
    sort(b + 1, b + n + 1);
    int tot = unique(b + 1, b + n + 1) - b - 1;
    // for (register int i = 1;i <= tot;i ++) fprint(b[i], 10);
    // putchar(10);
    for (register int i = 1;i <= n;i ++){
        // printf("a[i] = %d\n", a[i]);
        a[i] = lower_bound(b + 1, b + tot + 1, a[i]) - b;
        // printf("shifted a[i] = %d\n", a[i]);
        pos[a[i]].push_back(i);
    }
    for (register int i = 1;i <= n;i ++){
        h1[i] = (h1[i - 1] * base1 + a[i]) % MOD1;
        h2[i] = (h2[i - 1] * base2 + a[i]) % MOD2;
        h3[i] = (h3[i - 1] * base3 + a[i]) % MOD3;
    }
    for (register int i = 1;i <= tot;i ++){
        // printf("i = %d\n", i);
        for (register int j = 0;j < pos[i].size();j ++){
            for (register int k = j + 1;k < pos[i].size();k ++){
                int len = pos[i][k] - pos[i][j];
                // printf("j = %d, k = %d, pos[i][j] = %d, pos[i][k] = %d\n", j, k, pos[i][j], pos[i][k]);
                if(pos[i][k] + len - 1 > n) break;
                if(check(pos[i][j], pos[i][j] + len - 1, pos[i][k], pos[i][k] + len - 1)){
                    // printf("push len = %d, p = %d\n", len, pos[i][j]);
                    q.push(DPair(len, pos[i][j]));
                }
            }
        }
    }
    int L = 1;
    while(!q.empty()){
        DPair x = q.top();
        q.pop();
        if(x.p < L) continue;
        L = x.p + x.len;
    }
    fprint(n - L + 1, 10);
    for (register int i = L;i <= n;i ++) fprint(c[i], 32);
    putchar(10);
}