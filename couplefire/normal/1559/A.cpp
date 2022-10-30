#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int res = (1<<30)-1;
        for(int i = 0; i<n; ++i){
            int a; cin >> a;
            res &= a;
        }
        cout << res << '\n';
    }
}