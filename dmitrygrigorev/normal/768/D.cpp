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
double dp[10000][1001];
double k;
int q, p;
double eps = 0.0000000001;
double CONST = 2000;
int main(){
    std::ios::sync_with_stdio(false);
    cin >> k >> q;
    int k1 = k;
    for (int i=1;i<10000;i++){
        dp[i][1] = 1;
    }
    for (int i=2;i<=k1;i++){
        dp[1][i] = 0;
    }
    for (int i=2;i<10000;i++){
        for (int j=2;j<=k1;j++){
            double h = k - j + 1;
            dp[i][j] = dp[i - 1][j] + (dp[i-1][j - 1] - dp[i - 1][j]) / k * h;
        }
    }
    for (int i=0;i<q;i++){
        cin >> p;
        double ver = p / CONST;
        for (int j=1;j<10000;j++){
            if (dp[j][k1] - ver >= -eps){
                cout << j << endl;
                break;
            }
        }
    }
    return 0;
}