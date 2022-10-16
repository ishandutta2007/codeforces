#include <bits/stdc++.h>
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
using ll = long long;
const int MM = 2e4+24;

int n, m, k;
ll dp[52][MM], psa[52][MM], pre[MM], suf[MM];
ll sum(int i, int j){
    return psa[i][j] - psa[i][max(0, j-k)];
}
ll val(int i, int l, int r){
    int lo = min(l-k, r-k), hi = max(l, r);
    return psa[i][hi] - psa[i][max(0, lo)];
}

int main(){
    scan(n, m, k);
    for(int i = 0; i < n; i++){
        for(int j = 1; j <= m; j++){
            scan(psa[i][j]);
            psa[i][j] += psa[i][j-1];
        }
    }
    for(int j = k; j <= m; j++){
        dp[0][j] = sum(0, j) + sum(1, j);
        pre[j] = max(pre[j-1], dp[0][j]);
        //printf("%d ", dp[0][j]);
    }
    //pc(10);
    for(int j = m; j; j--)
        suf[j] = max(suf[j+1], dp[0][j]);
    
    for(int i = 1; i < n; i++){
        for(int j = k; j <= m; j++){
            if(j-k > 0)
                dp[i][j] = pre[j-k] + sum(i, j) + sum(i+1, j);
            if(j+k <= m)
                dp[i][j] = max(dp[i][j], suf[j+k] + sum(i, j) + sum(i+1, j));
            
            for(int l = max(k, j-k+1); l <= min(j+k-1, m); l++){
                dp[i][j] = max(dp[i][j], dp[i-1][l] + val(i, l, j) - sum(i, l) + sum(i+1, j));
                //remove last l sum. count overlap instead
            }
            //printf("%d ", dp[i][j]);
        }
        //pc(10);
        memset(pre, 0, sizeof pre);
        memset(suf, 0, sizeof suf);
        for(int j = 1; j <= m; j++)
            pre[j] = max(pre[j-1], dp[i][j]);
        for(int j = m; j; j--)
            suf[j] = max(suf[j+1], dp[i][j]);
    }
    ll ans = *max_element(dp[n-1], dp[n-1]+m+1);
    print(ans);
    
    return 0;
}