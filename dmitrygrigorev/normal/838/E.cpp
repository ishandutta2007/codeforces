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
#define int long long
#define double long double
using namespace std;
vector<pair<double, double> > v;
double dist(int a, int b){
    double f = (v[a].first - v[b].first) * (v[a].first - v[b].first);
    double s = (v[a].second - v[b].second) * (v[a].second - v[b].second);
    return sqrt(f + s);
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    double x, y;
    for (int i=0; i < n; i++){
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }
    double dp[n][n][2];
    for (int i=0; i < n; i++){
        for (int j=0; j < n; j++){
            for (int k=0; k < 2; k++){
                dp[i][j][k] = 0;
            }
        }
    }
    for (int d=1; d < n; d++){
        for (int i=0; i < n; i++){
            int j = (i + d) % n;
            int p1 = (i + d - 1) % n;
            dp[i][j][1] = max(dp[i][j][1], dp[i][p1][0] + dist(i, j));
            dp[i][j][1] = max(dp[i][j][1], dp[i][p1][1] + dist(p1, j));
            int p2 = (i + 1) % n;
            dp[i][j][0] = max(dp[i][j][0], dp[p2][j][0] + dist(i, p2));
            dp[i][j][0] = max(dp[i][j][0], dp[p2][j][1] + dist(i, j));
        }
    }
    double ans = 0;
    for (int i=0; i < n; i++){
        ans = max(ans, dp[i][(i + n - 1) % n][0]);
        ans = max(ans, dp[i][(i + n - 1) % n][1]);
    }
    cout.precision(50);
    cout << ans << endl;
    return 0;
}