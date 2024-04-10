#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, m; cin >> n >> m;
    string s; cin >> s;
    vector<int> ans(n*m, 0);
    int cur = 0;
    vector<bool> good(m, 0);
    int recent = -n*m-5;
    for(int i = 0; i<n*m; ++i){
        if(!good[i%m] && s[i]=='1')
            good[i%m] = 1, ++cur;
        if(s[i]=='1')
            recent = i;
        ans[i] = (i>=m?ans[i-m]:0)+(i-m<recent);
        cout << cur+ans[i] << ' ';
    }
    cout << '\n';
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}