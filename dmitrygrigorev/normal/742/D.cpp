#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <math.h>
#include <fstream>
using namespace std;
int n, m, w, ai, f, s;
vector<int> weights;
vector<int> moneys;
vector<vector< int> > data;
vector<bool> used;
vector<int> go;
vector<int> comp;
vector<vector<vector< int > > > dp;
int c;
void dfs(int vertex){
    go.push_back(vertex);
    used[vertex] = true;
    comp[vertex] = c;
    for (int i=0;i<data[vertex].size();i++){
            int to = data[vertex][i];
        if (!used[to]){
            dfs(to);
        }
    }
}
int main(){
    std::ios::sync_with_stdio(false);
    cin >> n >> m  >> w;
     c = 0;
    for (int i=0;i<n;i++){
        cin >> ai;
        weights.push_back(ai);
        vector<int> help;
        data.push_back(help);
    }
    for (int i=0;i<n;i++){
        cin >> ai;
        comp.push_back(0);
        used.push_back(false);
        moneys.push_back(ai);
    }
    for (int i=0;i<m;i++){
        cin >> f >> s;
        data[f-1].push_back(s-1);
        data[s-1].push_back(f-1);
    }
    for (int i=0;i<n;i++){
        if (!used[i]){
            dfs(i);
            c++;
        }
    }
    for (int i=0;i<n+1;i++){
        vector<vector<int> > h;
        for (int j=0;j<w+1;j++){
            vector<int> h1;
            h1.push_back(0);
            h1.push_back(0);
            h1.push_back(0);
            h1.push_back(0);
            h.push_back(h1);
        }
        dp.push_back(h);
    }
    for (int i=1;i<n+1;i++){
        int p = go[i-1];
        for (int j=1;j<w+1;j++){
            if (i==1){
                    if (j - weights[p] >= 0){
                dp[i][j][0] = moneys[p];
                dp[i][j][1] = moneys[p];
                    }
            }
            else{
                if (comp[p] != comp[go[i-2]]){
                    int to2 = max(dp[i-1][j][0], dp[i-1][j][1]);
                    int ts2 = max(to2, dp[i-1][j][3]);
                    if (j - weights[p] >= 0){
                    int to =  max(dp[i-1][j - weights[p]][0], dp[i-1][j - weights[p]][1]);
                    int ts = max(to, dp[i-1][j-weights[p]][3]);
                    int to1 = max(dp[i-1][j - weights[p]][0], dp[i-1][j - weights[p]][1]);
                    int ts1 = max(to1, dp[i-1][j-weights[p]][3]);
                    dp[i][j][0] = max(ts, dp[i-1][j - weights[p]][2]) + moneys[p];
                    dp[i][j][1] = max(ts1, dp[i-1][j - weights[p]][2]) + moneys[p];
                    }
                    dp[i][j][2] = max(ts2, dp[i-1][j][2]);
                    dp[i][j][3] = max(ts2, dp[i-1][j][2]);
                }
            else{
                if (j - weights[p] >= 0){
                    if (dp[i-1][j - weights[p]][0] != 0){
                dp[i][j][0] = dp[i-1][j - weights[p]][0] + moneys[p];
                    }
                dp[i][j][1] = dp[i-1][j - weights[p]][2] + moneys[p];
                }
                dp[i][j][2] = dp[i-1][j][2];
                dp[i][j][3] = max(dp[i-1][j][1], dp[i-1][j][3]);
            }
            }
        }
    }
    int answer = 0;
    for (int weight=1;weight<=w;weight++){
    int to3 = max(dp[n][weight][0], dp[n][weight][1]);
    int to4 = max(to3, dp[n][weight][2]);
    int to5 = max(to4, dp[n][weight][3]);
    answer = max(answer, to5);
    }
    cout << answer << endl;
    return 0;

}