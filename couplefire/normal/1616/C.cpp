#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i<n; ++i)
        cin >> arr[i];
    int ans = n-1;
    for(int a = 0; a<n; ++a)
        for(int b = a+1; b<n; ++b){
            vector<int> tmp = arr;
            for(int i = 0; i<n; ++i)
                tmp[i] *= b-a;
            int d = (tmp[b]-tmp[a])/(b-a);
            int s = tmp[a]-d*a;
            int lol = 0;
            for(int i = 0; i<n; ++i)
                if(s+i*d!=tmp[i]) ++lol;
            ans = min(ans, lol);
        }
    cout << ans << '\n';
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}