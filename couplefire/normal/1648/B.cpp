#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;

int n, c, occ[N];

void solve(){
    cin >> n >> c;
    memset(occ, 0, sizeof(int)*(c+1));
    for(int i = 0; i<n; ++i){
        int a; cin >> a;
        ++occ[a];
    }
    for(int i = 1; i<=c; ++i)
        occ[i] += occ[i-1];
    auto get = [&](int l, int r)->int{
        r = min(r, c);
        return occ[r]-occ[l-1];
    };
    for(int i = 1; i<=c; ++i){
        if(!get(i, i)) continue;
        for(int j = 1; j*i<=c; ++j)
            if(get(i*j, i*(j+1)-1) && !get(j, j)){
                cout << "NO" << '\n';
                return;
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