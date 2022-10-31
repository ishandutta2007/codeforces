#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int n, m, q; cin >> n >> m >> q;
    set<array<int, 2>> lol;
    for(int i = 0; i<q; ++i){
        int a, b; cin >> a >> b;
        lol.insert({a, b});
    }
    int ans = 0;
    vector<array<int, 2>> cur = {{1, 1}};
    while(++ans){
        vector<array<int, 2>> nxt;
        for(auto [a, b] : cur){
            if(a==n && b==m){
                cout << ans-1 << '\n';
                exit(0);
            }
            int add = (lol.find({a, b})!=lol.end());
            nxt.push_back({min(n, a+b+add), b});
            nxt.push_back({a, min(m, a+b+add)});
        }
        sort(nxt.rbegin(), nxt.rend());
        int mx = 0;
        cur.clear();
        for(auto [a, b] : nxt){
            if(b<=mx) continue;
            cur.push_back({a, b});
            mx = b;
        }
    }
}