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
const int K = 2000020;
const int MOD = 1000001;
int counts[K], summ[K], numbers[K];
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x, y, ai;
    cin >> n >> x >> y;
    for (int i=0; i < K; i++){
        counts[i] = 0;
    }
    for (int i=0; i < n; i++){
        cin >> ai;
        counts[ai]++;
    }
    summ[0] = 0;
    numbers[0] = 0;
    for (int i=1; i < K; i++){
        numbers[i] = numbers[i-1] + counts[i];
        summ[i] = summ[i-1] + i * counts[i];
    }
    int vyb = x / y;
    int ans = 1e18;
    for (int g=2; g < MOD; g++){
        int var = 0;
        for (int j=1; j < MOD; j+=g){
            int lg = max(j+g-1-vyb, j);
            int udal = numbers[lg-1] - numbers[j-1];
            var += udal * x;
            if (lg >= j + g-1) continue;
            int nc = numbers[j+g-2] - numbers[lg - 1];
            int ss = summ[j+g-2] - summ[lg - 1];
            int ws = nc * (j + g-1);
            var += (ws - ss) * y;
        }
        ans = min(ans, var);
    }
    cout << ans << endl;
    return 0;
}