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
int main()
{
    std::ios::sync_with_stdio(false);
    int n, m, ai;
    cin >> n >> m;
    int dp[n][m];
    int stolb[n];
    for (int i=0;i<n;i++){
        stolb[i] = i;
        for (int j=0;j<m;j++){
            cin >> ai;
            dp[i][j] = ai;
        }
    }
    for (int i=0;i<m;i++){
        int j = 0;
        int k = 1;
        while (j < n){
            while (k < n){
                if (dp[k][i] >= dp[k-1][i]){
                    k ++;
                }
                else{
                    break;
                }
            }
            for (int p=j;p<k;p++){
                stolb[p] = max(stolb[p], k - 1);
            }
            j = k;
            k = j + 1;
        }
    }
    int q, l, r;
    cin >> q;
    for (int i=0;i<q;i++){
        cin >> l >> r;
        if (stolb[l-1] >= r - 1){
            cout << "Yes" << endl;
        }
        else cout << "No" << endl;
    }
    return 0;
}