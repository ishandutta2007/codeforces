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
int t, x, y, p, q;
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin >> t;
    for (int i=0;i<t;i++){
        cin >> x >> y >> p >> q;
        if (p == q && x != y) {cout << -1 << endl; continue;}
        if (p == 0 && x != 0) {cout << -1 << endl; continue;}
        int l = 0;
        int r = 1100000000;
        while (r - l > 1){
            int m = (l + r) / 2;
            int nx = p * m;
            int ny = q * m;
            if (nx >= x && ny >= y && (nx - x <= ny - y)) r = m;
            else l = m;
        }
        cout << (q * r - y) << endl;
    }
    return 0;
}