#include <bits/stdc++.h>
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int MM = 5e5+5;

#define peek(x) (x)
//#define peek(x) cout << #x << ' ' << x << endl

int q, n, k, dp[MM]; //only store last edge
ll ans;
vector<pii> adj[MM];

void dfs(int cur, int pre){
    //printf("dfs %d %d\n", cur, pre);
    vector<int> dif;
    
    for(auto u: adj[cur]){
        if(u.first == pre)
            continue;
        
        dfs(u.first, cur);
        dif.push_back(u.second - dp[u.first]);
        //how much we get by getting this edge
    }
    
    //peek(dif.size());
    sort(dif.begin(), dif.end(), greater<int>());
    //for(int i: dif)
      //  printf("%d ", i);
    //pc(10);
    for(int i = 0; i < min(k-1, (int)dif.size()); i++){
        ans += max(0, dif[i]);
        //printf("add1 %d\n", dif[i]);
    }
    
    if(dif.size() >= k){
        dp[cur] = max(0, dif[k-1]);
        ans += max(0, dp[cur]);
        //printf("add %d\n", dif[k-1]);
    }
    else
        dp[cur] = 0;
    
    //peek(cur);
    //peek(dp[cur]);
}

int main(){
    
    scan(q);
    
    while(q--){
        
        //puts("********");
        
        scan(n, k);
        ans = 0;
        for(int i = 1; i <= n; i++){
            adj[i].clear();
            dp[i] = 0;
        }
        for(int i = 0,a,b,c; i < n-1; i++){
            scan(a, b, c);
            adj[a].push_back({b, c});
            adj[b].push_back({a, c});
        }
        
        dfs(1, 0);
        
        print(ans);
    }
    
    return 0;
}