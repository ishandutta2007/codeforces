#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<vector<int> > data;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i=0; i < n; i++){
        vector<int> help;
        data.push_back(help);
    }
    for (int i=0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        data[a-1].push_back(b-1);
        data[b-1].push_back(a-1);
    }
    vector<int> vis(n);
    for (int i=0; i < n; i++) cin >> vis[i];
    for (int i=0; i < n; i++) vis[i]--;
    if (vis[0] != 0){
        cout << "No";
        return 0;
    }
    vector<bool> b(n);
    fill(b.begin(), b.end(), false);
    b[0] = true;
    queue<int> q;
    q.push(0);
    int ind = 1;
    while (q.size()){
        int V = q.front();
        q.pop();
        set<int> frees;
        for (int i=0; i < data[V].size(); i++){
            if (!b[data[V][i]]) frees.insert(data[V][i]);
        }
        while (ind < n && frees.size()){
            int nw = vis[ind];
            if (!frees.count(nw)){
                cout << "No";
                return 0;
            }
            frees.erase(frees.find(nw));
            b[nw] = true;
            q.push(nw);
            ind++;
        }
        if (frees.size()){
            cout << "No";
            return 0;
        }
    }
    if (ind != n){
        cout << "No";
        return 0;
    }
    cout << "Yes";


}