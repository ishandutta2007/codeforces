#include <bits/stdc++.h>
using namespace std;
#define MAXN 524288

int n;
int height[MAXN];
int beauty[MAXN];
long long dp[MAXN];
int prv[MAXN];

struct node{
    long long maxdp = 0, maxtot = 0;
    node(){}
    node(long long a, long long b): maxdp(a), maxtot(b){}
};

node tree[2*MAXN];
long long lazy[2*MAXN];

node comb(node a, node b){
    a.maxdp = max(a.maxdp, b.maxdp);
    a.maxtot = max(a.maxtot, b.maxtot);
    return a;
}

void push(int v, int tl, int tr){
    if(lazy[v] == 1000000009) return;
    tree[v].maxtot = tree[v].maxdp + lazy[v];
    if(tl != tr) lazy[v*2] = lazy[v], lazy[v*2+1] = lazy[v];
    lazy[v] = 1000000009;
}

void pull(int v){
    tree[v] = comb(tree[v*2], tree[v*2+1]);
}

void setnew(int ind, node val, int v = 1, int tl = 0, int tr = MAXN-1){
    push(v, tl, tr);
    if(tl > ind || tr < ind) return;
    if(tl == tr){
        tree[v] = val;
        return;
    }
    int tm = (tl+tr)/2;
    setnew(ind, val, v*2, tl, tm);
    setnew(ind, val, v*2+1, tm+1, tr);
    pull(v);
}

void upd(int l, int r, long long val, int v = 1, int tl = 0, int tr = MAXN-1){
    push(v, tl, tr);
    if(tl > r || tr < l) return;
    if(l <= tl && tr <= r){
        lazy[v] = val;
        push(v, tl, tr);
        return;
    }
    int tm = (tl+tr)/2;
    upd(l, r, val, v*2, tl, tm);
    upd(l, r, val, v*2+1, tm+1, tr);
    pull(v);
}

long long query(int l, int r, int v = 1, int tl = 0, int tr = MAXN-1){
    push(v, tl, tr);
    if(tl > r || tr < l) return -1e18;
    if(l <= tl && tr <= r) return tree[v].maxtot;
    int tm = (tl+tr)/2;
    return max(query(l, r, v*2, tl, tm), query(l, r, v*2+1, tm+1, tr));
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    fill(lazy, lazy+2*MAXN, 1000000009);
    for(int i = 1; i<=n; i++) cin >> height[i];
    for(int i = 1; i<=n; i++) cin >> beauty[i];
    stack<pair<int, int>> st; // ind, val
    st.push({0, -1000000009});
    for(int i = 1; i<=n; i++){
        while(st.top().second >= height[i]) st.pop();
        prv[i] = st.top().first;
        st.push({i, height[i]});
    }
    for(int i = 1; i<=n; i++){
        setnew(i, {dp[i-1], dp[i-1]+beauty[i]});
        upd(prv[i]+1, i, beauty[i]);
        dp[i] = query(1, i);
    }
    cout << dp[n] << endl;
}