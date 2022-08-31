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
int32_t main(){
    int ms = 0;
    int n, a, b, x, y, xf, yf, xs, ys;
    vector<pair<int, int> > v;
    cin >> n >> a >> b;
    for (int i=0; i < n; i++){
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }
    for (int i=0; i < n; i++){
        for (int j=i+1; j < n; j++){
            for (int k=0; k < 2; k++){
                for (int m=0; m < 2; m++){
                    if (k == 0){
                        xf = v[i].first;
                        yf = v[i].second;
                    }
                    if (k == 1){
                        yf = v[i].first;
                        xf = v[i].second;
                    }
                    if (m == 0){
                        xs = v[j].first;
                        ys = v[j].second;
                    }
                    if (m == 1){
                        ys = v[j].first;
                        xs = v[j].second;
                    }
                    if (xf + xs > a && yf + ys > b) continue;
                    if (yf > b || ys > b || xf > a || xs > a) continue;
                    ms = max(ms, xf*yf + xs*ys);
                }
            }
        }
    }
    cout << ms << endl;
    return 0;
}