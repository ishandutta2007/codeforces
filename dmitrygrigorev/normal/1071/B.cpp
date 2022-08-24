#include <bits/stdc++.h>
using namespace std;
char matrix[2000][2000];
int dp[2000][2000];
bool used[2000][2000];
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("1.txt", "r", stdin);
    int n, k;
    cin >> n >> k;
    for (int i=0;i<n;i++) for (int j=0; j < n;j++) cin >> matrix[i][j];
    for (int i=0; i < n; i++) for (int j=0; j < n; j++) dp[i][j] = 1e9;
    dp[0][0] = (matrix[0][0] != 'a');
    for (int i=0; i < n; i++){
        for (int j=0; j < n; j++){
            if (i==0 && j==0) continue;
            if (i > 0) dp[i][j] = min(dp[i][j], dp[i-1][j] + (matrix[i][j] != 'a'));
            if (j > 0) dp[i][j] = min(dp[i][j], dp[i][j-1] + (matrix[i][j] != 'a'));
        }
    }
    int dist = -1e9;
    vector<pair<int, int> > cells;
    for (int i=0; i < n; i++) for (int j=0; j < n; j++){
        if (dp[i][j] > k) continue;
        int mv = i+j;
        if (mv > dist){
            cells = {{i, j}};
            dist = mv;
        }
        else if (mv==dist) cells.push_back({i, j});
    }
    if (!cells.size()) cells.push_back({-1, 0});
    dist = max(dist, -1);
    string ans = "";
    for (int i=0; i <= dist; i++) ans += 'a';
    while (dist != 2*n-2){
        vector<pair<int, int> > clls;
        char symb = (char) ('z' + 1);
        for (int i=0; i < cells.size(); i++){
            int X = cells[i].first, Y = cells[i].second;
            if (X < n-1 && Y >= 0){
                if (!used[X+1][Y]){
                    used[X+1][Y] = true;
                    char tr = matrix[X+1][Y];
                    if (tr < symb){
                        symb = tr;
                        clls = {{X+1,Y}};
                    }
                    else if (tr==symb) clls.push_back({X+1, Y});
                }
            }
            if (Y < n-1 && X >= 0){
                if (!used[X][Y+1]){
                    used[X][Y+1] = true;
                    char tr = matrix[X][Y+1];
                    if (tr < symb){
                        symb = tr;
                        clls = {{X,Y+1}};
                    }
                    else if (tr==symb) clls.push_back({X, Y+1});
                }
            }
        }
        cells = clls;
        dist++;
        ans += symb;
    }
    cout << ans;
    return 0;
}