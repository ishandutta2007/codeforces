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
int n, ai, bi;
long long xi;
vector<long long> data;
vector<vector<int> > graf;
vector<long long > st;
long long  dp[100000][2][25];
long long ans;
void dfs(int v, int last){
    int counter = 0;
    for (int i=0;i<graf[v].size();i++){
        int to = graf[v][i];
        if (to == last) continue;
        dfs(to, v);
        counter ++;
    }
    if (counter == 0){
        for (int i=0;i<25;i++){
            long long  hh = st[i] & data[v];
            if (hh != 0){
                dp[v][1][i] = 1;
                ans += st[i];
            }
            else{
                dp[v][0][i] = 1;
            }
        }
        return;
    }
    for (int i=0;i<25;i++){
        long long  hh = st[i] & data[v];
        if (hh != 0){
            dp[v][1][i] = 1;
        }
        else{
            dp[v][0][i] = 1;
        }
    }
    long long zeroes[25], ones[25], zz[25], zo[25], oo[25];
    for (int i=0;i<25;i++){
        zeroes[i] = 0;
        ones[i] = 0;
        zz[i] = 0;
        zo[i] = 0;
        oo[i] = 0;
    }
    for (int i=0;i<graf[v].size();i++){
        int to = graf[v][i];
        if (to == last) continue;
        for (int j=0;j<25;j++){
        long long hh = st[j] & data[v];
        if (hh != 0){
            dp[v][1][j] += dp[to][0][j];
            dp[v][0][j] += dp[to][1][j];
        }
        else{
            dp[v][1][j] += dp[to][1][j];
            dp[v][0][j] += dp[to][0][j];
        }
        zeroes[j] += dp[to][0][j];
        ones[j] += dp[to][1][j];
        oo[j] += dp[to][1][j] * (dp[to][1][j] - 1) / 2;
        zz[j] += dp[to][0][j] * (dp[to][0][j] - 1) / 2;
        zo[j] += dp[to][1][j] * (dp[to][0][j]);
        }
    }
    for (int i=0;i<25;i++){
        ans += dp[v][1][i] * st[i];
        long long  hh = st[i] & data[v];
        if (hh != 0){
            long long  aa = zeroes[i] * (zeroes[i] - 1) / 2 - zz[i];
            aa += ones[i] * (ones[i] - 1) / 2 - oo[i];
            ans += aa * st[i];
        }
        else{
            ans += (zeroes[i] * ones[i] - zo[i]) * st[i];
        }
    }
}
int main(){
    std::ios::sync_with_stdio(false);
    cin >> n;
    for (int i=0;i<n;i++){
        for (int k=0;k<2;k++){
        for (int j=0;j<25;j++){
            dp[i][k][j] = 0;
        }
    }
        cin >> xi;
        vector<int> h;
        graf.push_back(h);
        data.push_back(xi);
    }
    long long counter = 1;
    for (int i=0;i<25;i++){
        st.push_back(counter); counter *= 2;
    }
    for (int i=0;i<n-1;i++){
        cin >> ai >> bi;
        graf[ai - 1].push_back(bi - 1);
        graf[bi - 1].push_back(ai - 1);
    }
    dfs(0, -1);
    cout << ans << endl;
    return 0;
}