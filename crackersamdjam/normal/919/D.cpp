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

void init(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("err.txt", "w", stderr);
    #endif
}

const int MM = 3e5+5;
int n, m, dp[MM], ans;
char c[MM], t;
vector<int> adj[MM];
bool ins[MM];

void dfs(int cur){
    if(ins[cur]){
        print(-1);
        exit(0);
    }
    if(~dp[cur])
        return;
    ins[cur] = 1;

    int mx = 0;
    for(int u: adj[cur]){
        dfs(u);
        mx = max(mx, dp[u]);
    }
    ins[cur] = 0;
    dp[cur] = mx+(c[cur]==t);
    ans = max(ans, dp[cur]);
}


int main(){
    init();
    scan(n, m);
    scanf("%s", c+1);
    for(int i = 0,a,b; i < m; i++){
        scan(a, b);
        adj[a].emplace_back(b);
    }
    for(t = 'a'; t <= 'z'; t++){
        memset(dp, -1, sizeof dp);
        for(int i = 1; i <= n; i++){
            if(dp[i] == -1){
                dfs(i);
            }
        }
    }

    print(ans);
    
    return 0;
}