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
#define D long double
using namespace std;
int32_t main(){
    int n;
    cin >> n;
    int ans = 1e18;
    vector<int> v(2*n);
    for (int i=0; i < 2*n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for (int one=0; one < 2*n; one++){
        for (int t=one+1; t < 2*n; t++){
            int var = 0;
            int ind = -1;
            for (int k=0; k < 2*n; k++){
                if (k == one || k == t) continue;
                if (ind == -1) ind = k;
                else{
                    var += v[k] - v[ind];
                    ind = -1;
                }
            }
            ans = min(ans, var);
        }
    }
    cout << ans << endl;
    return 0;
}