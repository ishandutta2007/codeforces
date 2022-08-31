#include <bits/stdc++.h>

using namespace std;

#define int long long
const int K = 200005;
vector<int> dels[K];
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n/2);
    for (int i=0; i < n/2; i++) cin >> v[i];
    for (int i=1; i < K; i++){
        for (int j=i; j < K; j+=i) dels[j].push_back(i);
    }
    vector<int> ans;
    int now = 0;
    int INF = 1e18;
    for (int i=0; i < n/2; i++){
        int x = v[i];
        int kek = INF, par = 0;
        for (int j=0; j < dels[x].size(); j++){
            int A = dels[x][j], B = x / dels[x][j];
            if (A > B) swap(A, B);
            if (A%2 != B % 2) continue;
            int C = (A+B)/2, D = (B-A)/2;
            if (D <= now) continue;
            if (C < kek){
                kek = C, par = D;
            }
        }
        if (kek == INF){
            cout << "No";
            return 0;
        }
        ans.push_back(par*par-now*now);
        ans.push_back(v[i]);
        now = kek;
    }
    cout << "Yes" << endl;
    for (int i=0;i<n;i++) cout << ans[i] << " ";
    return 0;
}