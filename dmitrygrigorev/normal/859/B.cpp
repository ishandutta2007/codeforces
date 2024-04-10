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
    int ans = 1e18;
    for (int i=1; i <= n; i++){
        if (i > n) break;
        int d = n / i;
        int var = 2*d + 2*i;
        int ost = n%i;
        if (ost > 0){
            var += 2;
        }
        ans = min(ans, var);
    }
    cout << ans << endl;
    return 0;
}