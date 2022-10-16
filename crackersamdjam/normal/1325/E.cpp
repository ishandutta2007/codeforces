#include <bits/stdc++.h>
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
using pii = pair<int, int>;
const int MM = 1e6+2, lim = 1e3+1;

int n, ans = 1e9, dis[MM], x[MM], y[MM];
vector<pii> adj[MM];
vector<int> pre, pree, no;
queue<pii> q;
bool used[MM];

int main(){
    scan(n);
    for(int i = 0,v; i < n; i++){
        map<int, int, greater<int>> mp;
        vector<int> a;
        scan(v);
        for(int j = 2; j*j <= v; j++){
            while(v%j == 0){
                mp[j]++;
                v /= j;
            }
        }
        /*
        if(v >= lim){
            if(cnt[v]++)
                ans = 2;
            continue;
        }
         */
        mp[v]++;
        if(v != 1)
            mp[1]++;
        for(auto j: mp){
            if(j.second&1)
                a.push_back(j.first);
        }
        
        if(a.size() == 1)
            a.push_back(1);
        adj[a[0]].emplace_back(a[1], i);
        adj[a[1]].emplace_back(a[0], i);
        x[i] = a[0], y[i] = a[1];
    }
    memset(dis, 0x3f, sizeof dis);
    for(int i = 1; i < lim; i++){ //need node < sqrt to make cycle
        if(adj[i].empty())
            continue;
        dis[i] = 0;
        q.emplace(i, -1);
        while(q.size()){
            int cur = q.front().first, pid = q.front().second; q.pop();
            pre.emplace_back(cur);
            for(auto e: adj[cur]){
                int u = e.first, id = e.second;
                if(id == pid)
                    continue;
                if(dis[cur]+1 < dis[u]){
                    q.emplace(u, id);
                    dis[u] = dis[cur]+1;
                    used[id] = 1;
                    pree.emplace_back(id);
                }
                else{
                    //check this edge later
                    no.push_back(id);
                }
            }
        }
        for(int j: no){
            if(!used[j]){
//                print(i, x[j], y[j], dis[x[j]], dis[y[j]], dis[x[j]]+dis[y[j]]+1, j);
                ans = min(ans, dis[x[j]] + dis[y[j]] + 1);
            }
        }
        no.clear();
        while(pre.size()){
            dis[pre.back()] = 0x3f3f3f3f;
            pre.pop_back();
        }
        while(pree.size()){
            used[pree.back()] = 0;
            pree.pop_back();
        }
    }
    
    print(ans == 1e9? -1: ans);
    
    
    return 0;
}