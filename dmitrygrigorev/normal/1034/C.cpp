#include <bits/stdc++.h>
#define LL long long
using namespace std;
int MOD = 1e9+7;
const int K = 1000001;
vector<int> Data[K];
int a[K], f[K];
int dp[K];
void dfs(int vertex, int last, vector<LL> &cost, vector<LL> &w){
    LL W = cost[vertex];
    for (int i=0; i < Data[vertex].size(); i++){
        int to = Data[vertex][i];
        if (to == last) continue;
        dfs(to, vertex, cost, w);
        W += w[to];
    }
    w[vertex] = W;
}
LL gcd(LL a, LL b){
    if (b==0) return a;
    return gcd(b, a%b);
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<LL> v(n), h(n);
    for (int i=0; i < n; i++) cin >> v[i];
    for (int i=0; i < n-1; i++){
        int a;
        cin >> a;
        Data[i+1].push_back(a-1), Data[a-1].push_back(i+1);
    }
    //return 0;
    dfs(0, -1, v, h);
    //return 0;
    //for (int i=1; i < K; i++) for (int j=i+i; j < K; j+=i) del[j].push_back(i);
    LL S = h[0];
    for (int i=0; i < n; i++){
        LL G = S/gcd(S, h[i]);
        if (G <= n) a[G]++;
    }
    for (int i=n; i >= 1; i--){
        for (int j=i; j <= n; j += i) f[j] += a[i];
    }
    //for (int i=1; i <= n; i++) cout << a[i] << endl;
    dp[1] = 1;
    for (int i=1; i <= n; i++){
        for (int j=i+i; j <= n; j+=i){
            if (f[j] != j) continue;
            dp[j] += dp[i];
            dp[j] %= MOD;
        }
    }
    LL ans = 0;
    for (int i=1;i<=n;i++){
        ans += dp[i];
        //ans %= MOD;
    }
    cout << ans%MOD;



}