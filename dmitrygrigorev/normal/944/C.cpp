#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<vector<int> > data;
const int N = 200000;
int v[N];
void dfs(int a, int b){
    v[b]++;
    for (int i=0; i < data[a].size(); i++){
        int to = data[a][i];
        dfs(to, b+1);
    }
}
signed main()
{
    //freopen("1.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i=0; i < N; i++) v[i] = 0;
    for (int i=0; i < n; i++){
        vector<int> help;
        data.push_back(help);
    }
    for (int i=0; i < n-1; i++){
        int a;
        cin >> a;
        data[a-1].push_back(i+1);
    }
    dfs(0, 0);
    int ans = 0;
    for (int i=0; i < N; i++) ans += (v[i] % 2);
    cout << ans << endl;
    return 0;
}