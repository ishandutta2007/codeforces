#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, m; cin >> n >> m;
    vector<array<int, 3>> points;
    for(int i = 0; i<n; i++)
        for(int j = 0; j<n;j++){
            int a; cin >> a; --a;
            points.push_back({i, j, a});
        }
    string s; cin >> s;
    int trans[3][2] = {{0, 0}, {1, 0}, {2, 0}};
    for(char c : s){
        if(c == 'R') trans[1][1]++;
        else if(c == 'L') trans[1][1]--;
        else if(c == 'D') trans[0][1]++;
        else if(c == 'U') trans[0][1]--;
        else if(c == 'I') swap(trans[1], trans[2]);
        else swap(trans[0], trans[2]);
    }
    vector<vector<int>> ans(n, vector<int>(n));
    for(auto p : points)
        ans[((p[trans[0][0]]+trans[0][1])%n+n)%n][((p[trans[1][0]]+trans[1][1])%n+n)%n] = ((p[trans[2][0]]+trans[2][1])%n+n)%n;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++)
            cout << ans[i][j]+1 << " ";
        cout << endl;
    }
    cout << endl;
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}