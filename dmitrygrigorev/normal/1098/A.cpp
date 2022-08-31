#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<vector<int> > data;
int ans=0, INF = 1e12;
vector<int> a;
void dfs(int vertex, int sum){
    if (a[vertex] != -1){
        if (a[vertex] < sum){
            cout << -1;
            exit(0);
        }
        ans += a[vertex]-sum;
        sum = a[vertex];
        for (int i=0; i < data[vertex].size(); i++){
            int to = data[vertex][i];
            dfs(to, sum);
        }
    }
    else{
        int mn = INF;
        for (int i=0; i < data[vertex].size(); i++){
            int to = data[vertex][i];
            mn = min(mn, a[to]);
        }
        if (mn < sum){
            cout << -1;
            exit(0);
        }
        if (mn == INF){
            return;
        }
        ans += mn - sum;
        sum = mn;
        for (int i=0; i < data[vertex].size(); i++){
            int to = data[vertex][i];
            dfs(to, sum);
        }
    }
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    data.resize(n, {});
    for (int i=0; i < n-1; i++){
        int x;
        cin >> x;
        data[x-1].push_back(i+1);
    }
    a.resize(n, -1);
    for (int i=0; i < n; i++) cin >> a[i];
    dfs(0, 0);
    cout << ans;
    return 0;
}