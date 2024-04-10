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
double n, p, ai, bi;
vector<vector<double> > data;
int main(){
    ios_base::sync_with_stdio(false);
    cin >> n >> p;
    double summ = 0;
    for (int i=0;i<n;i++){
        cin >> ai >> bi;
        summ += ai;
        vector<double> help;
        help.push_back(ai);
        help.push_back(bi);
        data.push_back(help);
    }
    if (summ <= p){
        cout << -1 << endl;
        return 0;
    }
    double l = 0;
    double nole = 0;
    double r = pow(10, 18);
    for (int i=0;i<300;i++){
        double m = (l + r) / 2;
        double ss = 0;
        for (int j=0;j<n;j++){
            ss += max(nole, data[j][0] * m - data[j][1]);
        }
        if (ss > m * p) r = m;
        else l = m;
    }
    cout.precision(30);
    cout << (l + r) / 2 << endl;
    return 0;
}