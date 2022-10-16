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
const int MM = 5e5+5;

int n, m, t[MM], done[MM], x[MM], y[MM];
vector<int> adj[MM], ord;
set<int> cnt[MM];
queue<int> q;

int main(){
    scan(n, m);
    for(int i = 0; i < m; i++)
        scan(x[i], y[i]);
    for(int i = 1; i <= n; i++)
        scan(t[i]);
    
    for(int i = 0; i < m; i++){
        int a = x[i], b = y[i];
        if(t[a] > t[b])
            swap(a, b);
        if(t[a] == t[b]){
            print(-1);
            return 0;
        }
        adj[a].emplace_back(b);
    }
    for(int i = 1; i <= n; i++){
        if(t[i] == 1){
            q.push(i);
            done[i] = 1;
        }
    }
    while(q.size()){
        int cur = q.front(); q.pop();
        ord.emplace_back(cur);
        for(int u: adj[cur]){
            cnt[u].insert(t[cur]);
            if((int)cnt[u].size() == t[u]-1 and !done[u]){
                q.push(u);
                done[u] = 1;
            }
        }
    }
    
    if(ord.size() != n){
        print(-1);
        return 0;
    }
    for(int i: ord)
        printf("%d ", i);
    
    return 0;
}
/*
3 2
1 3
2 3
1 1 2
 */