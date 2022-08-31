#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<vector<pair<int, int> > > data;
vector<int> w;
vector<vector<int> > up;
int INF = -1e18;
void dfs(int vertex, int last){
    int mx = 0;
    for (int i=0; i < data[vertex].size(); i++){
        int to = data[vertex][i].first;
        if (to==last) continue;
        dfs(to, vertex);
        if (up[to].back() >= data[vertex][i].second){
            up[vertex].push_back(up[to].back() - data[vertex][i].second + w[vertex]);
        }
        else up[vertex].push_back(INF);
        mx = max(mx, up[vertex].back());
    }
    up[vertex].push_back(w[vertex]);
    mx = max(mx, up[vertex].back());
    up[vertex].push_back(mx);
    return;
}
int ans=0;
void dfs2(int vertex, int last, int path){
    path += w[vertex];
    int num = up[vertex].size() - 1;
    int pref[num+1], suff[num+1];
    pref[0] = 0, suff[0] = 0;
    for (int i=0; i < up[vertex].size() - 1; i++) pref[i+1] = max(pref[i], up[vertex][i]);
    for (int i=0; i < up[vertex].size() - 1; i++) suff[i+1] = max(suff[i], up[vertex][num-i-1]);
    ans = max(path, ans);
    int ctr = 0;
    for (int i=0; i < data[vertex].size(); i++){
        int to = data[vertex][i].first;
        if (to==last) continue;
        int M = max(path, max(pref[ctr], suff[num-ctr-1]));
        if (M >= data[vertex][i].second){
            dfs2(to, vertex, M-data[vertex][i].second);
        }
        else dfs2(to, vertex, 0);
        ctr++;
    }
}
signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    srand(time(0));
    int n;
    cin >> n;
    data.resize(n, {});
    w.resize(n, 0);
    for (int i=0; i < n; i++) cin >> w[i];
    up.resize(n, {});
    for (int i=0; i < n-1; i++){
        int a, b, c;
        cin >> a >> b >> c;
        data[a-1].push_back({b-1, c});
        data[b-1].push_back({a-1, c});
    }
    dfs(0, -1);
    //return 0;
    dfs2(0, -1, 0);
    cout << ans;
}