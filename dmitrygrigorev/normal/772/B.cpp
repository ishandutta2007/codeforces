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
double x, y;
vector<vector<double> > data;
int main(){
    ios_base::sync_with_stdio(false);
    cin >> n;
    double ans = pow(10, 18);
    for (int i=0;i<n;i++){
        cin >> x >> y;
        vector<double> help;
        help.push_back(x);
        help.push_back(y);
        data.push_back(help);
    }
    for (int i=0;i<n;i++){
        double x0 = data[i][0];
        double y0 = data[i][1];
        double x1 = data[(i+n-1) % n][0];
        double y1 = data[(i+n-1) % n][1];
        double x2 = data[(i+1) % n][0];
        double y2 = data[(i+1) % n][1];
        double dist = abs((x2 - x1) * (y0 - y1) - (y2 - y1) * (x0 - x1));
        double dd = pow(pow(x2-x1, 2) + pow(y2 - y1, 2), 0.5);
        ans = min(ans, dist / dd);
    }
    cout.precision(30);
    cout << ans / 2 << endl;
    return 0;
}