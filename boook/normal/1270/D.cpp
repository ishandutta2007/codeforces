#include <bits/stdc++.h>
using namespace std;
#define int long long
#define maxn 100090
#define PII pair<int, int>

int n, k;


int32_t main() {
    cin.tie(0), cout.sync_with_stdio(0);
    cin >> n >> k;
    
    vector<PII> sol;
    for (int i = 1; i <= k + 1; ++ i) {
        cout << "?";
        for (int j = 1; j <= k + 1; ++ j) if (j != i) cout << " " << j;
        cout << endl;cout.flush();
        int v1, v2;
        cin >> v1 >> v2;
        sol.emplace_back(v1, v2);
    }

    int big = 0, cnt = 0;
    for (auto to : sol) big = max(big, to.second);
    for (auto to : sol) if (big == to.second) cnt ++;

    cout << "! " << cnt << endl;
    return 0;
}