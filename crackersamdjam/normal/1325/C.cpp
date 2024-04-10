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

int n, ans[MM];
vector<pii> adj[MM];
int sz[MM];

int dfs(int cur, int pre){
    sz[cur] = 1;
    for(auto e: adj[cur]){
        if(e.first != pre){
            sz[cur] += dfs(e.first, cur);
        }
    }
}

set<int> st;

void go(int cur, int pre, int id){
    for(auto e: adj[cur]){
        if(e.first != pre){
            go(e.first, cur, e.second);
        }
    }
    ans[id] = *st.begin();
    st.erase(st.begin());
}

int main(){
    memset(ans, -1, sizeof ans);
    scan(n);
    for(int i = 0,a,b; i < n-1; i++){
        scan(a, b);
        adj[a].emplace_back(b, i);
        adj[b].emplace_back(a, i);
    }
    for(int i = 3; i < n-1; i++)
        st.insert(i);
    
    bool done = 0;
    for(int i = 1; i <= n; i++){
        if(adj[i].size() >= 3){
            vector<pair<int, pii>> v;
            for(auto e: adj[i]){
                v.emplace_back(dfs(e.first, i), e);
            }
            sort(v.begin(), v.end());
            reverse(v.begin(), v.end());
            st.insert(0);
            go(v[0].second.first, i, v[0].second.second);
            st.insert(1);
            go(v[1].second.first, i, v[1].second.second);
            st.insert(2);
            go(v[2].second.first, i, v[2].second.second);
            done = 1;
            break;
        }
    }
    if(!done){
        st.insert(0);
        st.insert(1);
        st.insert(2);
    }
    for(int i = 0; i < n-1; i++){
        if(ans[i] == -1){
            ans[i] = *st.begin();
            st.erase(st.begin());
        }
        print(ans[i]);
    }
    
    return 0;
}