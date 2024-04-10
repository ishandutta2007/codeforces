#include <bits/stdc++.h>
using namespace std;
#define INF 1000000009
#define SIZ 1048576

template<int siz> struct Seg{
    int curmin[2*siz], cnt[2*siz], lazy[2*siz];
    Seg(){
        memset(curmin, 0, sizeof curmin);
        memset(lazy, 0, sizeof lazy);
        fill(cnt, cnt+2*siz, 1);
    }
    void pull(int v){
        if(curmin[2*v] != curmin[2*v+1]){
            int ind = 2*v; if(curmin[2*v+1] < curmin[ind]) ind = 2*v+1;
            curmin[v] = curmin[ind]; cnt[v] = cnt[ind];
        }
        else curmin[v] = curmin[2*v], cnt[v] = cnt[2*v]+cnt[2*v+1];
    }
    void build(){for(int i = siz-1; i>=0; i--) pull(i);}
    void push(int ind, int l, int r){
        curmin[ind] += lazy[ind];
        if(l != r) lazy[2*ind] += lazy[ind], lazy[2*ind+1] += lazy[ind];
        lazy[ind] = 0;
    }
    void upd(int cl, int cr, int inc, int ind = 1, int l = 0, int r = siz-1){
        push(ind, l, r);
        if(cl > r || cr < l) return;
        if(cl <= l && r <= cr){
            lazy[ind] += inc;
            push(ind, l, r); return;
        }
        int mid = (l+r)/2;
        upd(cl, cr, inc, ind*2, l, mid);
        upd(cl, cr, inc, ind*2+1, mid+1, r);
        pull(ind);
    }
    pair<int, int> query(int cl = 0, int cr = siz-1, int ind = 1, int l = 0, int r = siz-1){
        push(ind, l, r);
        if(cl > r || cr < l) return {INF, 0};
        if(l <= cl && cr <= r) return {curmin[ind], cnt[ind]};
        int mid = (l+r)/2;
        pair<int, int> r1 = query(cl, cr, ind*2, l, mid);
        pair<int, int> r2 = query(cl, cr, ind*2+1, mid+1, r);
        if(r1.first == r2.first) return {r1.first, r1.second+r2.second};
        return min(r1, r2);
    }
};

int n, m;
vector<vector<pair<int, int>>> grid;
vector<vector<int>> adj;
int counter = 1;
vector<int> tin, tout;
Seg<SIZ> seg;
vector<int> bruh;
long long ans = 0;

int hsh(pair<int, int> a){
    return a.first*(m+2)+a.second;
}

pair<int, int> add(pair<int, int> a, pair<int, int> b){
    return {a.first+b.first, a.second+b.second};
}

bool bad(pair<int, int> a){
    return a.first <= 0 || a.first > n || a.second <= 0 || a.second > m;
}

void getRanges(int v){
    counter++;
    tin[v] = counter;
    for(auto u : adj[v]){
        getRanges(u);
    }
    tout[v] = counter;
}

void solve(int v){
    if(bruh[v] >= 0) seg.upd(tin[bruh[v]], tout[bruh[v]], 1);
    if(bruh[v] >= 0) ans += SIZ-seg.query().second;
    for(auto u : adj[v]) solve(u);
    if(bruh[v] >= 0) seg.upd(tin[bruh[v]], tout[bruh[v]], -1);
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    grid.assign(n+2, vector<pair<int, int>>(m+2));
    adj.resize((n+2)*(m+2)+1);
    tin.resize((n+2)*(m+2)+1), tout.resize((n+2)*(m+2)+1);
    bruh.assign((n+2)*(m+2)+1, -1);
    for(int i = 0; i<n; i++){
        string s; cin >> s;
        for(int j = 0; j<m; j++){
            if(s[j] == 'U') grid[i+1][j+1] = {2, 0}, bruh[hsh({i+1, j+1})] = hsh({i+2, j+1});
            if(s[j] == 'D') grid[i+1][j+1] = {-2, 0}, bruh[hsh({i+1, j+1})] = hsh({i, j+1});
            if(s[j] == 'L') grid[i+1][j+1] = {0, 2}, bruh[hsh({i+1, j+1})] = hsh({i+1, j+2});
            if(s[j] == 'R') grid[i+1][j+1] = {0, -2}, bruh[hsh({i+1, j+1})] = hsh({i+1, j});
        }
    }
    for(int i = 0; i<(n+2); i++){
        for(int j = 0; j<(m+2); j++){
            if(bad({i, j})) adj[(n+2)*(m+2)].push_back(hsh({i, j}));
            else adj[hsh(add({i, j}, grid[i][j]))].push_back(hsh({i, j}));
        }
    }
    getRanges((n+2)*(m+2));
    seg.build();
    solve((n+2)*(m+2));
    // brute();
    cout << ans/2 << endl;
}