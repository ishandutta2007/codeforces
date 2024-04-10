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
using namespace std;
int32_t main(){
    int n, m, INF = 1e6;
    cin >> n >> m;
    vector<int> zn(n);
    for (int i=0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        zn[b] += (1 << a);
        zn[a] += (1 << b);
    }
    int dp[1 << n];
    vector<pair<int, int> > wh(1 << n);
    for (int i=0; i < (1 << n); i++){
        dp[i] = INF;
    }
    for (int i=1; i < (1 << n); i++){
        bool can = true;
        for (int j=0; j < n; j++){
            int ba = ((1 << j) & i);
            if (ba == 0) continue;
            int K = (i ^ (1 << j));
            if ((K & zn[j]) != K){
                can = false;
            }
        }
        if (can){
            dp[i] = 0;
        }
    }
    for (int i=1; i < (1 << n); i++){
        for (int j=0; j < n; j++){
            int ba = ((1 << j) & i);
            if (ba == 0) continue;
            int nm = i | zn[j];
            if (dp[nm] > dp[i] + 1){
                dp[nm] = dp[i] + 1;
                wh[nm] = make_pair(i, j);
            }
        }
    }
    cout << dp[((1 << n) - 1)] << endl;
    int now = ((1 << n) - 1);
    vector<int> ans;
    while (dp[now] != 0){
        ans.push_back(wh[now].second + 1);
        now = wh[now].first;
    }
    reverse(ans.begin(), ans.end());
    for (int i=0; i < ans.size(); i++) cout << ans[i] << " ";
    return 0;
}