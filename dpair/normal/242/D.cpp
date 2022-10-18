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
int a[100005], cur[100005], opt[100005];
int head[100005], nxt[200005], e[200005];
int cnt;
inline void add(int u, int v){
    nxt[++ cnt] = head[u];
    head[u] = cnt;
    e[cnt] = v;
}

queue <int> q;
bitset <100005> inq;
inline void change(int x){
    for (register int i = head[x];i;i = nxt[i]){
        cur[e[i]] += opt[x];
        if(cur[e[i]] == a[e[i]]){
            if(!inq[e[i]]){
                inq[e[i]] = 1;
                q.push(e[i]);
            }
        }
    }
    cur[x] += opt[x];
    opt[x] = -opt[x];
}
//1 1 2 0 2
//1 1 0 1 1
//2 2 1 1 1
//3 2 1 2 1
int main(){
    read(n);read(m);
    for (register int i = 1;i <= m;i ++){
        int u, v;read(u);read(v);
        add(u, v);add(v, u);
    }
    for (register int i = 1;i <= n;i ++){
        read(a[i]);opt[i] = 1;
    }
    for (register int i = 1;i <= n;i ++){
        if(cur[i] == a[i]) q.push(i), inq[i] = 1;
    }
    while(!q.empty()){
        int x = q.front();q.pop();
        inq[x] = 0;
        if(cur[x] ^ a[x]) continue;
        change(x);
    }
    vector <int> ans;
    for (register int i = 1;i <= n;i ++) if(opt[i] == -1) ans.push_back(i);
    fprint(ans.size(), 10);
    reverse(ans.begin(), ans.end());
    while(!ans.empty()) fprint(ans.back(), 32), ans.pop_back();
    putchar(10);
    return 0;
}