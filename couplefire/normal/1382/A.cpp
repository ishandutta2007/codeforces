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
        int ans = 0;
        set<int> ss;
        for(int i = 0; i<n; i++){
            int a; cin >> a;
            ss.insert(a);
        }
        for(int i = 0; i<m; i++){
            int a; cin >> a;
            if(ss.count(a)) ans = a;
        }
        if(ans) cout << "YES" << endl << 1 << " " << ans << endl;
        else cout << "NO" << endl;
    }
}