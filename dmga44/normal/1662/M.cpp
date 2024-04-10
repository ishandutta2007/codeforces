#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()

using namespace std;

typedef long long ll;
typedef vector<ll> dlist;
typedef vector<dlist> matrix;

void solve(int tc){
    int n, m;
    cin >> n >> m;

    int mr = 0, mw = 0, x, y;
    for(int i = 0; i < m; ++i){
        cin >> x >> y;
        mr = max(x, mr);
        mw = max(y, mw);
    }
    if(mr + mw > n) {
        cout << "IMPOSSIBLE\n";
        return;
    } 
    mw += n - mr - mw;
    cout << string(mr, 'R') << string(mw, 'W') << "\n";
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    for(int i = 1; i <= t; ++i)
        solve(i);

    return 0;
}//UH Top