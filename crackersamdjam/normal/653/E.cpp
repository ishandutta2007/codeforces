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
const int MM = 3e5+5;

int n, m, k, par[MM];
set<int> no[MM], unvis;
queue<int> q;
map<int, vector<int>> mp;

int find(int x){
    while(x != par[x])
        x = par[x], par[x] = par[par[x]];
    return x;
}

int main(){
    scan(n, m, k);
    for(int i = 0,a,b; i < m; i++){
        scan(a, b);
        no[a].insert(b);
        no[b].insert(a);
    }
    for(int i = 2; i <= n; i++){
        unvis.insert(i);
        par[i] = i;
    }
    while(unvis.size()){
        int rt = *unvis.begin();
        unvis.erase(rt);
        q.push(rt);
        while(q.size()){
            int cur = q.front(); q.pop();
            for(auto it = unvis.begin(); it != unvis.end();){
                int u = *it;
                if(!no[cur].count(u)){
                    q.push(u);
                    par[find(u)] = find(cur);
                    it = unvis.erase(it);
                }
                else
                    it++;
            }
        }
    }
    for(int i = 2; i <= n; i++){
        mp[find(i)].emplace_back(i);
    }
    int cnt = 0;
    for(auto i: mp){
        for(int j: i.second){
            if(!no[1].count(j)){
                cnt++;
                break;
            }
        }
    }
    
    if(cnt < mp.size() or cnt > k or n-1-no[1].size() < k){
        //can not connect, too many needed, too few available
        puts("impossible");
    }
    else
        puts("possible");
    
    return 0;
}