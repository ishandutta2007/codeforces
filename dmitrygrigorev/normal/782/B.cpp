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
using namespace std;
int n;
double ai;
vector<double> coords;
vector<double> v;
double result(double coord){
    double tt = 0;
    for (int i=0;i<n;i++){
        double t1 = abs(coords[i] - coord) / v[i];
        tt = max(tt, t1);
    }
    return tt;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> ai; coords.push_back(ai);
    }
    for (int i=0;i<n;i++){
        cin >> ai; v.push_back(ai);
    }
    double l = -1000000000;
    double r = 1000000000;
    double T = 3;
    for (int i=0;i<200;i++){
        double d = (r - l) / T;
        double m1 = l + d;
        double m2 = r - d;
        double res1 = result(m1);
        double res2 = result(m2);
        if (res1 > res2){
            l = m1;
        }
        else r = m2;
    }
    double TW = 2;
    cout.precision(50);
    cout << result((l + r) / TW) << endl;
    return 0;
}