#include <bits/stdc++.h>
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 2002;

int n, a[MM], v[MM], sz[MM], NO;
vector<int> adj[MM];

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using T = int;
typedef __gnu_pbds::tree<T, __gnu_pbds::null_type, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> bbst;
bbst t;

void dfs(int cur){
    sz[cur] = 1;
    for(int u: adj[cur]){
        dfs(u);
        sz[cur] += sz[u];
    }
    if(v[cur] >= sz[cur])
        NO = 1;
}

void dfs2(int cur){
    //printerr("go", cur);
    
    for(int u: adj[cur]){
        //printerr("u", v[cur], sz[u]);
        if(v[cur] >= sz[u]){
            v[cur] -= sz[u];
        }
        else if(!a[cur]){
            auto ptr = t.find_by_order(v[cur]);
            //printerr("set", cur, v[cur], *ptr);
            a[cur] = *ptr;
            t.erase(ptr);
            v[cur]--;
        }
        dfs2(u);
    }
    if(!a[cur] and v[cur] >= 0){
        //printf("END %d\n", v[cur]);
        a[cur] = *t.begin();
        t.erase(t.begin());
    }
}

int main(){
    
    for(int i = 1; i < MM*5; i++)
        t.insert(i);
    
    scan(n);
    
    int rt = 0;
    for(int i = 1,p; i <= n; i++){
        scan(p, v[i]);
        adj[p].push_back(i);
        if(!p) rt = i;
    }
    
    dfs(rt);
    if(NO){
        return puts("NO"), 0;
    }
    
    dfs2(0);
    
    puts("YES");
    for(int i = 1; i <= n; i++)
        printf("%d ", a[i]);
    
    return 0;
}