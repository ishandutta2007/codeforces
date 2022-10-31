#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        set<int> st;
        for(int i = 0; i<n; ++i){
            int x; cin >> x;
            if(st.count(x)) x = -x;
            st.insert(x);
        }
        cout << st.size() << '\n';
    }
}