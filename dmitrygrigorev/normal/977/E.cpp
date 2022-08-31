#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<vector<int> > data;
vector<bool> comp;
bool able;
void dfs(int vertex){
    comp[vertex] = true;
    if (data[vertex].size() != 2) able = false;
    for (int i=0;i<data[vertex].size(); i++){
        int to = data[vertex][i];
        if (comp[to]) continue;
        dfs(to);
    }
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i=0;i<n;i++) data.push_back({});
    for (int i=0;i<n;i++) comp.push_back(false);
    for (int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        data[a-1].push_back(b-1);
        data[b-1].push_back(a-1);
    }
    int ans=0;
    for (int i=0; i < n; i++){
        if (!comp[i]){
            able=true;
            dfs(i);
            if (able) ans++;
        }
    }
    cout << ans;
    return 0;
}


/*

1
6 6
3 6
3 4
1 4
1 2
1 3
2 3

*/