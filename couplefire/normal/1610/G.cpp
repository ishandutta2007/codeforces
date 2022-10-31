#include <bits/stdc++.h>
using namespace std;

const int N = 300005;
const int LG = 20;
const int MOD = 1000018433;

inline int add(int a, int b){return (a+b>=MOD)?a+b-MOD:a+b;}
inline void inc(int& a, int b){a = add(a, b);}
inline int sub(int a, int b){return (a-b<0)?a-b+MOD:a-b;}
inline void dec(int &a, int b){a = sub(a, b);}
inline int mul(int a, int b){return 1ll*a*b%MOD;}
inline void grow(int &a, int b){a = mul(a, b);}

string s;
int n, pw[LG], psum[N], ls[N+N], nxt[N], up_fa[N][LG], up_sum[N][LG], node[N];

bool check(int u, int v){
    for(int i = LG-1; i>=0; --i)
        if(up_sum[u][i]==up_sum[v][i])
            u = up_fa[u][i], v = up_fa[v][i];
    if(u==n+1) return 1;
    return up_sum[u][0]>=up_sum[v][0];
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    cin >> s; n = s.length(); s = "$"+s;
    pw[0] = 2;
    for(int i = 1; i<LG; ++i)
        pw[i] = mul(pw[i-1], pw[i-1]);
    for(int i = 1; i<=n; ++i)
        psum[i] = psum[i-1]+(s[i]=='('?1:-1);
    for(int i = n+1; i>=1; --i){
        nxt[i] = i;
        if(s[i]=='(' && ls[psum[i-1]+N])
            nxt[i] = ls[psum[i-1]+N];
        ls[psum[i-1]+N] = i;
    }
    for(int i = 0; i<LG; ++i)
        up_fa[n+1][i] = n+1;
    node[n+1] = n+1;
    for(int i = n; i>=1; --i){
        up_fa[i][0] = node[i+1];
        up_sum[i][0] = (s[i]=='(');
        for(int j = 1; j<LG; ++j)
            up_fa[i][j] = up_fa[up_fa[i][j-1]][j-1],
            up_sum[i][j] = add(up_sum[i][j-1], mul(pw[j-1], up_sum[up_fa[i][j-1]][j-1]));
        node[i] = (nxt[i]>i && check(node[nxt[i]], i)?node[nxt[i]]:i);
    }
    int cur = node[1];
    while(cur!=n+1)
        cout << (up_sum[cur][0]?'(':')'), cur = up_fa[cur][0];
    cout << '\n';
}