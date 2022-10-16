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
const int MM = 2e5+2;

int n, m, par[MM], mx[MM], mn[MM], ans;
bool done[MM];
vector<pii> v;

int find(int x){
    while(x != par[x])
        x = par[x], par[x] = par[par[x]];
    return x;
}

int main(){
    
    scan(n, m);
    for(int i = 1; i <= n; i++)
        par[i] = mx[i] = mn[i] = i;
    
    for(int i = 0,a,b; i < m; i++){
        scan(a, b);
        a = find(a), b = find(b);
        if(a != b){
            par[b] = a;
            mx[a] = max(mx[a], mx[b]);
            mn[a] = min(mn[a], mn[b]);
        }
    }
    
    for(int i = 1; i <= n; i++){
        int id = find(i);
        if(!done[id]){
            done[id] = 1;
            v.push_back({mn[id], mx[id]});
        }
    }
    
    sort(v.begin(), v.end());
    
    int ed = v.front().second;
    for(int i = 1; i < v.size(); i++){
        //print(v[i].first, v[i].second, ed);
        if(v[i].first <= ed){
            ed = max(ed, v[i].second);
            ans++;
        }
        else{
            ed = v[i].second;
        }
    }
    
    print(ans);
    
    return 0;
}