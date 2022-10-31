#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 1500+1, mod = 998244353;

int n;
int a[N][N];

int p[N];
vector<ll> dp[N];
int cnt[N];

void init(){
    for(int i = 0; i < n; ++i){
        p[i] = i;
        dp[i].push_back(1);
        cnt[i] = 0;
    }
}
int leader(int v){
    return p[v] = (p[v] == v ? v : leader(p[v]));
}
vector<ll> vec;
void unite(int u, int v){
    u = leader(u);
    v = leader(v);
    ++cnt[u];
    if(u == v)
        goto END;
    if(dp[u].size() < dp[v].size())
        swap(u, v);
    p[v] = u;
    cnt[u] += cnt[v];
    vec = vector<ll>(dp[u].size() + dp[v].size(), 0);
    for(int i = 0; i < dp[u].size(); ++i)
        for(int j = 0; j < dp[v].size(); ++j)
            vec[i+j+1] = (vec[i+j+1] + dp[u][i]*dp[v][j])%mod;
    dp[u] = vec;
END:
    if(cnt[u] == dp[u].size()*(dp[u].size()-1)/2)
        ++dp[u][0];
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    cin >> n;
    init();
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            cin >> a[i][j];
    vector<pair<ll, pair<int, int>>> vec;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < i; ++j)
            vec.emplace_back(a[i][j], pair<int, int>{i, j});
    sort(vec.begin(), vec.end());
    for(int i = 0; i < vec.size(); ++i)
        unite(vec[i].second.first, vec[i].second.second);
    int v = leader(0);
    for(int i = 0; i < n; ++i)
        cout << dp[v][i] << " ";
    cout << "\n";
}