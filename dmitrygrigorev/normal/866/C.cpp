#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <math.h>
#include <bitset>
#include <fstream>
#define int long long
#define D long double
using namespace std;
signed main()
{
    int n, r;
    cin >> n >> r;
    int v[n][3];
    for (int i=0; i < n; i++){
        for (int j=0; j < 3; j++){
            cin >> v[i][j];
        }
    }
    D dp[n+1][5001];
    int prefix[n+1];
    prefix[0] = 0;
    for (int i=0; i < n; i++){
        prefix[i+1] = prefix[i] + v[i][1];
    }
    D left = 0;
    D right = 1e10;
    for (int it=0; it < 100; it++){
        D mid = (left + right) / 2;
        for (int i=0; i <= n; i++){
            for (int j=0; j <= 5000; j++){
                dp[i][j] = 0;
            }
        }
        for (int j=0; j <= 5000; j++){
            if (j <= r) dp[n][j] = 0;
            else dp[n][j] = (D) mid;
        }
        for (int i=n-1; i >= 0; i--){
            for (int j=prefix[i]; j >= 0; j--){
                D var = (dp[i+1][j + v[i][0]] + (D) v[i][0]) * (D) v[i][2] / (D) 100 + (dp[i+1][j + v[i][1]] + (D) v[i][1]) * (D) (100 - v[i][2]) / (D) 100;
                var = min(var, (D) mid);
                dp[i][j] = var;
            }
        }
        if (dp[0][0] >= mid) left = mid;
        else right = mid;
    }
    cout.precision(30);
    cout << left << endl;
    return 0;
}