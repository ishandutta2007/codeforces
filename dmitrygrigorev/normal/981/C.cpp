#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<vector<int> > data;
int dfs(int a, int b){
    for (int i=0; i < data[a].size(); i++){
        int to = data[a][i];
        if (b==to) continue;
        return dfs(to, a);
    }
    return a;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
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
    int vrt = -1;
    for (int i=0; i < n; i++){
        if (data[i].size() < 3) continue;
        if (vrt != -1){
            cout << "No";
            return 0;
        }
        vrt = i;
    }
    if (vrt == -1) vrt = 0;
    cout << "Yes" << endl;
    cout << data[vrt].size() << endl;
    for (int i=0; i < data[vrt].size(); i++){
        int to = data[vrt][i];
        int rs = dfs(to, vrt);
        cout << vrt+1 << " " << rs+1 << endl;
    }
}