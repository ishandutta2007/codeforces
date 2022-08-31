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
int n, m, v, u, t;
const int N = 505;
bitset<N> dp[61][2][N];
int main(){
    std::ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=0;i<m;i++){
        cin >> v >> u >> t;
        dp[0][t][v-1][u-1] = 1;
    }
    for (int i=1;i<61;i++){
        for (int j=0;j<2;j++){
            for (int k=0;k<n;k++){
                for (int p=0;p<n;p++){
                    if (dp[i-1][j][k][p]){
                        dp[i][j][k] |= dp[i-1][j^1][p];
                    }
                }
            }
        }
    }
    for (int i=0;i<n;i++){
        if (dp[60][0][0][i]){cout << -1 << endl;return 0;}
    }
    int now = 0;
    vector<long long> st;
    long long answer = 0;
    long long counter = 1;
    for (int i=0;i<61;i++){
        st.push_back(counter); counter *= 2;
    }
    bitset<N> bs;
    bs[0] = 1;
    for (int i=59;i>=0;i--){
        bitset<N> ss;
        bool ch = false;
        for (int j=0;j<n;j++){
            if (bs[j] == 0) continue;
            for (int k=0;k<n;k++){
                if (dp[i][now][j][k]){ch = true; ss[k] = 1;}
            }
        }
        if (ch){
            answer += st[i];
            bs = ss;
            now ^= 1;
        }
    }
    if (answer > 1000000000000000000) {cout << -1 << endl; return 0;}
    cout << answer << endl;
    return 0;
}