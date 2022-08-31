#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <bits/stdc++.h>
#include <math.h>
#include <fstream>
using namespace std;
int dp[75][(1<<20) + 1];
int ans;
int s1, s2;
int now, ch;
int cc = 1000000007;
int number = (1<<20);
int tlog(int j){
    if (j == 0){
        return 0;
    }
    s1 = 1;
    s2 = 1;
    while (2 * s2 <= j){
        s1 ++;
        s2 = s2 * 2;
    }
    return s1;
}
int main(){
    std::ios::sync_with_stdio(false);
    int n;
    string str;
    cin >> n;
    cin >> str;
    ans = 0;
    for (int i=0;i<n;i++){
        for (int j=1;j<=number;j++){
            dp[i][j] = 0;
        }
        dp[i][0] = 1;
    }
    for (int i=0;i<n;i++){
        int j = 0;
        now = 0;
        for (int k=i;k<n;k++){
            if (str[k] == '0'){
                now = now * 2;
            }
            else{
                now = now * 2 + 1;
            }
            if (now > 20){
                break;
            }
            if (now > 0){
                ch = pow(2, now-1);
                dp[k][ch] += 1;
            }
        }
        for (int j=1;j<=number;j++){
            if (dp[i][j] != 0){
                now = 0;
                for (int k=i+1;k<n;k++){
                    if (str[k] == '0'){
                        now = now * 2;
                    }
                    else{
                        now = now * 2 + 1;
                    }
                    if (now > 20){
                        break;
                    }
                    if (now > 0){
                        ch = pow(2, now-1);
                        if ((j & ch) != 0){
                            dp[k][j] += dp[i][j] % cc;
                            dp[k][j] = dp[k][j] % cc;
                        }
                        else{
                            ch = j + pow(2, now-1);
                            dp[k][ch] += dp[i][j] % cc;
                            dp[k][ch] = dp[k][ch] % cc;
                        }
                    }
                }
            }
        }
    }
    for (int i = 0;i<n;i++){
        int counter = 1;
        while (counter <= number){
            ans += dp[i][counter];
            ans = ans % cc;
            counter = counter * 2 + 1;
        }
    }
    cout << ans << endl;
    return 0;
}