#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;
const int INF = 1000000000;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k, v; cin >> n >> k >> v;
    vector<int> V(n);

    int maxx = 0;
    for (int i = 0; i < n; ++i) {
        cin >> V[i];
        maxx += V[i];
    }    

    if (maxx < v) {
        cout << "NO" << endl;
        return 0;
    }

    if (v % k == 0) {
        cout << "YES" << endl;
        for (int i = 1; i < n; ++i) 
            cout << INF << " " << i + 1 << " " << 1 << '\n';
        if (v / k != 0) cout << v / k << " " << 1 << " " << 2 << '\n';
        return 0;
    }

    vector<vector<int>> dp(n + 1, vector<int>(k, -1));
    dp[0][0] = -2;
    
    cerr << "DOING DP" << endl;

    for (int i = 0; i < n; ++i) {
        dp[i + 1] = dp[i];
        for (int j = 0; j < k; ++j) {
            if (dp[i][j] == -1) continue;
            dp[i + 1][(j + V[i]) % k] = i;
        }
    }

    if (dp[n][v % k] == -1) {
        cout << "NO" << endl;
        return 0;
    }
    
    cerr << "DONE DP" << endl;

    const int INF = 1000000000;
    vector<int> sol;
    
    int at = dp[n][v % k];
    int rem = v % k;

    vector<bool> in_sol(n, 0);
    while (at >= 0) {
        sol.push_back(at);
        
        rem = (rem - V[at]) % k;
        if (rem < 0) rem += k;
        
        in_sol[at] = true;
        at = dp[at][rem];
    }

    assert(sol.size());
   /* 
    for (auto x : sol) 
        cerr << x << " "; 
    cerr << endl;
*/
    cout << "YES" << endl;
    cerr << "POUR INTO USE" << endl;

    int use = sol[0];
    for (int i = 1; i < (int)sol.size(); ++i) {
        cout << INF << " " << sol[i] + 1 << " " << use + 1 << "\n";
        V[use] += V[sol[i]];
        V[sol[i]] = 0;
    }

    
    cerr << "POUR INTO OTH" << endl;
    int oth = use == 0 ? 1 : use - 1;
    for (int i = 0; i < n; ++i) {
        if (i != oth && i != use && V[i] > 0) {
            cout << INF << " " << i + 1 << " " << oth + 1 << '\n';
            V[oth] += V[i];
            V[i] = 0;
        }
    }

    assert(V[oth] + V[use] == maxx);
    assert(V[use] % k == v % k);
    
    cerr << "EQUIL" << endl;
    if (V[use] > v) {
        cout << (V[use] - v) / k << " " << use + 1 << " " << oth + 1 << '\n';
    }
    if (V[use] < v) {
        cout << (v - V[use]) / k << " " << oth + 1 << " " << use + 1 << '\n';
    }
    

    return 0;
}