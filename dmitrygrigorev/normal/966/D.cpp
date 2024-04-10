#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
vector<vector<int> > data;
vector<bool> used, da;
vector<int> ms;
void dfs(int vertex){
    used[vertex] = true;
    ms.push_back(vertex);
    for (int i=0; i < data[vertex].size(); i++){
        int to = data[vertex][i];
        if (used[to]) continue;
        if (!da[to]) continue;
        dfs(to);
    }
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i=0; i < n; i++){
        vector<int> help;
        data.push_back(help);
        used.push_back(false);
    }
    set<pair<int, int> > reb;
    for (int i=0; i < m; i++){
        int x, y;
        cin >> x >> y;
        if (x>y) swap(x, y);
        reb.insert(make_pair(x-1, y-1));
        data[x-1].push_back(y-1);
        data[y-1].push_back(x-1);
    }
    if (data[0].size() == 0){
        cout << -1;
        return 0;
    }
    for (int i=0; i < data[0].size(); i++){
        if (data[0][i] == n-1){
            cout << 1 << endl;
            cout << 1 << " " << n << endl;
            return 0;
        }
    }
    for (int i=0; i < data[0].size(); i++){
        int to = data[0][i];
        for (int j=0; j < data[to].size(); j++){
            int tt = data[to][j];
            if (tt == n-1){
                cout << 2 << endl;
                cout << 1 << " " << to+1 << " " << n << endl;
                return 0;
            }
        }
    }
    vector<bool> db(n);
    for (int i=0;i<n;i++) da.push_back(false);
    fill(db.begin(), db.end(), false);
    for (int i=0; i < data[0].size(); i++){
        int to = data[0][i];
        da[to] = true;
    }
    for (int i=0; i < data[n-1].size(); i++){
        int to = data[n-1][i];
        db[to] = true;
    }
    for (int i=0; i < n; i++){
        if (!da[i]) continue;
        for (int j=0; j < data[i].size(); j++){
            int to = data[i][j];
            if (db[to]){
                cout << 3 << endl;
                cout << 1 << " " << i+1 << " " << to+1 << " " << n << endl;
                return 0;
            }
        }
    }
    for (int i=0; i < n; i++){
        if (!da[i]) continue;
        for (int j=0; j < data[i].size(); j++){
            int to = data[i][j];
            if (da[to] || to==0) continue;
            cout << 4 << endl;
            cout << 1 << " " << i+1 << " " << to+1 << " " << 1 << " " << n << endl;
            return 0;
        }
    }
    for (int i=0; i < n; i++){
        if (!da[i]) continue;
        if (used[i]) continue;
        ms.clear();
        dfs(i);
        int fff = -1;
        for (int j=0; j < ms.size(); j++){
            if (fff!=-1) break;
            for (int p=j+1; p < ms.size(); p++){
                int jj = ms[j], pp = ms[p];
                if (jj > pp) swap(jj, pp);
                if (reb.count(make_pair(jj, pp))) continue;
                fff = jj;
            }
        }
        if (fff == -1) continue;
        queue<int> q;
        vector<int> D(n);
        int INF = 1e9;
        fill(D.begin(), D.end(), INF);
        D[fff] = 0;
        q.push(fff);
        while (q.size()){
            int R = q.front();
            q.pop();
            for (int j=0; j < data[R].size(); j++){
                int tt = data[R][j];
                if (D[tt] != INF) continue;
                if (!da[tt]) continue;
                D[tt] = D[R] + 1;
                q.push(tt);
                if (D[tt] == 2){
                    cout << 5 << endl;
                    cout << 1 << " " << fff+1 << " " << R + 1 << " " << tt + 1 << " " << fff+1 << " " << n << endl;
                    return 0;
                }
            }
        }
    }
    cout << -1;
    return 0;
}