#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; string s1, s2;
    cin >> n >> s1 >> s2;
    int ans = 0;
    for(int i = 0; i<n;){
        if(s1[i]=='0' && s2[i]=='0'){
            if(i==n-1 || s1[i+1]!='1' || s2[i+1]!='1'){
                ++ans; ++i; continue;
            }
            ans += 2; i += 2;
        } else if(s1[i]=='1' && s2[i]=='1'){
            while(i<n && s1[i]=='1' && s2[i]=='1') ++i;
            if(i<n) ans += 2; ++i;
        } else ans += 2, ++i;
    }
    cout << ans << '\n';
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}