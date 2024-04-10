#include <bits/stdc++.h>
#define _FORTIFY_SOURCE 0
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("fast-math")
#define int long long
//#define double long double
using namespace std;
const int MAXN = 200000;
vector<int> strs[MAXN], cols[MAXN];
bool strused[MAXN], colused[MAXN];
void dfs(int i, int vertex){
    if (i==0){
        strused[vertex] = true;
        for (int j=0; j < strs[vertex].size(); j++){
            int to = strs[vertex][j];
            if (colused[to]) continue;
            dfs(1, to);
        }
    }
    else{
        colused[vertex] = true;
        for (int j=0; j < cols[vertex].size(); j++){
            int to = cols[vertex][j];
            if (strused[to]) continue;
            dfs(0, to);
        }
    }
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, q;
    cin >> n >> m >> q;
    for (int i=0; i < n; i++) strused[i] = false;
    for (int i=0; i < m; i++) colused[i] = false;
    for (int i=0; i < q; i++){
        int x, y;
        cin >> x >> y;
        strs[x-1].push_back(y-1);
        cols[y-1].push_back(x-1);
    }
    int cmp = 0;
    for (int i=0; i < n; i++){
        if (!strused[i]){
            dfs(0, i);
            cmp++;
        }
    }
    for (int i=0; i < m; i++){
        if (!colused[i]){
            dfs(1, i);
            cmp++;
        }
    }
    cout << cmp-1;
    return 0;
}