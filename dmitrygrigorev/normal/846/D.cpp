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
#include <deque>
#define int long long
using namespace std;
int n, m, k, q, ai, bi, ci;
int matrix[500][500], dp[500][500];
vector<vector<int> > lom;
int INF = 1e10;
bool checker(int number){
    for (int i=0; i < n; i++){
        for (int j=0; j < m; j++){
            matrix[i][j] = 0;
            dp[i][j] = 0;
        }
    }
    for (int i=0; i < q; i++){
        if (lom[i][2] <= number){
            matrix[lom[i][0]-1][lom[i][1]-1] = 1;
        }
    }
    int maximum = 0;
    for (int i=0; i < n; i++){
        for (int j=0; j < m; j++){
            if (matrix[i][j] == 0) continue;
            if (i == 0 || j == 0) dp[i][j] = 1;
            else{
                dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
            }
        }
    }
    for (int i=0; i < n; i++){
        for (int j=0; j < m; j++){
            maximum = max(maximum, dp[i][j]);
        }
    }
    return (k <= maximum);
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k >> q;
    for (int i=0; i < n; i++){
        for (int j=0; j < m; j++){
            matrix[i][j] = 0;
        }
    }
    int left = -1;
    int right = INF;
    for (int i=0; i < q; i++){
        cin >> ai >> bi >> ci;
        vector<int> help;
        help.push_back(ai);
        help.push_back(bi);
        help.push_back(ci);
        lom.push_back(help);
    }
    while (right - left > 1){
        int mid = (left + right) / 2;
        bool res = checker(mid);
        if (res) right = mid;
        else left = mid;
    }
    if (right == INF){
        cout << -1 << endl;
    }
    else cout << right << endl;
    return 0;
}