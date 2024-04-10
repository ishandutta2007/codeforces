#include <cstdio>
 
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
#define MAXN 200005
char s[2][MAXN];
#define a(x) s[(x - 1) / n][(x - 1) % n + 1]
#define INF 0x3f3f3f3f
int dp[MAXN][21][2][2];
int n, q, fa[MAXN << 1];
int find(int x){
    if(fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}
template <typename T>
inline T mn(T x, T y) {return x < y ? x : y;}
template <typename T>
inline T mx(T x, T y) {return x > y ? x : y;}
template <typename T>
inline void chmin(T &x, T y) {(x > y) && (x = y);}
template <typename T>
inline void chmax(T &x, T y) {(x < y) && (x = y);}
int main(){
    read(n);read(q);
    scanf("%s", s[0] + 1);scanf("%s", s[1] + 1);
    for (register int i = 1;i <= (n << 1);i ++){
        if(a(i) == '.'){
            fa[i] = i;
            if((i - 1) % n && a(i - 1) == '.') fa[find(i)] = find(i - 1);
            if(i > n && a(i - n) == '.') fa[find(i)] = find(i - n);
        }
    }
    for (register int i = 1;i < n;i ++){
        for (register int j = 0;j < 2;j ++){
            dp[i][0][j][j] = s[j][i + 1] == 'X'? INF : 1;
            dp[i][0][j][j ^ 1] = s[j ^ 1][i + 1] == 'X'? INF : 2;
        }
    }
    for (register int k = 1;k <= 20;k ++){
        for (register int i = 1;i + (1 << k) <= n;i ++){
            for (register int j = 0;j < 2;j ++){
                dp[i][k][j][j] = s[j][i + (1 << k)] == 'X'? INF : mn(dp[i][k - 1][j][j] + dp[i + (1 << (k - 1))][k - 1][j][j], dp[i][k - 1][j][j ^ 1] + dp[i + (1 << (k - 1))][k - 1][j ^ 1][j]);
                dp[i][k][j][j ^ 1] = s[j ^ 1][i + (1 << k)] == 'X'? INF : mn(dp[i][k - 1][j][j] + dp[i + (1 << (k - 1))][k - 1][j][j ^ 1], dp[i][k - 1][j][j ^ 1] + dp[i + (1 << (k - 1))][k - 1][j ^ 1][j ^ 1]);
            }
        }
    }
    while(q --){
        int u, v;read(u);read(v);
        if(a(u) == 'X' || a(v) == 'X' || (find(u) ^ find(v))) {
            printf("-1\n");
            continue;
        }
        if((v - 1) % n < (u - 1) % n) u ^= v ^= u ^= v;
        int opp = u <= n? u + n : u - n;
        int num[2];
        num[(u - 1) / n] = 0;
        num[((u - 1) / n) ^ 1] = a(opp) == 'X'? INF : 1;
        int pos = (u - 1) % n + 1, dis = ((v - 1) % n) - ((u - 1) % n);
        for (register int i = 20;i >= 0;i --){
            if((dis >> i) & 1){
                int tmp[2] = {num[0], num[1]};
                for (register int j = 0;j < 2;j ++)num[j] = mn(tmp[0] + dp[pos][i][0][j], tmp[1] + dp[pos][i][1][j]);
                pos = pos + (1 << i);
            }
        }
        fprint(num[(v - 1) / n], 10);
    }
}