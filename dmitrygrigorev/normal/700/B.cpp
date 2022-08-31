#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<vector<int> > data;
vector<int> t;
int ans, k;
int dfs(int vertex, int last){
    int var = t[vertex];
    for (int i=0; i < data[vertex].size(); i++){
        int to = data[vertex][i];
        if (to == last) continue;
        int res = dfs(to, vertex);
        var += res;
    }
    ans += min(var, 2*k - var);
    return var;
}
signed main(){
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n >> k;
    for (int i=0; i < n; i++){
        vector<int> help;
        data.push_back(help);
        t.push_back(0);
    }
    for (int i=0; i < 2*k ; i++){
        int a;
        cin >> a;
        t[a-1]++;
    }
    for (int i=0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        data[a-1].push_back(b-1);
        data[b-1].push_back(a-1);
    }
    ans = 0;
    dfs(0, -1);
    cout << ans << endl;
    return 0;
}