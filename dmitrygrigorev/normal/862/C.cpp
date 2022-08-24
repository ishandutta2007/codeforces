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
const int K = 1000000;
int32_t main(){
    int n, x;
    cin >> n >> x;
    if (n == 2 && x == 0){
        cout << "NO" << endl;
        return 0;
    }
    if (n == 1){
        cout << "YES" << endl;
        cout << x << endl;
        return 0;
    }
    int now = K;
    int xr = 0;
    vector<int> ans;
    for (int i=0; i < n-2; i++){
        xr ^= now;
        ans.push_back(now);
        now-= rand() % 5 + 1;
    }
    if (n % 2 != 0){
        xr ^= now;
        ans.push_back(now);
        int please = xr ^ x;
        ans.push_back(please);
    }
    else{
        while (true){
            int z = rand() % 8000;
            int w = xr ^ z;
            int pl = x ^ w;
            if (pl != z){
                ans.push_back(z);
                ans.push_back(pl);
                break;
            }
        }
    }
    cout << "YES" << endl;
    for (int i=0; i < n; i++){
        cout << ans[i] << " ";
    }
    return 0;
}