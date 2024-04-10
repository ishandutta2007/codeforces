#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> nxt(n+1);
    for(int i = 1; i<=n; i++)
        cin >> nxt[i], nxt[i] = i-nxt[i];
    vector<bool> inSt(n+1); stack<int> st;
    int v = 1;
    while(!inSt[v]){
        st.push(v); inSt[v] = 1;
        v = nxt[v];
    }
    vector<int> ans{v};
    while(st.top() != v)
        ans.push_back(st.top()), st.pop();
    cout << ans.size() << '\n';
    for(auto a : ans)
        cout << a << " ";
    cout << '\n';
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}