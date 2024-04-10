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
#define int long long
using namespace std;
int n, t, k, d;
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin >> n >> t >> k >> d;
    int st;
    if (n % k == 0){
        st = (n / k);
    }
    else{
        st = (n / k + 1);
    }
    int tlast = (st - 1) * t;
    if (tlast > d){
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;
    return 0;
}