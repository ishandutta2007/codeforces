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
#define int long long
using namespace std;
int n;
double x1, yp, x2, y2, r1, r2, v1, v2;
double eps = 0.0000000001;
vector<vector<double> > mouse;
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin >> n;
    cin >> x1 >> yp >> x2 >> y2;
    for (int i=0;i<n;i++){
        cin >> r1 >> r2 >> v1 >> v2;
        vector<double> m;
        m.push_back(r1);
        m.push_back(r2);
        m.push_back(v1);
        m.push_back(v2);
        mouse.push_back(m);
    }
    double l = 0;
    double r = pow(10, 11);
    bool good = false;
    for (int i=0;i<300;i++){
        double mid = (l + r) / 2;
        int cc = 0;
        bool yes = true;
        for (int j=0;j<n;j++){
            double xx = mouse[j][0] + mid * mouse[j][2];
            double yy = mouse[j][1] + mid * mouse[j][3];
            if (xx >= x2 && mouse[j][2] >= 0) yes = false;
            if (xx <= x1 && mouse[j][2] <= 0) yes = false;
            if (yy >= y2 && mouse[j][3] >= 0) yes = false;
            if (yy <= yp && mouse[j][3] <= 0) yes = false;
            if (xx > x1 && xx < x2 && yy > yp && yy < y2){
                cc ++;
            }
        }
        if (cc == n) good = true;
        if (cc == n || !yes) r = mid;
        else l = mid;
    }
    cout.precision(30);
    if (good) cout << r << endl;
    else cout << -1 << endl;
    return 0;
}