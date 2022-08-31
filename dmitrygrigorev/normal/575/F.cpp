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
int32_t main() {
    ios_base::sync_with_stdio(false);
    int n, x;
    cin >> n >> x;
    int l = x;
    int r = x;
    int ans = 0;
    for (int i=0; i < n; i++){
        int a, b;
        cin >> a >> b;
        if (a > r){
            ans += a-r;
            l = r;
            r = a;
        }
        else if (b < l){
            ans += l - b;
            r = l;
            l = b;
        }
        else{
            l = max(l, a);
            r = min(r, b);
        }
    }
    cout << ans << endl;
    return 0;
}