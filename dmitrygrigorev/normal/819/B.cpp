#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <sstream>
#include <string>
#include <unordered_map>
#include <set>
#include <stdlib.h>
#include <cmath>
#include <math.h>
#include <fstream>
#include <bitset>
#include <time.h>
#define int long long
using namespace std;
int n, ai;
vector<int> data;
unordered_map<int, int> sh;
signed main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> ai;
        data.push_back(ai);
    }
    int o = 0;
    int p = 0;
    int res = 0, num = 0;
    for (int i=0;i<n;i++){
        int counter = data[i] - (i+1);
        res += abs(counter);
        if (counter > 0){
            sh[counter] ++;
            o ++;
        }
        else p++;
    }
    int ans = res;
    for (int go=0;go<n-1;go++){
        res += p-1; res -= o;
        int sdv = n - 1 - go;
        int zn = data[sdv] - (sdv+1) - (go + 1) + n;
        sh[go+zn+1] ++;
        p--; o++;
        o -= sh[go+1];
        p += sh[go+1];
        int old = abs(data[sdv] - n);
        int nv = abs(1 - data[sdv]);
        res += nv - old;
        if (res < ans){
            ans = res;
            num = go+1;
        }
    }
    cout << ans << " " << num << endl;
    return 0;
}