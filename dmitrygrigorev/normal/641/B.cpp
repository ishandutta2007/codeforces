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
int n, m, q, t, a, b, c;
pair<int, int> dp[100][100];
int ans[100][100];
int main(){
    std::ios::sync_with_stdio(false);
    cin >> n >> m >> q;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            pair<int, int> p;
            p.first = i;
            p.second = j;
            dp[i][j] = p;
            ans[i][j] = 0;
        }
    }
    for (int i=0;i<q;i++){
        cin >> t;
        if (t == 3){
            cin >> a >> b >> c;
            pair<int, int> p = dp[a-1][b-1];
            ans[p.first][p.second] = c;
        }
        else if (t == 1){
            cin >> c;
            pair<int, int> np = dp[c-1][0];
            for (int j=0;j<m-1;j++){
                dp[c-1][j] = dp[c-1][j+1];
            }
            dp[c-1][m-1] = np;
        }
        else{
            cin >> c;
            pair<int, int> np = dp[0][c-1];
            for (int j=0;j<n-1;j++){
                dp[j][c-1] = dp[j+1][c-1];
            }
            dp[n-1][c-1] = np;
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}