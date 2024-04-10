#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        set<int> st;
        for(int i = 0; i<n; i++){
            int a; cin >> a;
            st.insert(a);
        }
        int cnt = 0;
        for(int i = 0; i<m; i++){
            int a; cin >> a;
            if(st.count(a)) cnt++;
        }
        cout << cnt << endl;
    }
}