#include <bits/stdc++.h>
#define int long long
using namespace std;
int dp[100][100][27][2];
int n, m;
vector<vector<int> > data;
vector<vector<char> > symb;
bool solve(int i, int j, int k, int l){
    if (dp[i][j][k][l] != -1) return dp[i][j][k][l];
    if (l == 0){
        for (int p=0; p < data[i].size(); p++){
            int code = (symb[i][p] - 'a') + 1;
            if (code < k) continue;
            int to = data[i][p];
            if (solve(to, j, code, 1-l) == 0){
                dp[i][j][k][l] = 0;
                return 0;
            }
        }
        dp[i][j][k][l] = 1;
        return 1;
    }
    if (l == 1){
        for (int p=0; p < data[j].size(); p++){
            int code = (symb[j][p] - 'a') + 1;
            if (code < k) continue;
            int to = data[j][p];
            if (solve(i, to, code, 1-l) == 1){
                dp[i][j][k][l] = 1;
                return 1;
            }
        }
        dp[i][j][k][l] = 0;
        return 0;
    }
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i=0; i < n; i++){
        vector<int> h;
        vector<char> r;
        data.push_back(h);
        symb.push_back(r);
    }
    for (int i=0; i < m; i++){
        int a, b;
        cin >>a >> b;
        char c;
        cin >> c;
        data[a-1].push_back(b-1);
        symb[a-1].push_back(c);
    }
    for (int i=0; i < n; i++){
        for (int j=0; j < n; j++){
            for (int k=0; k < 27; k++){
                for (int l=0; l < 2; l++){
                    dp[i][j][k][l] = -1;
                }
            }
        }
    }
    for (int i=0; i < n; i++){
        for (int j=0; j < n; j++){
            if (solve(i, j, 0, 0)) cout << "B";
            else cout << "A";
        }
        cout << endl;
    }
}