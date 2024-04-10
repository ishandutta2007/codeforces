#include <bits/stdc++.h>
#define int long long

using namespace std;
#define TASKNAME ""
vector<vector<int> > data;
vector<bool> good;
int kek;
void dfs(int vertex, int last){
    if (good[vertex]){
        kek = vertex;
        return;
    }
    for (int i=0; i < data[vertex].size(); i++){
        int to = data[vertex][i];
        if (to==last) continue;
        dfs(to, vertex);
    }
}
void solve(){
    int n;
    cin >> n;
    data.clear();
    data.resize(n, {});
    good.clear();
    good.resize(n, false);
    for (int i=0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        data[a-1].push_back(b-1);
        data[b-1].push_back(a-1);
    }
    int X;
    cin >> X;
    vector<int> x(X);
    for (int i=0; i < X; i++) cin >> x[i];
    for (int i=0; i < X; i++) good[x[i]-1]=true;
    int Y;
    cin >> Y;
    vector<int> y(Y);
    for (int i=0; i < Y; i++) cin >> y[i];
    cout << "B" << " " << y[0] << endl;
    int res;
    cin >> res;
    for (int i=0; i < X; i++){
        if (x[i] == res){
            cout << "C" << " " << res << endl;
            return;
        }
    }
    dfs(res-1, -1);
    cout << "A " << kek+1 << endl;
    cin >> res;
    for (int i=0; i < Y; i++){
        if (y[i] == res){
            cout << "B" << " " << y[i] << endl;
            cin >> res;
            cout << "C" << " " << res << endl;
            return;
        }
    }
    cout << "C" << " " << -1 << endl;
    return;
}
signed main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int t;
    cin >> t;
    for (int i=0; i < t; i++) solve();
}