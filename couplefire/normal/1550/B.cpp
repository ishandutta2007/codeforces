#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--){
        int n, a, b; cin >> n >> a >> b;
        string s; cin >> s;
        if(b >= 0){
            cout << a*n+b*n << '\n';
            continue;
        }
        int cnt[2] = {0, 0};
        for(int i = 0; i<n; i++){
            int tmp = i;
            while(i < n-1 && s[i+1] == s[tmp]) i++;
            cnt[s[i]-'0']++;
        }
        cout << a*n+min(cnt[0],cnt[1])*b+b << '\n';
    }
}