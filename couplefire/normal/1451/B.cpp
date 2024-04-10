#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n, q; cin >> n >> q;
        string s; cin >> s;
        while(q--){
            int l, r; cin >> l >> r; --l; --r;
            bool one = 0, two = 0;
            for(int i = 0; i<l; i++) if(s[i] == s[l]) one = 1;
            for(int i = r+1; i<n; i++) if(s[i] == s[r]) two = 1;
            if(one || two) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
}