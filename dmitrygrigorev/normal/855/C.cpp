#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <stdlib.h>
#include <cmath>
#include <math.h>
#include <fstream>
#include <bitset>
#include <time.h>
#include <queue>
#include <cassert>
#include <cstdio>
#define int long long
using namespace std;
const int MAXN = 100000;
vector<vector<int> > data;
int K = 1000000007;
int dp[MAXN][11][3];
int n, m, k, x, ai, bi;
void dfs(int vertex, int last){
    dp[vertex][0][0] = k-1;
    dp[vertex][1][1] = 1;
    dp[vertex][0][2] = m-k;
    for (int i=0; i < data[vertex].size(); i++){
        int to = data[vertex][i];
        if (to == last) continue;
        dfs(to, vertex);
        for (int j=10; j >= 0;j--){
            for (int p=1; p+j<=10;p++){
                dp[vertex][p+j][0] += (dp[to][p][0] + dp[to][p][1] + dp[to][p][2]) * dp[vertex][j][0];
                dp[vertex][p+j][0] %= K;
            }
            dp[vertex][j][0] *= (dp[to][0][0] + dp[to][0][1] + dp[to][0][2]);
            dp[vertex][j][0] %= K;
        }
        for (int j=10; j >= 0;j--){
            for (int p=1; p+j<=10;p++){
                dp[vertex][p+j][1] += (dp[to][p][0]) * dp[vertex][j][1];
                dp[vertex][p+j][1] %= K;
            }
            dp[vertex][j][1] *= (dp[to][0][0]);
            dp[vertex][j][1] %= K;
        }
        for (int j=10; j >= 0;j--){
            for (int p=1; p+j<=10;p++){
                dp[vertex][p+j][2] += (dp[to][p][0] + dp[to][p][2]) * dp[vertex][j][2];
                dp[vertex][p+j][2] %= K;
            }
            dp[vertex][j][2] *= (dp[to][0][0] + dp[to][0][2]);
            dp[vertex][j][2] %= K;
        }
    }
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=0; i < n; i++){
        vector<int> help;
        data.push_back(help);
        for (int j=0; j <= 10; j++){
            dp[i][j][0] = 0;
            dp[i][j][1] = 0;
            dp[i][j][2] = 0;
        }
    }
    for (int i=0; i < n-1; i++){
        cin >> ai >> bi;
        data[ai-1].push_back(bi-1);
        data[bi-1].push_back(ai-1);
    }
    cin >> k >> x;
    dfs(0, -1);
    int ans = 0;
    for (int i=0; i <= x; i++){
        for (int j=0; j < 3; j++){
            ans += dp[0][i][j];
        }
    }
    cout << ans % K << endl;
    return 0;
}