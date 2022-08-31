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
int INF = -7e18;
signed main()
{
    ios_base::sync_with_stdio(false);
    int n, p, q, r;
    cin >> n >> p >> q >> r;
    int data[n], dp[n][3];
    for (int i=0;i<n;i++){
        cin >> data[i];
        dp[i][0] = INF;
        dp[i][1] = INF;
        dp[i][2] = INF;
    }
    for (int i=0; i < n; i++){
        dp[i][0] = max(dp[i][0], p*data[i]);
        if (i > 0) dp[i][0] = max(dp[i][0], dp[i-1][0]);
        dp[i][1] = max(dp[i][1], dp[i][0] + q*data[i]);
        if (i > 0) dp[i][1] = max(dp[i][1], dp[i-1][1]);
        dp[i][2] = max(dp[i][2], dp[i][1] + r*data[i]);
        if (i > 0) dp[i][2] = max(dp[i][2], dp[i-1][2]);
    }
    cout << dp[n-1][2] << endl;
    return 0;
}