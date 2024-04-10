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
int n, c, d, ai, bi;
char ch;
vector<vector<int> > cs, ds;
vector<int> maxc, maxd, m2c, m2d;
int bs(int money, vector<vector<int> > &vect, int ind){
    int left = -1;
    int right = vect.size();
    while (right - left > 1){
        int mid = (left + right) / 2;
        if (vect[mid][0] > money) right = mid;
        else left = mid;
    }
    if (left == ind) return left - 1;
    return left;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin >> n >> c >> d;
    for (int i=0;i<n;i++){
        cin >> ai >> bi >> ch;
        vector<int> help;
        help.push_back(bi);
        help.push_back(ai);
        if (ch == 'C'){
            cs.push_back(help);
        }
        else ds.push_back(help);
    }
    int maximum = -1;
    int max2 = -1;
    sort(cs.begin(), cs.end());
    sort(ds.begin(), ds.end());
    for (int i=0;i<cs.size();i++){
        if (cs[i][1] > max2 && cs[i][1] <= maximum){
            max2 = cs[i][1];
        }
        else if (cs[i][1] > maximum){
            max2 = maximum;
            maximum = cs[i][1];
        }
        maxc.push_back(maximum);
        m2c.push_back(max2);
    }
    maximum = -1;
    max2 = -1;
    for (int i=0;i<ds.size();i++){
        if (ds[i][1] > max2 && ds[i][1] <= maximum){
            max2 = ds[i][1];
        }
        else if (ds[i][1] > maximum){
            max2 = maximum;
            maximum = ds[i][1];
        }
        maxd.push_back(maximum);
        m2d.push_back(max2);
    }
    int minimum = 0;
    for (int i=0;i<cs.size();i++){
        int canc = c - cs[i][0];
        int cand = d;
        if (canc < 0) continue;
        int index1 = bs(canc, cs, i);
        int index2 = bs(cand, ds, -2);
        if (index1 == -1 && index2 == -1) continue;
        int m1, m2;
        if (index1 != -1){
            m1 = maxc[index1];
            if (cs[i][1] == maxc[index1]) m1 = m2c[index1];
        }
        if (index1 != -1 && m1 != -1){
            minimum = max(minimum, cs[i][1] + m1);
        }
        if (index2 != -1){
            minimum = max(minimum, cs[i][1] + maxd[index2]);
        }
    }
    for (int i=0;i<ds.size();i++){
        int canc = c;
        int cand = d - ds[i][0];
        if (cand < 0) continue;
        int index1 = bs(canc, cs, -2);
        int index2 = bs(cand, ds, i);
        if (index1 == -1 && index2 == -1) continue;
        int m1, m2;
        if (index2 != -1){
            m2 = maxd[index2];
            if (ds[i][1] == maxd[index2]) m2 = m2d[index2];
        }
        if (index1 != -1){
            minimum = max(minimum, ds[i][1] + maxc[index1]);
        }
        if (index2 != -1 && m2 != -1){
            minimum = max(minimum, ds[i][1] + m2);
        }
    }
    cout << minimum << endl;
    return 0;
}