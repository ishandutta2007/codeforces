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
int n, l, m;
int MOD = 1000000007;
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> l >> m;
    vector<int> f(m), s(n), t(n);
    int ai;
    for (int i=0; i < n; i++){
        cin >> ai;
        f[ai%m]++;
    }
    for (int i=0; i < n; i++){
        cin >> s[i];
    }
    for (int i=0; i < n; i++){
        cin >> t[i];
    }
    int dp[20][m];
    for (int i=0; i < 20; i++){
        for (int j=0; j < m; j++){
            dp[i][j] = 0;
        }
    }
    for (int i=0; i < n; i++){
        dp[0][s[i]%m]++;
    }
    for (int i=1; i < 20; i++){
        for (int j=0; j < m; j++){
            for (int k=0; k < m; k++){
                dp[i][(j+k) % m] += (dp[i-1][j] * dp[i-1][k]);
                dp[i][(j+k) % m] %= MOD;
            }
        }
    }
    int ans[m];
    for (int i=0; i < m; i++){
        ans[i] = 0;
    }
    ans[0] = 1;
    int p = l-2;
    for (int i=0; i < 20; i++){
        int bn = p & (1 << i);
        if (bn == 0) continue;
        int ans1[m];
        for (int j=0; j < m; j++){
            ans1[j] = 0;
        }
        for (int j=0; j < m; j++){
            for (int k=0; k < m; k++){
                ans1[(j+k) % m] += (ans[j] * dp[i][k]);
                ans1[(j+k) % m] %= MOD;
            }
        }
        for (int j=0; j < m; j++){
            ans[j] = ans1[j];
        }
    }
    int answer = 0;
    for (int i=0; i < n; i++){
        for (int j=0; j < m; j++){
            int res = f[j];
            int want = (3*m - j - t[i] - s[i]) % m;
            res *= ans[want];
            answer += res;
        }
        answer %= MOD;
    }
    cout << answer << endl;
    return 0;
}