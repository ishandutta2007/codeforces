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
#include <deque>
#define int long long
using namespace std;
int32_t main(){
    int n;
    cin >> n;
    vector<int> data(n);
    int ss = 0;
    for (int i=0; i < n; i++){
        cin >> data[i];
        ss += data[i];
    }
    int dp[n];
    dp[n-1] = data[n-1];
    for (int i=n-2; i >= 0; i--){
        int summ = 0;
        for (int j=i+1; j < n; j++){
            summ += data[j];
        }
        dp[i] = max(dp[i+1], summ - dp[i+1] + data[i]);
    }
    cout << ss-dp[0] << " " << dp[0] << endl;
    return 0;
}