#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> st;
    for(int i = 0; i<n; i++){
        int x; cin >> x;
        if(x != 1) while(st.back() != x-1) st.pop_back();
        else st.push_back(0);
        st.back()++;
        string ans = "";
        for(int a : st) ans += to_string(a)+".";
        ans.pop_back();
        cout << ans << endl;
    }
}

int main(){
    // freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
}