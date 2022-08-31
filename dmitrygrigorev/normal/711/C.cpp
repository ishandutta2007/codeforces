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
int n, m, k, ti;
long long ai;
vector<vector<long long> > data;
vector<vector<vector<long long> > > dp;
vector<int> trees;
int main(){
    long long inf = 1000000000000;
    cin >> n >> m >> k;
    for (int i=0;i<n;i++){
        cin >> ti;
        trees.push_back(ti);
    }
    for (int i=0;i<n;i++){
        vector<long long> help;
        for (int j=0;j<m;j++){
            cin >> ai;
            help.push_back(ai);
        }
        data.push_back(help);
    }
    vector<vector<long long> > d;
    for (int i=0;i<m;i++){
        vector<long long> help;
        for (int j=0;j<k+1;j++){
            help.push_back(0);
        }
        d.push_back(help);
    }
    dp.push_back(d);
    for (int i=0;i<n;i++){
        vector<vector<long long> > dp1;
        for (int j=0;j<m;j++){
            vector<long long> dp2;
            for (int p=0;p<=k;p++){
                dp2.push_back(inf);
            }
            dp1.push_back(dp2);
        }
        dp.push_back(dp1);
    }
    for (int i=1;i<=n;i++){
        for (int j=0;j<m;j++){
            for (int p=1;p<=min(i, k);p++){
                if (trees[i-1] != j + 1 & trees[i-1] != 0){
                    continue;
                }
                long long cost = 0;
                if (trees[i-1] == 0){
                    cost = data[i-1][j];
                }
                if (dp[i-1][j][p] != inf){
                    dp[i][j][p] = min(dp[i][j][p], dp[i-1][j][p] + cost);
                }
                for (int r=0;r<m;r++){
                    if (r != j & dp[i-1][r][p-1] != inf){
                        dp[i][j][p] = min(dp[i][j][p], dp[i-1][r][p-1] + cost);
                    }
                }
            }
        }
    }
    long long minimum = inf;
    for (int i=0;i<m;i++){
        if (dp[n][i][k] < minimum){
            minimum = dp[n][i][k];
        }
    }
    if (minimum == inf){
        cout << -1 << endl;
    }
    else{
        cout << minimum << endl;
    }
    return 0;
}