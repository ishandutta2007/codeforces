#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <deque>
 
#define fi first
#define se second
 
using namespace std;
const int MOD = 1000 * 1000 * 1000 + 7;
const int MAXN = 1e5 + 100;
const int INF = 2e9 + 1000;
 
struct Per{
    int u;
    int l;
    int r;
    int s;
};
 
bool operator < (const Per& a, const Per& b){
    return a.u > b.u;
}
 
struct SGTree{
    pair<int, int> tr[MAXN * 4];
    int pos[MAXN];
    int sz;
 
    void Build(int v, int l, int r, int h){
        if (v == 0){
            sz = r;
        }
 
        if (l + 1 == r){
            tr[v] = {h, l};
            pos[l] = v;
            return;
        }
 
        int m = (l + r) / 2;
        Build(v * 2 + 1, l, m, h);
        Build(v * 2 + 2, m, r, h);
        tr[v] = min(tr[v * 2 + 1], tr[v * 2 + 2]);
    }
 
    pair<int, int> Get(int v, int l, int r, int cl, int cr){
        if (l >= cr || cl >= r){
            return {INF, INF};
        }
 
        if (l <= cl && cr <= r){
            return tr[v];
        } else {
            int cm = (cl + cr) / 2;
            return min(Get(v * 2 + 1, l, r, cl, cm), Get(v * 2 + 2, l, r, cm, cr));
        }
    }
 
    pair<int, int> Get(int l, int r){
        return Get(0, l, r, 0, sz);
    }
 
    void Upd(int i, int x){
        int v = pos[i];
        tr[v].fi = x;
        while (v != 0){
            v = (v - 1) / 2;
            tr[v] = min(tr[v * 2 + 1], tr[v * 2 + 2]);
        }
    }
};
 
int h, w, n;
Per mas[MAXN];
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    cin >> h >> w >> n;
    for (int i = 0; i < n; ++i){
        cin >> mas[i].u >> mas[i].l >> mas[i].r >> mas[i].s;
        mas[i].l--;
    }
 
    sort(mas, mas + n);
 
    SGTree mt;
    mt.Build(0, 0, w, h + 1);
    vector<pair<int, int>> st[MAXN];
 
    for (int i = 0; i < w; ++i){
        st[i].push_back({h + 1, 1});
    }
 
    for (int i = 0; i < n; ++i){
        //cout << i << endl;
        int cur_c = 0;
        while (mt.Get(mas[i].l, mas[i].r).fi <= mas[i].u + mas[i].s){
            int j = mt.Get(mas[i].l, mas[i].r).se;
            cur_c += st[j].back().se;
            //cout << cur_c << ' ' << j << ' ' << mt.Get(mas[i].l, mas[i].r).fi << ' ' << mt.Get(mas[i].l, mas[i].r).se << endl;
            cur_c %= MOD;
            st[j].pop_back();
            if (st[j].size() == 0){
                mt.Upd(j, INF);
            } else {
                mt.Upd(j, st[j].back().fi);
            }
        }
 
        if (mas[i].l == 0){
            cur_c *= 2;
            cur_c %= MOD;
            //cout << 'l' << ' ' << cur_c << endl;
            st[mas[i].r].push_back({mas[i].u, cur_c});
            mt.Upd(mas[i].r, mas[i].u);
        } else if (mas[i].r == w){
            cur_c *= 2;
            cur_c %= MOD;
            //cout << 'r' << ' ' << cur_c << endl;
            st[mas[i].l - 1].push_back({mas[i].u, cur_c});
            mt.Upd(mas[i].l - 1, mas[i].u);
        } else {
            //cout << 'm' << ' ' << cur_c << endl;
            st[mas[i].r].push_back({mas[i].u, cur_c});
            mt.Upd(mas[i].r, mas[i].u);
            st[mas[i].l - 1].push_back({mas[i].u, cur_c});
            mt.Upd(mas[i].l - 1, mas[i].u);
        }
    }
 
    int ans = 0;
    for (int i = 0; i < w; ++i){
        for (auto e : st[i]){
            ans += e.se;
            ans %= MOD;
        }
    }
 
    cout << ans << endl;
 
    return 0;
}