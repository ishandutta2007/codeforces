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
    vector<int> d(n);
    for (int i=0; i < n; i++){
        cin >> d[i];
    }
    sort(d.begin(), d.end());
    int ans = max((int) 0, d.back() - 25);
    cout << ans << endl;
    return 0;
}