/*
  !










*/
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
using namespace std;
int n;
string s;
string fs;
int CONST = 10000000;
int main()
{
    cin >> n;
    cin >> s;
    fs = "";
    int v = 0;
    int x = 0;
    int k = 0;
    for (int i=0;i<n;i++){
        if (s[i] == 'V'){v++;fs+=s[i];}
        else if (s[i] == 'K'){k++;fs+=s[i];}
        else {x++;fs+="X";}
    }
    int dp[v+1][x+1][k+1][2];
    for (int i=0;i<=v;i++){
        for (int j=0;j<=x;j++){
            for (int l=0;l<=k;l++){
                for (int m=0;m<=1;m++){
                    dp[i][j][l][m] = CONST;
                }
            }
        }
    }
    dp[0][0][0][0] = 0;
    dp[0][0][0][1] = 1;
    for (int i=0;i<=v;i++){
        for (int j=0;j<=x;j++){
            for (int l=0;l<=k;l++){
                if (i>0){
                    int xx = 0;
                    int kk = 0;
                    int vv = 0;
                    for (int m=0;m<n;m++){
                        if (fs[m] == 'X') xx++;
                        if (fs[m] == 'K') kk++;
                        if (fs[m] == 'V') vv++;
                        if (vv >= i) break;
                    }
                    int pl = max(0, xx-j) + max(0, kk - l);
                    dp[i][j][l][1] = min(dp[i][j][l][1], dp[i-1][j][l][1] + pl);
                    dp[i][j][l][1] = min(dp[i][j][l][1], dp[i-1][j][l][0] + pl);
                }
                if (j>0){
                    int xx = 0;
                    int kk = 0;
                    int vv = 0;
                    for (int m=0;m<n;m++){
                        if (fs[m] == 'X') xx++;
                        if (fs[m] == 'K') kk++;
                        if (fs[m] == 'V') vv++;
                        if (xx >= j) break;
                    }
                    int pl = max(0, vv-i) + max(0, kk - l);
                    dp[i][j][l][0] = min(dp[i][j][l][0], dp[i][j-1][l][0] + pl);
                    dp[i][j][l][0] = min(dp[i][j][l][0], dp[i][j-1][l][1] + pl);
                }
                if (l>0){
                    int xx = 0;
                    int kk = 0;
                    int vv = 0;
                    for (int m=0;m<n;m++){
                        if (fs[m] == 'X') xx++;
                        if (fs[m] == 'K') kk++;
                        if (fs[m] == 'V') vv++;
                        if (kk >= l) break;
                    }
                    int pl = max(0, xx-j) + max(0, vv - i);
                    dp[i][j][l][0] = min(dp[i][j][l][0], dp[i][j][l-1][0] + pl);
                }
            }
        }
    }
    int ans = CONST;
    for (int i=0;i<=v;i++){
        for (int j=0;j<=x;j++){
            for (int l=0;l<=k;l++){
                if (i+j+l == n) {ans = min(ans, dp[i][j][l][0]);ans = min(ans, dp[i][j][l][1]);}
            }
        }
    }
    cout << ans << endl;
    return 0;
}