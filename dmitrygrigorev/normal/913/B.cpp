#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<vector<int> > data;
bool ans;
bool dfs(int vertex){
    if (data[vertex].size() == 0) return true;
    int sons = 0;
    for (int i=0; i < data[vertex].size(); i++){
        sons += dfs(data[vertex][i]);
    }
    if (sons < 3) ans = false;
    return false;
}
int32_t main(){
    int n;
    cin >> n;
    for (int i=0; i < n; i++){
        vector<int> help;
        data.push_back(help);
    }
    for (int i=0; i < n-1; i++){
        int A;
        cin >> A;
        data[A-1].push_back(i+1);
    }
    ans = true;
    dfs(0);
    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}