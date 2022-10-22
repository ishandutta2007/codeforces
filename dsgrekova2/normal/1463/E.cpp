#include "list"
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>
#define int long long
using namespace std;
void dfs(int v, vector<int> &color, vector<vector<int>> &qg, int c){
    if(color[v] != -1)
        return;
    color[v] = c;
    for(auto x : qg[v])
        dfs(x, color, qg, c);
}
struct segtree{
    vector<pair<int, int>> tree;
    int size;
    pair<int, int> cmp(pair<int, int> a, pair<int, int> b){
        if(a.second < b.second)
            return a;
        return b;
    }
    void make(int n, vector<int> &k){
        size = 1;
        while(size <= n)
            size *= 2;
        tree.assign(size * 2, {0, 1e6});
        for (int i = 0; i < n; ++i) {
            tree[i + size] = {i, k[i]};
        }
        for (int i = size - 1; i > 0; --i) {
            tree[i] = cmp(tree[i * 2], tree[i * 2 + 1]);
        }
    }
    void upd(int p, int x){
        p += size;
        tree[p].second += x;
        while(p != 1){
            p /= 2;
            tree[p] = cmp(tree[p * 2], tree[p * 2 + 1]);
        }
    }
    void chn(int p, int x){
        p += size;
        tree[p].second = x;
        while(p != 1){
            p /= 2;
            tree[p] = cmp(tree[p * 2], tree[p * 2 + 1]);
        }
    }
    pair<int, int> getmin(int l, int r){
        l += size;
        r += size;
        pair<int, int> res = tree[l];
        while(l < r){
            if(l % 2){
                res = cmp(res, tree[l]);
                l++;
            }
            if(r % 2 == 0){
                res = cmp(res, tree[r]);
                r--;
            }
            l /= 2;
            r /= 2;
        }
        if(l == r){
            res = cmp(res, tree[r]);
        }
        return res;
    }
};
void PolnalyubviTop(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto & i : a) {
        cin >> i;i--;
    }
    vector<int> color(n, -1);
    vector<int> prev(n, -1);
    vector<int> next(n, -1);
    vector<vector<int>> cg(n);
    for (int i = 0; i < k; ++i) {
        int z1, z2;
        cin >> z1 >> z2;
        z1--;z2--;
        cg[z1].push_back(z2);
        cg[z2].push_back(z1);
        prev[z2] = z1;
        next[z1] = z2;
    }
    int c = 0;
    for (int i = 0; i < n; ++i) {
        if(color[i] == -1){
            dfs(i, color, cg, c);
            c++;
        }
    }
    vector<vector<int>> colvprint(c);
    vector<int> ans;
    vector<int> sn2(n, 0);
    for (int i = 0; i < n; ++i) {
        if(next[i] == -1){
            int v = i;
            sn2[v] = 1;
            colvprint[color[v]].push_back(v);
            while(prev[v] != -1){
                v = prev[v];
                sn2[v] = 1;
                if(color[a[v]] == color[v] and sn2[a[v]] == 1){
                    cout << 0;
                    return;
                }
                colvprint[color[v]].push_back(v);
            }
            reverse(colvprint[color[v]].begin(), colvprint[color[v]].end());
        }
    }
    vector<vector<int>> g;
    g.assign(c, {});
    vector<int> sz(c);
    for (int i = 0; i < n; ++i) {
        if(a[i] != -1){
            int q = color[a[i]], p = color[i];
            if(q != p){
                g[q].push_back(p);
                sz[p]++;
            }
        }
    }
    segtree st;
    st.make(c, sz);
    while(ans.size() != n){
        pair<int, int> rnow = st.getmin(0, c - 1);
        if(rnow.second != 0){
            cout << 0;
            return;
        }
        int v = rnow.first;
        st.chn(v, 1e7);
        for(auto &i : colvprint[v])
            ans.push_back(i);
        for(auto &i : g[v])
            st.upd(i, -1);
    }
    for(auto i : ans)
        cout << i + 1 << ' ';
}


signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n = 1;
    for (int i = 0; i < n; ++i) {
        PolnalyubviTop();
    }
}