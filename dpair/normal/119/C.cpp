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
#define int long long
int n, m, k;

int dp[55][55][105];
typedef pair <int, int> pi;

pi pre[55][55][105];

struct Subject {
    int l, r, val, id;
    inline bool operator < (const Subject &tmp) const{
        return val < tmp.val;
    }
}a[55];

inline void output(int x, int y, int z){
    if(y == 1) {printf("%lld %lld\n", a[x].id, a[x].l + z);return;}
    pi cur = pre[x][y][z];
    output(cur.first, y - 1, cur.second);
    printf("%lld %lld\n", a[x].id, a[x].l + z);
}

signed main(){
    read(n);read(m);read(k);
    for (register int i = 1;i <= m;i ++){read(a[i].l);read(a[i].r);read(a[i].val);a[i].id = i;}
    sort(a + 1, a + m + 1);
    for (register int i = 1;i <= m;i ++){
        for (register int j = 1;j <= n && j <= i;j ++){
            for (register int p = a[i].l;p <= a[i].r;p ++){
                int dis = p - a[i].l;
                if(j == 1) {dp[i][j][dis] = p;continue;}
                for (register int q = 1;q < i;q ++){
                    if(a[q].val == a[i].val) continue;
                    if(p - k >= a[q].l && p - k <= a[q].r && dp[q][j - 1][p - k - a[q].l] && dp[q][j - 1][p - k - a[q].l] + p > dp[i][j][dis]) dp[i][j][dis] = dp[q][j - 1][p - k - a[q].l] + p, pre[i][j][dis] = make_pair(q, p - k - a[q].l);
                    if(p % k == 0 && (p / k) >= a[q].l && (p / k) <= a[q].r && dp[q][j - 1][(p / k) - a[q].l] && dp[q][j - 1][(p / k) - a[q].l] + p > dp[i][j][dis]) dp[i][j][dis] = dp[q][j - 1][(p / k) - a[q].l] + p, pre[i][j][dis] = make_pair(q, (p / k) - a[q].l);
                }
            }
        }
    }
    pi pos;
    int ans = -0x3f3f3f3f;
    for (register int i = n;i <= m;i ++){
        for (register int p = a[i].r;p >= a[i].l;p --){
            int dis = p - a[i].l;
            if(dp[i][n][dis] && dp[i][n][dis] > ans) pos = make_pair(i, dis), ans = dp[i][n][dis];
        }
    }
    if(ans == -0x3f3f3f3f) printf("NO\n");
    else{
        printf("YES\n");
        output(pos.first, n, pos.second);
    }
    
    return 0;
}