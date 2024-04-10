#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <math.h>
#include <fstream>
using namespace std;
int m, pi, ti;
map<int, int> mymap;
vector<vector<int> > data;
vector<int> rmq;
vector<int> mod;
int result(int i, int l, int r, int pp){
    if (r - l == 1){
        return l;
    }
    pp += mod[i];
    int mid = (l + r) / 2;
    if (rmq[2 * i + 1] > -pp && mid > l){
        return result(2*i+1, l, mid, pp);
    }
    else{
        return result(2*i+2, mid, r, pp);
    }
}
int modificate(int i, int l1, int r1, int l, int r, int ch){
    if (l >= r){
        return -10000000;
    }
    if (l1 >= r1){
        return rmq[i];
    }
    if (l1 == l && r1 == r){
        rmq[i] += ch;
        mod[i] += ch;
        return rmq[i];
    }
    int mid = (l + r) / 2;
    int res1 = modificate(2*i + 1, l1, min(mid, r1), l, mid, ch) + mod[i];
    int res2 = modificate(2*i + 2, max(mid, l1), r1, mid, r, ch) + mod[i];
    rmq[i] = max(res1, res2);
    return rmq[i];
}
int main(){
    std::ios::sync_with_stdio(false);
    cin >> m;
    for (int i=0;i<m;i++){
        cin >> pi >> ti;
        vector<int> help;
        help.push_back(pi);
        help.push_back(ti);
        if (ti == 1){
            cin >> ti;
            mymap[pi] = ti;
        }
        data.push_back(help);
    }
    for (int i=0;i<4*m;i++){
        rmq.push_back(0);
        mod.push_back(0);
    }
    for (int i=0;i<m;i++){
        int index = m - data[i][0];
        if (data[i][1] == 0){
            modificate(0, index, m, 0, m, -1);
        }
        else{
            modificate(0, index, m, 0, m, 1);
        }
        if (rmq[0] <= 0){
            cout << -1 << endl;
        }
        else{
            int ii = result(0, 0, m, 0);
            int ni = m - ii;
            cout << mymap[ni] << endl;
        }
    }
    return 0;
}