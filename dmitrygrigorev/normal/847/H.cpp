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
    vector<int> v(n);
    for (int i=0; i <n; i++){
        cin >> v[i];
    }
    pair<int, int> prefix[n], suffix[n];
    prefix[0] = make_pair(0, v[0]);
    suffix[n-1] = make_pair(0, v[n-1]);
    for (int i=1; i < n; i++){
        if (v[i] > prefix[i-1].second){
            prefix[i] = make_pair(prefix[i-1].first, v[i]);
        }
        else{
            prefix[i] = make_pair(prefix[i-1].second+1 - v[i] + prefix[i-1].first, prefix[i-1].second+1);
        }
    }
    for (int i=n-2; i >= 0; i--){
        if (v[i] > suffix[i+1].second){
            suffix[i] = make_pair(suffix[i+1].first, v[i]);
        }
        else{
            suffix[i] = make_pair(suffix[i+1].second+1 - v[i] + suffix[i+1].first, suffix[i+1].second+1);
        }
    }
    int ans = 1e18;
    for (int i=0; i < n; i++){
        ans = min(ans, prefix[i].first + suffix[i].first + abs(prefix[i].second - suffix[i].second) - (max(prefix[i].second, suffix[i].second) - v[i]));
    }
    cout << ans << endl;
    return 0;
}