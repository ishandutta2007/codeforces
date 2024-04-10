#include <bits/stdc++.h>
using namespace std;

const int N = 300005;
mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());

int n, q, arr[N];
vector<int> pos[N];

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    for(int i = 0; i<n; i++)
        cin >> arr[i], pos[arr[i]].push_back(i);
    while(q--){
        int l, r; cin >> l >> r; --l; --r;
        int cnt = 0;
        for(int i = 0; i<40; i++){
            int v = arr[uniform_int_distribution<int>(l, r)(rng)];
            int tmp = upper_bound(pos[v].begin(), pos[v].end(), r)-lower_bound(pos[v].begin(), pos[v].end(), l);
            cnt = max(cnt, tmp);
        }
        cout << max(1, 2*cnt-(r-l+1)) << "\n";
    }
}