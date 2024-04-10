#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<vector<int> > data;
vector<int> lst;
int dfs(int vertex){
    int ctr = 0;
    bool go = false;
    for (int i=0; i < data[vertex].size(); i++){
        int to = data[vertex][i];
        go = true;
        ctr += dfs(to);
    }
    if (!go) ctr = 1;
    lst.push_back(ctr);
    return ctr;
}
signed main(){
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
    dfs(0);
    sort(lst.begin(), lst.end());
    for (int i=0;i<lst.size();i++) cout << lst[i] << " ";

}