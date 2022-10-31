#include <bits/stdc++.h>
using namespace std;

int n, res;
vector<bool> vis;
vector<int> indeg, ans, brr, lol;
set<int> st;

void reset(){
    indeg.clear();
    indeg.assign(n, 0);
    vis.clear();
    vis.assign(n, 0);
    ans.clear(); 
    ans.assign(n, -1);
    st.clear();
    brr.clear();
    brr.resize(n);
    res = 0;
    lol.clear();
    lol.assign(n, 0);
}

void solve(){
    cin >> n;
    reset();
    for(int i = 0; i<n; i++){
        cin >> brr[i]; --brr[i];
        lol[brr[i]]++;
    }
    vector<int> huh(n);
    iota(huh.begin(), huh.end(), 0);
    sort(huh.begin(), huh.end(), [&](int a, int b){return lol[a]<lol[b];});
    for(int i = 0; i<n; i++){
        if(vis[huh[i]]) continue;
        int v = huh[i];
        while(!indeg[brr[v]]){
            vis[v] = 1;
            indeg[brr[v]]++;
            ans[v] = brr[v];
            res++;
            v = brr[v];
        }
    }
    for(int i = 0; i<n; i++)
        if(!indeg[i]) st.insert(i);
    vector<int> blah(n);
    iota(blah.begin(), blah.end(), 0);
    sort(blah.begin(), blah.end(), [&](int a, int b){return (ans[a]==-1&&indeg[a]==0)>(ans[b]==-1&&indeg[b]==0);});
    for(int i = 0; i<n; i++)
        if(ans[blah[i]] == -1){
            int tmp = (*st.begin());
            if(tmp == blah[i]) tmp = (*next(st.begin()));
            ans[blah[i]] = tmp;
            st.erase(tmp);
        }
    cout << res << '\n';
    for(int i = 0; i<n; i++)
        cout << ans[i]+1 << " ";
    cout << '\n';
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}