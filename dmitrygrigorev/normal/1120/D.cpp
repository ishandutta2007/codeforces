#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
vector<int> price;
vector<vector<int> > gr;
vector<vector<int> > children;
int ans=0;
vector<int> answer;
int INF = 1e18;
int dfs(int vertex, int last){
    for (int i=0; i < gr[vertex].size();i++){
        int to = gr[vertex][i];
        if (to==last) continue;
        children[vertex].push_back(dfs(to, vertex));
    }
    int s = 0, mx = -INF;
    for (int i=0; i < children[vertex].size(); i++){
        s += children[vertex][i];
        mx = max(mx, children[vertex][i]);
    }
    if (mx != -INF){
        ans+=s-mx;
    }
    else mx = price[vertex];
    mx = min(mx, price[vertex]);
    return mx;
}
void dfs2(int vertex, int last, int ret){
    int mx = -INF, amount = 0, what = -1;
    int cur = 0;
    for (int i=0; i < gr[vertex].size(); i++){
        int to = gr[vertex][i];
        if (to==last) continue;
        if (children[vertex][cur] == mx) amount++;
        else if (children[vertex][cur] > mx){
            mx = children[vertex][cur], amount = 1, what = to;
        }
        cur++;
    }
    if (mx == -INF) mx = INF;
    if (price[vertex] <= ret && price[vertex] <= mx) answer.push_back(vertex);
    cur = 0;
    for (int i=0; i < gr[vertex].size(); i++){
        int to = gr[vertex][i];
        if (to==last) continue;
        if (children[vertex][cur] == mx && amount==1){
            //cout <<  vertex << " " << to << endl;
            dfs2(to, vertex, min(ret, price[vertex]));
        }
        else dfs2(to, vertex, INF);
        cur++;
    }
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    gr.resize(n, {});
    price.resize(n, 0);
    children.resize(n, {});
    for (int i=0; i < n; i++) cin >> price[i];
    for (int i=0; i < n-1; i++){
        int u,v;
        cin >> u >> v;
        gr[u-1].push_back(v-1);
        gr[v-1].push_back(u-1);
    }
    ans += dfs(0, -1);
    cout << ans << " ";
    dfs2(0, -1, INF);
    sort(answer.begin(), answer.end());
    cout << answer.size() << endl;
    for (int i=0;i<answer.size();i++) cout << answer[i]+1 << " ";

}