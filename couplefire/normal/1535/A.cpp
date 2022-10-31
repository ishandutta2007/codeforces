#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        vector<int> s(4);
        for(int i = 0; i<4; i++)
            cin >> s[i];
        int v1 = max(s[0], s[1]), v2 = max(s[2], s[3]);
        sort(s.rbegin(), s.rend());
        if(v1 < v2) swap(v1, v2);
        if(s[0] == v1 && s[1] == v2) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}