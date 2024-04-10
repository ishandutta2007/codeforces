#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 1e6+5;

int t, n, k, dp[MM], psa[MM];
char s[MM];

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &k);
        scanf("%s", s+1);
        for(int i = 1; i <= n; i++){
            s[i] -= '0';
            psa[i] = psa[i-1]+s[i];
            dp[i] = psa[i-1] + !s[i];
            if(i > k)
                dp[i] = min(dp[i], dp[i-k] + psa[i-1] - psa[i-k] + !s[i]);
        }
        int ans = 1e9;
        for(int i = 0; i <= n; i++){
            ans = min(ans, dp[i] + psa[n]-psa[i]);
        }
        print(ans);
    }
    
    return 0;
}
/*

7
2 2
00
5 5
11110
5 1
10101
5 3
10001
13 2
1010000000101
33 2
101010001000000000101010101010101
33 2
101010101010101000000000100010101

 */