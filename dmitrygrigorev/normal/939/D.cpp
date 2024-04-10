#include <bits/stdc++.h>
#define int long long
using namespace std;
const int K = 26;
vector<pair<char, char> > ans;
vector<vector<int> > data(K);
vector<bool> used(K);
void dfs(int vertex){
    used[vertex] = true;
    for (int i=0; i < data[vertex].size(); i++){
        int to = data[vertex][i];
        if (used[to]) continue;
        ans.push_back(make_pair((char) (vertex+'a'), (char) (to+'a')));
        dfs(to);
    }
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    for (int i=0; i < n; i++){
        int A = a[i] - 'a';
        int B = b[i] - 'a';
        data[A].push_back(B);
        data[B].push_back(A);
    }
    fill(used.begin(), used.end(), false);
    for (int i=0; i < 26; i++){
        if (!used[i]) dfs(i);
    }
    cout << ans.size() << endl;
    for (int i=0; i < ans.size(); i++) cout << ans[i].first << " " << ans[i].second << endl;
}