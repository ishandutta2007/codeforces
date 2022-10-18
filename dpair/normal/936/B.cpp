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

int n, m, s;
vector <int> dd[100005];
bitset <100005> inq, dp[2];
int pre[2][100005];

void output(int f, int x){
    if(x == s && !f) return fprint(x, 32);
    else output(f ^ 1, pre[f][x]);
    return fprint(x, 32);
}

int dfn[100005], low[100005], dep;
stack <int> stk;
bitset <100005> ins;
int tot = 0;
void tarjan(int x){
    dfn[x] = low[x] = ++ dep;
    stk.push(x);ins[x] = 1;
    for (register int i = 0;i < dd[x].size();i ++){
        if(!dfn[dd[x][i]]){
            tarjan(dd[x][i]);
            low[x] = min(low[x], low[dd[x][i]]);
        }
        else if(ins[dd[x][i]]) low[x] = min(low[x], low[dd[x][i]]);
    }
    if(dfn[x] == low[x]){
        int cur;tot ++;
        do{
            cur = stk.top();stk.pop();ins[cur] = 0;
        } while(cur ^ x);
    }
}

int main(){
    read(n);read(m);
    for (register int i = 1;i <= n;i ++){
        read(s);
        while(s --){
            int x;read(x);
            dd[i].push_back(x);
        }
    }
    read(s);
    queue <int> q;
    q.push(s);
    dp[0][s] = 1;
    while(!q.empty()){
        int x = q.front();q.pop();
        inq[x] = 0;
        for (register int i = 0;i < dd[x].size();i ++){
            int e = dd[x][i];
            if(dp[0][x]){
                if(!dp[1][e]) {
                    dp[1][e] = 1;
                    pre[1][e] = x;
                    if(!inq[e]) inq[e] = 1, q.push(e);
                }
            }
            if(dp[1][x]){
                if(!dp[0][e]){
                    dp[0][e] = 1;
                    pre[0][e] = x;
                    if(!inq[e]) inq[e] = 1, q.push(e);
                }
            }
        }
    }
    for (register int i = 1;i <= n;i ++){
        if(dd[i].empty() && dp[1][i]){
            printf("Win\n");
            output(1, i);
            putchar(10);
            return 0;
        }
    }
    tarjan(s);
    if(tot == dep) printf("Lose\n");
    else printf("Draw\n");
}