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
const int MM = 1e5+5;

int n, dp[MM][2];
vector<int> adj[MM];
int ansl, ansr, odd, even;

void dfs(int cur, int pre, int dis){
    if(adj[cur].size() == 1){
        if(dis&1)
            odd = 1;
        else
            even = 1;
    }
    for(int u: adj[cur]){
        if(u != pre)
            dfs(u, cur, dis+1);
    }
}

int main(){
    scan(n);
    if(n == 2){
        //wont happen
        print(1, 1);
        return 0;
    }
    
    for(int i = 0,a,b; i < n-1; i++){
        scan(a, b);
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    ansl = 1;
    ansr = n-1;
    for(int i = 1; i <= n; i++){
        int cnt = 0;
        for(int u: adj[i]){
            if(adj[u].size() == 1){
                cnt++;
            }
        }
        if(cnt)
            cnt--;
        ansr -= cnt;
    }
    dfs(1, 0, 0);
    
    if(odd and even)
        ansl = 3;
    
    print(ansl, ansr);
    
    return 0;
}
/*
6
1 6
6 2
2 3
3 4
2 5

8
1 6
6 2
2 3
3 4
2 5
4 7
5 8

7
1 2
1 3
3 4
1 5
5 6
6 7
 
11
1 2
1 3
3 4
1 5
5 6
6 7
1 8
8 9
9 10
10 11

 */