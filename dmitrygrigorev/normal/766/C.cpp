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
using namespace std;
int n, ai;
string s;
string id = "abcdefghijklmnopqrstuvwxyz";
vector<int> idd;
int main(){
    std::ios::sync_with_stdio(false);
    cin >> n;
    cin >> s;
    for (int i=0;i<26;i++){
        cin >> ai;
        idd.push_back(ai);
    }
    int dp[n+1][n+1];
    int ogr[n+1][n+1];
    for (int i=0;i<=n;i++){
        for (int j=0;j<=n;j++){
            dp[i][j] = 0;
            ogr[i][j] = 100000000;
        }
    }
    dp[0][0] = 1;
    int dd[n + 1];
    int mx[n+1];
    dd[0] = 0;
    mx[0] = 0;
    for (int i=1;i<=n;i++){
        dd[i] = 100000000;
        mx[i] = 0;
    }
    int CONST = 1000000007;
    for (int i=1;i<=n;i++){
        for (int j=0;j<i;j++){
            int nn;
            for (int k=0;k<26;k++){
                if (s[i-1] == id[k]) {nn = k;break;}
            }
            if (idd[nn] >= abs(i - j) && abs(i-j) <= ogr[i-1][j]){
                if (dp[i-1][j]){
                mx[i] = max(mx[i], mx[j]);
                mx[i] = max(mx[i], abs(i-j));
                dd[i] = min(dd[i], dd[j] + 1);
                }
                dp[i][j] += dp[i-1][j];
                dp[i][j] %= CONST;
                int mm = min(ogr[i-1][j], idd[nn]);
                ogr[i][j] = min(ogr[i][j], mm);
                dp[i][i] += dp[i-1][j];
                dp[i][i] %= CONST;
            }
        }
    }
    long long ans = 0;
    for (int i=0;i<n;i++){
        ans += dp[n][i];
        ans %= CONST;
    }
    cout << ans << endl;
    cout << mx[n] << endl;
    cout << dd[n] << endl;
    return 0;
}