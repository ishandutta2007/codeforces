#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    multiset<int> a, b;
    for(int i = 0; i<n; ++i){
        int x; cin >> x;
        a.insert(x);
    }
    for(int i = 0; i<n; ++i){
        int x; cin >> x;
        b.insert(x);
    }
    while(a.size()){
        if((*a.begin())==(*b.begin())){
            a.erase(a.begin());
            b.erase(b.begin());
            continue;
        } else if((*a.begin())>(*b.begin())){
            cout << "NO" << '\n';
            return;
        } else{
            int x = (*a.begin());
            a.erase(a.begin());
            auto it = b.find(x+1);
            if(it==b.end()){
                cout << "NO" << '\n';
                return;
            }
            b.erase(it);
        }
    }
    cout << "YES" << '\n';
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}