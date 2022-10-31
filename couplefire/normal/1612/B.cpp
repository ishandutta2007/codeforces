#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--){
        int n, a, b; cin >> n >> a >> b;
        set<int, greater<>> stuff;
        for(int i = 1; i<=n; ++i)
            stuff.insert(i);
        stuff.erase(a); stuff.erase(b);
        vector<int> ans(n+1);
        ans[n/2] = a, ans[n] = b;
        bool bad = 0;
        for(int i = 1; i<=n/2-1; ++i){
            int lol = *stuff.begin();
            if(lol<a){
                cout << -1 << '\n';
                bad = 1; break;
            }
            stuff.erase(lol);
            ans[i] = lol;
        }
        if(bad) continue;
        if((*stuff.begin())>b){
            cout << -1 << '\n';
            continue;
        }
        for(int i = n/2+1; i<=n-1; ++i)
            ans[i] = (*stuff.begin()), stuff.erase(stuff.begin());
        for(int i = 1; i<=n; ++i)
            cout << ans[i] << ' ';
        cout << '\n';
    }
}