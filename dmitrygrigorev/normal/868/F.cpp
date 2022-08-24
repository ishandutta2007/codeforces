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
#define int long long
using namespace std;
vector<int> dp, rights, dp_new, data;
int n, k, INF = 1e18, var, ai;
void relax_left(int l, int r, int mid, int lg, int rg, int start){
    int ng = start;
    int best = INF, where;
    while (ng >= lg){
        int cand = var + dp[ng];
        if (cand < best){
            best = cand;
            where = ng;
        }
        int el = data[ng] - 1;
        var += rights[el];
        rights[el]++;
        ng--;
    }
    while (ng != where){
        ng++;
        int el = data[ng] - 1;
        rights[el]--;
        var -= rights[el];
    }
    dp_new[mid] = best;
    int new_mid = (l + mid) / 2;
    int om = mid, ow = where;
    if (new_mid != mid && new_mid != r){
        while (mid != new_mid && mid > where){
            int el = data[mid] - 1;
            rights[el]--;
            var -= rights[el];
            mid--;
        }
        bool wh = false;
        if (where == mid){
            wh = true;
            where = new_mid - 1;
            rights[data[new_mid] - 1] = 1;
        }
        relax_left(l, om, new_mid, lg, ow, where);
        if (wh){
            rights[data[new_mid] - 1] = 0;
        }
        where = ow;
        while (mid != om){
            mid++;
            int el = data[mid] - 1;
            var += rights[el];
            rights[el]++;
        }
    }
    new_mid = (mid + 1 + r) / 2;
    if (new_mid != mid && new_mid != r){
        while (mid != new_mid){
            mid++;
            int el = data[mid] - 1;
            var += rights[el];
            rights[el]++;
        }
        while (where < min(rg, new_mid - 1)){
            where++;
            int el = data[where] - 1;
            rights[el]--;
            var -= rights[el];
        }
        relax_left(om+1, r, new_mid, ow, rg, where);
    }
    while (where > start){
        int el = data[where] - 1;
        var += rights[el];
        rights[el]++;
        where--;
    }
    while (where < start){
        where++;
        int el = data[where] - 1;
        rights[el]--;
        var -= rights[el];
    }
    while (mid > om){
        int el = data[mid] - 1;
        rights[el]--;
        var -= rights[el];
        mid--;
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i=0; i < n; i++){
        cin >> ai;
        data.push_back(ai);
        rights.push_back(0);
        dp_new.push_back(0);
    }
    int now = 0;
    for (int i=0; i < n; i++){
        int el = data[i] - 1;
        now += rights[el];
        rights[el]++;
        dp.push_back(now);
    }
    for (int i=1; i < k; i++){
        fill(dp_new.begin(), dp_new.end(), 0);
        fill(rights.begin(), rights.end(), 0);
        int l = i;
        int r = n-1;
        int mid = (l + r) / 2;
        rights[data[mid]-1]++;
        var = 0;
        relax_left(l, r+1, mid, l-1, n-1, mid-1);
        for (int j=0; j < n; j++){
            dp[j] = dp_new[j];
        }
    }
    cout << dp[n-1] << endl;
    return 0;
}