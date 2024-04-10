#include <bits/stdc++.h>
using namespace std;
#define int long long
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

int n;
int prime[100005], tot;
bitset <100005> b;
inline void init(int N){
    for (register int i = 2;i <= N;i ++){
        if(!b[i]) prime[++ tot] = i;
        for (register int j = 1;j <= tot && 1ll * i * prime[j] <= N;j ++){
            b[i * prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }
    }
}
int ans = 1;

inline int ksm(int x, int y){
    int ret = 1;
    while(y){
        if(y & 1) ret = ret * x;
        x = x * x;
        y >>= 1;
    }
    return ret;
}

signed main(){
    read(n);init(n);
    int i, j;
    for (i = 1;i <= tot && 1ll * prime[i] * prime[i] <= n;i ++){
        printf("B %lld\n", prime[i]);fflush(stdout);
        int num;read(num);
        int l = 1, r = floor(log(n) / log(prime[i])), ret = 0;
        while(l <= r){
            int mid = (l + r) >> 1;
            printf("A %lld\n", ksm(prime[i], mid));fflush(stdout);
            // printf("prime[i] = %d, l = %d, r = %d\n", prime[i], l, r);
            read(num);
            if(num) ret = mid, l = mid + 1;
            else r = mid - 1;
        }
        ans *= ksm(prime[i], ret);
    }
    int block = 98;
    int pre, sig = 0;
    printf("A 1\n");fflush(stdout);
    read(pre);
    for (j = 0;i <= tot;i ++){
        printf("B %lld\n", prime[i]);fflush(stdout);
        int num;read(num);
        sig += num;
        j ++;
        j %= block;
        if(!j){
            printf("A 1\n");fflush(stdout);
            read(num);
            if(pre - num < sig){
                j = block;
                for (register int k = i;j;j --, k --){
                    printf("A %lld\n", prime[k]);fflush(stdout);
                    read(num);
                    if(num){
                        printf("C %lld\n", ans * prime[k]);
                        fflush(stdout);
                        return 0;
                    }
                }
            }
            else pre = num, sig = 0;
        }
    }
    int num;
    printf("A 1\n");fflush(stdout);
    read(num);
    if(pre - num < sig){
        for (register int k = tot;j;k --, j --){
            printf("A %lld\n", prime[k]);fflush(stdout);
            read(num);
            if(num){
                printf("C %lld\n", ans * prime[k]);
                fflush(stdout);
                return 0;
            }
        }
    }
    else printf("C %lld\n", ans), fflush(stdout);
}