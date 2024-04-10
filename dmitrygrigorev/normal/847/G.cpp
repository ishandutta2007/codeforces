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
    vector<string> v(n);
    for (int i=0; i < n; i++){
        cin >> v[i];
    }
    int ans = 0;
    for (int i=0; i < 7; i++){
        int a = 0;
        for (int j=0; j < n ; j++){
            a += (v[j][i] == '1');
        }
        ans = max(ans, a);
    }
    cout << ans << endl;
    return 0;
}