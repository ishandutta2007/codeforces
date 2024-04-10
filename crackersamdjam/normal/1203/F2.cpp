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
using ll = long long;
const int MM = 102*300 + 30002;

int n, dp[2][MM], ans, sum;
vector<pair<int, int>> pos, neg, v;

int main(){
    
    scan(n, sum);
    
    for(int j = 0,a,b; j < n; j++){
        scan(a, b);
        if(b >= 0) pos.emplace_back(a, b);
        else neg.emplace_back(max(a, -b), b);
    }
    v.emplace_back();
    sort(all(pos));
    v.insert(v.end(), all(pos));
    sort(all(neg), [](auto x, auto y){
        return x.first+x.second > y.first+y.second;
    });
    v.insert(v.end(), all(neg));
    
    memset(dp, -1, sizeof dp);
    dp[0][sum] = 0;
    int cur = 0, pre = 1;
    
    for(int i = 1; i <= n; i++){
        swap(cur, pre);
        
        int a = v[i].first, b = v[i].second;
        for(int j = 0; j < MM; j++)
            dp[cur][j] = dp[pre][j];
        for(int j = max(0, b); j < MM; j++){
            if(j >= 0 and j < MM and j-b >= 0 and j-b < MM and ~dp[pre][j-b] and j-b >= a){
                dp[cur][j] = max(dp[cur][j], dp[pre][j-b]+1);
                ans = max(ans, dp[cur][j]);
            }
        }
    }
    
    print(ans);
    
    return 0;
}