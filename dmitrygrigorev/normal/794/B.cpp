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
int n, h;
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin >> n >> h;
    double last = 0;
    cout.precision(30);
    double hh = h;
    double nn = n;
    double two = 2;
    vector<double> answers;
    for (int i=0;i<nn-1;i++){
        double ii = i;
        double left = last;
        double right = hh;
        double um = nn - ii - 1;
        double losn = (hh - last) / hh;
        for (int j=0;j<300;j++){
            double mid = (left + right) / two;
            double osn = (hh - mid) / hh;
            double triangle = (hh - mid) * osn / two;
            double trap = um * (losn + osn) / two * (mid - last);
            if (triangle > trap){
                left = mid;
            }
            else right = mid;
        }
        double mm = (left + right) / 2;
        last = mm;
        answers.push_back(hh - mm);
    }
    for (int i=n-2;i>=0;i--){
        cout << answers[i] << " ";
    }
    return 0;
}