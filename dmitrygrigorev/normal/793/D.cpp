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
int CONST = 100000000;
int n, k, m, ai, bi, ci;
int dp[80][80][80][80], matrix[80][80];
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin >> n >> k >> m;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            matrix[i][j] = CONST;
        }
    }
    for (int i=0;i<m;i++){
        cin >> ai >> bi >> ci;
        matrix[ai-1][bi-1] = min(ci, matrix[ai-1][bi-1]);
    }
    for (int i=0;i<k;i++){
        for (int j=0;j<n;j++){
            for (int p=0;p<n;p++){
                for (int s=0;s<n;s++){
                    dp[i][j][p][s] = CONST;
                }
            }
        }
    }
    for (int j=0;j<n;j++){
        dp[0][j][0][n-1] = 0;
    }
    for (int i=0;i<k-1;i++){
        for (int j=0;j<n;j++){
            for (int p=0;p<n;p++){
                for (int s=0;s<n;s++){
                    if (dp[i][j][p][s] >= CONST) continue;
                    if (j-1 >= p){
                        for (int q=p;q<j;q++){
                            if (matrix[j][q] == CONST) continue;
                            dp[i+1][q][p][j-1] = min(dp[i+1][q][p][j-1], dp[i][j][p][s] + matrix[j][q]);
                        }
                    }
                    if (j + 1 <= s){
                        for (int q=j+1;q<=s;q++){
                            if (matrix[j][q] == CONST) continue;
                            dp[i+1][q][j+1][s] = min(dp[i+1][q][j+1][s], dp[i][j][p][s] + matrix[j][q]);
                        }
                    }
                }
            }
        }
    }
    int answer = CONST;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            for (int p=0;p<n;p++){
                answer = min(answer, dp[k-1][i][j][p]);
            }
        }
    }
    if (answer >= CONST) cout << -1 << endl;
    else cout << answer << endl;
    return 0;
}