#include <bits/stdc++.h>
using namespace std;
 
void solve(){
    int n, m; cin >> n >> m;
    vector<int> must(n, 0);
    vector<int> cnt(n, 0);
    vector<vector<int>> stuff(m);
    vector<int> ans(m, -1);
    for(int i = 0; i<m; i++){
        int k; cin >> k;
        for(int j = 0; j<k; j++){
            int a; cin >> a; --a;
            stuff[i].push_back(a);
            cnt[a]++;
        }
        if(k == 1) must[stuff[i][0]]++;
    }
    int mx = (m+1)/2;
    for(int i = 0; i<n; i++){
        if(must[i] > mx){
            cout << "NO" << endl;
            return;
        }
    }
    int best = 0;
    for(int i = 0; i<n; i++){
        if(cnt[i]>cnt[best]) best = i;
    }
    for(int i = 0; i<m; i++){
        if(stuff[i].size() == 1 && stuff[i][0] == best){
            ans[i] = best;
        }
    }
    int num = must[best];
    for(int i = 0; i<m; i++){
        if(ans[i] != -1) continue;
        int take = 0;
        for(int j = 0; j<stuff[i].size(); j++){
            if(num < mx && stuff[i][j] == best) take = j;
            if(num == mx && stuff[i][j] != best) take = j;
        }
        ans[i] = stuff[i][take];
        if(stuff[i][take] == best) num++;
    }
    cout << "YES" << endl;
    for(int i = 0; i<m; i++) cout << ans[i]+1 << " ";
    cout << endl;
}
 
int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
}