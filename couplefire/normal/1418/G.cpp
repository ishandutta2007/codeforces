#include <bits/stdc++.h>
using namespace std;
#define MAXN 524288

pair<int, int> seg[2*MAXN];
int lazy[2*MAXN];

void build(){
    for(int i = 2*MAXN-1; i>=MAXN; i--) seg[i].second = 1;
    for(int i = MAXN-1; i>=0; i--) seg[i].second = seg[i*2].second+seg[i*2+1].second;
}

pair<int, int> comb(pair<int, int> a, pair<int, int> b){
    if(a.first != b.first) return max(a, b);
    return {a.first, a.second+b.second};
}

void push(int v, int l, int r){
    seg[v].first += lazy[v];
    if(l != r) lazy[v*2] += lazy[v], lazy[v*2+1] += lazy[v];
    lazy[v] = 0;
}

void pull(int v){seg[v] = comb(seg[v*2], seg[v*2+1]);}

void upd(int cl, int cr, int val, int v = 1, int l = 0, int r = MAXN-1){
    if(cl > cr) return;
    push(v, l, r);
    if(r < cl || l > cr) return;
    if(cl <= l && r <= cr){
        lazy[v] = val; push(v, l, r);
        return;
    }
    int m = (l+r)/2;
    upd(cl, cr, val, v*2, l, m); upd(cl, cr, val, v*2+1, m+1, r);
    pull(v);
}

pair<int, int> query(int cl, int cr, int v = 1, int l = 0, int r = MAXN-1){
    push(v, l, r);
    if(r < cl || l > cr) return {0, 0};
    if(cl <= l && r <= cr) return seg[v];
    int m = (l+r)/2;
    return comb(query(cl, cr, v*2, l, m), query(cl, cr, v*2+1, m+1, r));
}

int n;
int arr[MAXN];
vector<int> pos[MAXN];
long long ans = 0;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    build();
    for(int i = 0; i<n; i++) cin >> arr[i], --arr[i];
    for(int i = 0; i<n; i++) pos[i].push_back(-1);
    for(int i = 0; i<n; i++){
        upd(i, i, n);
        if(pos[arr[i]].size() >= 4) upd(pos[arr[i]][pos[arr[i]].size()-4]+1, pos[arr[i]][pos[arr[i]].size()-3], -1);
        upd(pos[arr[i]].back()+1, i, -1);
        pos[arr[i]].push_back(i);
        if(pos[arr[i]].size() >= 4) upd(pos[arr[i]][pos[arr[i]].size()-4]+1, pos[arr[i]][pos[arr[i]].size()-3], 1);
        pair<int, int> tmp = query(0, i);
        if(tmp.first == n) ans += tmp.second;
    }
    cout << ans << endl;
}