#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(12);
    map<pair<int, int>, int> mp;
    int cnt = 0;
    for(int i = 9; i>=0; i--){
        if(i % 2 == 1) for(int j = 0; j<10; j++) mp[{i, j}] = cnt++;
        else for(int j = 9; j>=0; j--) mp[{i, j}] = cnt++;
    }
    vector<int> adj[100];
    for(int i = 0; i<10; i++){
        for(int j = 0; j<10; j++){
            int x; cin >> x;
            if(x) adj[mp[{i, j}]].push_back(mp[{i-x, j}]);
        }
    }
    double dp[100] = {0};
    for(int i = 98; i>=0; i--){
        int num = min(6, 99-i);
        double total = 6.0;
        for(int j = i+1; j<=i+num; j++){
            double mi = dp[j];
            for(auto k : adj[j]) mi = min(mi, dp[k]);
            total += mi;
        }
        dp[i] = total/(0.0+num);
    }
    cout << dp[0] << endl;
}