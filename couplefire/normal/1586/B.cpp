#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, m; cin >> n >> m;
    set<int> st;
    for(int i = 1; i<=n; ++i)
        st.insert(i);
    for(int i = 0; i<m; ++i){
        int a, b, c; cin >> a >> b >> c;
        if(st.count(b)) st.erase(b);
    }
    int pos = (*st.begin());
    for(int i = 1; i<=n; ++i)
        if(i!=pos) cout << pos << ' ' << i << '\n';
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}