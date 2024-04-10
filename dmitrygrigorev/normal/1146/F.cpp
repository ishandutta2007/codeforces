#include <bits/stdc++.h>
#define ll long long
using namespace std;
int mod = 998244353;
const int K = 200000;
int dp[K][2];
vector<vector<int> > data;
int sum(int a, int b){
    if (a+b < 0) return a+b+mod;
    if (a+b >= mod) return a+b-mod;
    return a+b;
}
int mult(int a, int b){
    return ((ll) a * (ll)b) % (ll) mod;
}
void dfs(int vertex){
    vector<pair<int, int> > dps;
    for (int i=0; i < data[vertex].size(); i++){
        int to = data[vertex][i];
        dfs(to);
        dps.push_back({dp[to][0], dp[to][1]});
    }
    if (data[vertex].size() == 0){
        dp[vertex][1] = 1;
        dp[vertex][0] = 1;
        return;
    }
    int A = 1, B = 1, C = 1;
    for (int i=0;i<dps.size();i++){
        A = mult(A, dps[i].first);
        B = mult(B, dps[i].second);
        C = mult(C, sum(dps[i].first, dps[i].second));
    }
    vector<int> prefa, suffa;
    prefa.push_back(1), suffa.push_back(1);
    for (int i=0; i < dps.size(); i++) prefa.push_back(mult(prefa.back(), dps[i].first));
    for (int i=0; i < dps.size(); i++) suffa.push_back(mult(suffa.back(), dps[dps.size() - i - 1].first));
    reverse(suffa.begin(), suffa.end());
    int T = 0;
    for (int i=0; i < dps.size(); i++){
        T = sum(T, mult(dps[i].second, mult(prefa[i], suffa[i+1])));
        //cout << prefa[i] << " " << suffa[i+1] << endl;
    }
    //if (vertex==0) cout <<A << " " << B << " " << C << " " << T << endl;
    dp[vertex][0] = sum(dp[vertex][0], A);
    dp[vertex][0] = sum(dp[vertex][0], sum(sum(C, -A), -T));
    dp[vertex][1] = sum(dp[vertex][1], sum(C, -A));
}
main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    data.resize(n, {});
    for (int i=0; i < n-1; i++){
        int u;
        cin >> u;
        data[u-1].push_back(i+1);
    }
    dfs(0);
    cout << dp[0][0];
}