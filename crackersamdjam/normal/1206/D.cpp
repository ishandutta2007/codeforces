#include <bits/stdc++.h>
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
typedef long long ll;
const int MM = 1e5+2, MN = 1e5+2;

int n, dis[MN];
set<int> adj[MM], adj2[MN];
vector<int> add[69];
map<int, int> mp;
int t;

int main(){
    
    scan(n);
    
    for(int i = 1; i <= n; i++){
        ll a;
        scan(a);
        for(ll j = 0; j < 64; j++){
            
            if(a&(1LL<<j)){
                
                if(add[j].size() >= 2){
                    puts("3");
                    return 0;
                }
                for(int u: add[j]){
                    //print(i, u);
                    adj[i].insert(u);
                    adj[u].insert(i);
                }
                add[j].push_back(i);
            }
        }
    }
    
    for(int i = 1; i <= n; i++){
        if(!adj[i].empty()){
            if(!mp[i])
                mp[i] = ++t;
            
            for(int u: adj[i]){
                if(!mp[u])
                    mp[u] = ++t;
                
                adj2[mp[i]].insert(mp[u]);
                //adj2[mp[u]].push_back(mp[i]);
            }
        }
    }
    int ans = INT_MAX;
    for(int i = 1; i <= t; i++){
        for(int j = 1; j <= t; j++)
            dis[j] = 0x3f3f3f3f;
        dis[i] = 0;
        queue<pair<int, int>> q;
        q.push({i, -1});
        
        while(!q.empty()){
            int cur = q.front().first; int pre = q.front().second; q.pop();
            
            for(int u: adj2[cur]){
                if(u == pre)
                    continue;
                if(dis[u] != 0x3f3f3f3f)
                    ans = min(ans, dis[u] + dis[cur] + 1);
                else{
                    dis[u] = dis[cur]+1;
                    q.push({u, cur});
                }
            }
        }
    }
    
    if(ans >= 0x3f3f3f3f)
        puts("-1");
    else
        print(ans);
    
    return 0;
}