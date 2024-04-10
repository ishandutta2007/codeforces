#pragma GCC optimize("O3")
#pragma GCC target("sse4")

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using ld = long double;
constexpr int MAXN = 1e5+1, MM = 600;

int n, k;
ld dp[2][MM];

int main(){
    scanf("%d %d", &n, &k);
    int cur = 1, pre = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j < MM-1; j++){
            dp[cur][j] = 1.0/k*(1.0/(j+1)*(dp[pre][j+1] + j) + j/(j+1.0)*((j+1)/2.0 + dp[pre][j])) + (k-1.0)/k*dp[pre][j];
            //gets higher one, gets <= j, gets another item type
        }
        cur ^= 1;
        pre ^= 1;
    }
    printf("%.10Lf\n", k*dp[pre][1]);
    
    return 0;
}