#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i<n; ++i)
        cin >> arr[i], --arr[i];
    check:{
        vector<int> cnt(n);
        for(int i = 0; i<n; ++i)
            ++cnt[arr[i]];
        int odd = 0;
        for(int i = 0; i<n; ++i)
            if(cnt[i]&1) ++odd;
        if(odd>1){
            cout << "NO" << '\n';
            return;
        }
        if(n&1){
            int bruh = 0;
            for(int i = 0; i<n; ++i)
                if(arr[i]==arr[n/2])
                    ++bruh;
            if(bruh==1){
                cout << "NO" << '\n';
                return;
            }
        }
        cout << "YES" << '\n';
    }
    vector<int> nxt(n), prv(n);
    vector<int> fa(n, 0), siz(n, 1);
    iota(fa.begin(), fa.end(), 0);
    auto find = [&](int v)->int{
        while(v!=fa[v]) v = fa[v];
        return v;
    };
    auto unite = [&](int u, int v)->void{
        u = find(u), v = find(v);
        if(siz[u]>siz[v]) swap(u, v);
        fa[u] = v; siz[v] += siz[u];
    };
    init:{
        vector<vector<int>> stuff(n);
        for(int i = 0; i<n; ++i)
            stuff[arr[i]].push_back(i);
        int lst = -1;
        int l = 0, r = n-1;
        for(int i = 0; i<n; ++i){
            if(stuff[i].size()&1){
                lst = i;
                continue;
            }
            bool cur = 0;
            while(!stuff[i].empty()){
                if(cur) nxt[stuff[i].back()] = l++;
                else nxt[stuff[i].back()] = r--;
                stuff[i].pop_back(); cur ^= 1;
            }
        }
        if(lst>=0){
            if(stuff[lst].front()==n/2)
                reverse(stuff[lst].begin(), stuff[lst].end());
            bool cur = 0;
            while(!stuff[lst].empty()){
                if(cur) nxt[stuff[lst].back()] = l++;
                else nxt[stuff[lst].back()] = r--;
                stuff[lst].pop_back(); cur ^= 1;
            }
        }
        for(int i = 0; i<n; ++i)
            unite(i, nxt[i]), prv[nxt[i]] = i;
    }
    for(int i = 0, j = n-1; i<j; ++i, --j){
        if(find(i)==find(j)) continue;
        swap(nxt[prv[i]], nxt[prv[j]]);
        swap(prv[i], prv[j]);
        unite(i, j);
    }
    for(int i = 0, j = n-1; i<j-2; ++i, --j){
        if(find(i)==find(i+1)) continue;
        nxt[prv[i]] = i+1; nxt[prv[j]] = j-1;
        nxt[prv[i+1]] = j; nxt[prv[j-1]] = i;
        int pi = prv[i], pj = prv[j], pi1 = prv[i+1], pj1 = prv[j-1];
        prv[i] = pj1; prv[j-1] = pj; prv[j] = pi1; prv[i+1] = pi;
        unite(i, i+1);
    }
    for(int i = 0; i<n; ++i)
        cout << prv[i]+1 << ' ';
    cout << '\n';
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}