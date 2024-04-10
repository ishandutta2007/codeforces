#include<bits/stdc++.h>
using namespace std;
const int MN = 2e5+5;
vector<array<int,2>> st[MN], ed[MN];
int p[MN];
int find (int n) {return p[n] == n ? n : p[n] = find(p[n]);}
void merge (int a, int b) {p[find(a)] = find(b);}
void solve () {
    int n; scanf ("%d",&n);
    vector<int> xs;
    vector<array<int,3>> v(n);
    for (auto &[c,l,r] : v) {
        scanf ("%d %d %d",&c,&l,&r);
        xs.push_back(l); xs.push_back(r);
    }
    sort(xs.begin(),xs.end());
    xs.erase(unique(xs.begin(),xs.end()),xs.end());
    auto getx = [&] (int x) {
        return lower_bound(xs.begin(),xs.end(),x) - xs.begin() + 1;
    };
    for (int i = 0; i <= (int)xs.size(); i++) st[i].clear(), ed[i].clear();
    int id = 0;
    for (auto &[c,l,r] : v) {
        l = getx(l), r = getx(r);
        ++id;
        st[l].push_back({id,c}); ed[r].push_back({id,c});
    }
    for (int i = 1; i <= n; i++) p[i] = i; 
    vector<int> cnt(2);
    map<int, int> cmps;
    for (int t = 1; t <= (int)xs.size(); t++) {
        for (auto [id,c] : st[t]) {
            ++cnt[c]; ++cmps[find(id)];
            if (min(cnt[0],cnt[1]) > 0) {
                int lst = -1;
                for (auto [i,cc] : cmps) {
                    assert(cc > 0);
                    if (lst != -1) merge(lst,i);
                    lst = i;
                }
                cmps.clear();
                cmps[find(id)] = cnt[0] + cnt[1];
            }
        }
        for (auto [id,c] : ed[t]) {
            --cnt[c];
            if (!(--cmps[find(id)])) cmps.erase(find(id));
        }
    }
    int ret = 0;
    for (int i = 1; i <= n; i++) ret += find(i) == i;
    printf ("%d\n",ret);
}
int main () {
    int t; scanf ("%d",&t);
    while (t--) solve();
    return 0;
}