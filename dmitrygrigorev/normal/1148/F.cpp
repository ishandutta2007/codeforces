#include<bits/stdc++.h>
#define int long long
using namespace std;
struct Ans{int l; int r; int d;};
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int> > v;
    for (int i=0; i < n; i++){
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    int ans = 0;
    vector<bool> nec(n);
    fill(nec.begin(), nec.end(), false);
    int sum = 0;
    for (int i=0;i<n;i++) sum += v[i].first;
    if (sum < 0){
        for (int i=0;i<n;i++) v[i].first *= -1;
    }
    vector<int> lb(n);
    for (int i=0; i < n; i++){
        for (int j=0; j < 62; j++){
            int ba = (1LL<<j)&v[i].second;
            if (ba != 0){
                lb[i] = j;
                break;
            }
        }
    }
    for (int i=61; i >= 0; i--){
        int tet = 0;
        for (int j=0; j < n; j++){
            if (lb[j] != i) continue;
            if (!nec[j]) tet += v[j].first;
            else tet += -v[j].first;
        }
        if (tet > 0){
            ans += (1LL<<i);
            for (int j=0; j < n; j++){
                int ba = (1LL<<i)&v[j].second;
                if (ba != 0){
                    if (nec[j]) nec[j] = false;
                    else nec[j] = true;
                }
            }
        }
    }
    cout << ans;
}