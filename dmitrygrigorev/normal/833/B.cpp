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
using namespace std;
int n, k, ai;
vector<int> data, rmq, pushs;
void push(int i, int l, int r){
    if (l + 1 >= r || pushs[i] == 0) return;
    rmq[2*i+1] += pushs[i];
    rmq[2*i+2] += pushs[i];
    pushs[2*i+1] += pushs[i];
    pushs[2*i+2] += pushs[i];
    pushs[i] = 0;
}
void change(int i, int l, int r, int l1, int r1, int val){
    push(i, l, r);
    if (l1 >= r1) return;
    if (l == l1 && r == r1){
        rmq[i] += val;
        pushs[i] += val;
        return;
    }
    int mid = (l + r) / 2;
    change(2*i+1, l, mid, l1, min(r1, mid), val);
    change(2*i+2, mid, r, max(l1, mid), r1, val);
    rmq[i] = max(rmq[2*i+1], rmq[2*i+2]);
}
int get(int i, int l, int r, int l1, int r1){
    push(i, l, r);
    if (l1 >= r1) return -1;
    if (l == l1 && r == r1){
        return rmq[i];
    }
    int mid = (l + r) / 2;
    int g1 = get(2*i+1, l, mid, l1, min(r1, mid));
    int g2 = get(2*i+2, mid, r, max(l1, mid), r1);
    return max(g1, g2);
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i=0; i < n; i++){
        cin >> ai;
        data.push_back(ai);
    }
    int dp[k+1][n+1];
    for (int i=0; i <= k; i++){
        for (int j=0; j <= n; j++){
            dp[i][j] = 0;
        }
    }
    for (int i=0; i < 4*n+4;i++){
        rmq.push_back(0);
        pushs.push_back(0);
    }
    vector<int> lasts;
    for (int i=0; i < n; i++){
        lasts.push_back(-1);
    }
    for (int i=1; i <= k; i++){
        fill(lasts.begin(), lasts.end(), 0);
        for (int j=0; j < 4*n+4;j++){
            rmq[j] = 0;
            pushs[j] = 0;
        }
        for (int j=0; j <= n; j++){
            change(0, 0, n+1, j, j+1, dp[i-1][j]);
        }
        for (int j=i;j<=n;j++){
            int last_el = data[j-1] - 1;
            change(0, 0, n+1, lasts[last_el], j, 1);
            dp[i][j] = get(0, 0, n+1, 0, j);
            lasts[last_el] = j;
        }
    }
    cout << dp[k][n] << endl;
    return 0;
}