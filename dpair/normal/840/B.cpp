#include <bits/stdc++.h>
using namespace std;

template <typename T>
inline void read(T &x){
    x = 0;int fu = 1;
    char c = getchar();
    while(c > 57 || c < 48){
        if(c == 45) fu = -1;
        c = getchar();
    }
    while(c <= 57 && c >= 48){
        x = (x << 3) + (x << 1) + c - 48;
        c = getchar();
    }
    x *= fu;
}
template <typename T>
inline void fprint(T x){
    if(x < 0) putchar(45), x = -x;
    if(x > 9) fprint(x / 10);
    putchar(x % 10 + 48);
}
template <typename T>
inline void fprint(T x, char ch){
    fprint(x);putchar(ch);
}

int n, m;
int a[300005];
int ck = 0, one = 0;

typedef pair <int, int> pi;

vector < pi > vec[300005];

int fa[300005];
pi f[300005];
int fd(int x){
    if(fa[x] == x) return x;
    return fa[x] = fd(fa[x]);
}
bitset <300005> b;
int d[300005];
void dfs(int x, int pre){
    f[x].first = pre;
    for (int i = 0;i < vec[x].size();i ++){
        if(vec[x][i].first == pre) continue;
        d[x] ++;f[vec[x][i].first].second = vec[x][i].second;
        dfs(vec[x][i].first, x);
    }
}
queue <int> q;
void bfs(){
    for (register int i = 1;i <= n;i ++){
        if(!d[i]) q.push(i);
    }
    while(!q.empty()){
        int x = q.front();q.pop();
        if(a[x]) b[f[x].second] = 1, a[f[x].first] ^= 1;
        d[f[x].first] --;
        if(!d[f[x].first]) q.push(f[x].first);
    }
}

int main(){
    read(n);read(m);
    for (int i = 1;i <= n;i ++){
        read(a[i]);
        if(~a[i]) one ^= a[i];
        else ck = 1;
        fa[i] = i;
    }
    if(one && !ck) return printf("-1\n"), 0;
    for (register int i = 1;i <= n;i ++){
        if(a[i] == -1){
            if(one) a[i] = 1, one = 0;
            else a[i] = 0;
        }
    }
    for (int i = 1;i <= m;i ++){
        int u, v;read(u);read(v);
        int uu = fd(u), vv = fd(v);
        if(uu ^ vv){
            fa[uu] = vv;
            vec[u].push_back(make_pair(v, i));
            vec[v].push_back(make_pair(u, i));
        }
    }
    dfs(1, 0);
    bfs();
    fprint(b.count(), 10);
    for (int i = 1;i <= m;i ++){
        if(b[i]) fprint(i, 10);
    }
    return 0;
}