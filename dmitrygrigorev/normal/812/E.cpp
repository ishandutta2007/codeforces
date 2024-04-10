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
using namespace std;
int n, ai, xr;
vector<vector<int> > data;
vector<int> apples, zero, one;
int dfs(int vertex){
    int ret = 0;
    for (int i=0;i<data[vertex].size();i++){
        int to = data[vertex][i];
        ret = dfs(to) + 1;
    }
    if (ret % 2 == 0) {zero[apples[vertex]-1] ++; xr^=apples[vertex];}
    else one[apples[vertex]-1] ++;
    return ret;
}
int32_t main(){
    cin >> n;
    for (int i=0;i<n;i++){
        vector<int> help;
        data.push_back(help);
        cin >> ai;
        apples.push_back(ai);
    }
    for (int i=0;i<10000000;i++){
        zero.push_back(0);
        one.push_back(0);
    }
    for (int i=1;i<n;i++){
        cin >> ai;
        data[ai-1].push_back(i);
    }
    xr = 0;
    dfs(0);
    if (xr == 0){
        long long ans = 0;
        long long z = 0;
        long long o = 0;
        for (int i=0;i<10000000;i++){
            long long f1 = zero[i];
            long long f2 = one[i];
            ans += f1*f2;
            z += f1;
            o += f2;
        }
        ans += z * (z-1) / 2;
        ans += o * (o-1) / 2;
        cout << ans << endl;
    }
    else{
        long long ans = 0;
        for (int i=0;i<10000000;i++){
            int nx = xr ^ (i+1);
            if (nx > 0 && nx <= 10000000) {
                long long f1 = one[nx-1];
                long long f2 = zero[i];
                ans += f1*f2;
            }
        }
        cout << ans << endl;
    }
    return 0;
}