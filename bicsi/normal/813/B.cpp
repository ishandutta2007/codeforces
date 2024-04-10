#include <vector>
#include <algorithm>
#include <cstring>
#include <set>
#include <cassert>
#include <iostream>

using namespace std;
#define int long long

int mul(int a, int b) {
    int r = a * b;
    if (r / a != b) return -1;
    return r;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int x, y, l, r; cin >> x >> y >> l >> r;
    int px = 1;
    vector<int> All;
    
    for (int i = 0; ; ++i) {
        int py = 1;
        for (int j = 0; ; ++j) {
            int prod = px + py;
            
            if (l <= prod && prod <= r)
                All.push_back(prod);
            py = mul(py, y); if (py == -1) break;
        }
        px = mul(px, x); if (px == -1) break;
    }
       
    All.push_back(l - 1); All.push_back(r + 1);
    //for (auto x : All) cerr << x << " "; cerr << endl;
    sort(All.begin(), All.end());
        
    int ans = 0;
    for (int i = 1; i < All.size(); ++i) {
        ans = max(ans, All[i] - All[i - 1] - 1);
    }
    cout << ans << endl;


    return 0;
}