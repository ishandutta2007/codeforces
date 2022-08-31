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
#define ll long long
using namespace std;
int32_t main(){
    int n, x, y, get;
    cin >> n >> x >> y;
    int xr = x ^ y;
    int res = 0;
    for (int i=0; i < 10; i++){
        vector<int> v;
        for (int j=0; j < n; j++){
            int b_and = j & (1 << i);
            if (b_and == 0){
                v.push_back(j);
            }
        }
        cout << "? " << v.size() << " ";
        for (int j=0; j < v.size(); j++){
            cout << v[j]+1 << " ";
        }
        cout << endl;
        cout.flush();
        cin >> get;
        if (get == xr || get == y){
            res += (1 << i);
        }
    }
    vector<pair<int, int> > p;
    for (int i = 0; i < n ; i++){
        int pp = res ^ i;
        if (pp <= i) continue;
        if (pp >= n) continue;
        p.push_back(make_pair(i, pp));
    }
    while (p.size() > 1){
        vector<pair<int, int> > p1, p2;
        for (int i=0; i < p.size(); i++){
            if (i < p.size() / 2) p1.push_back(p[i]);
            else p2.push_back(p[i]);
        }
        vector<int> v;
        for (int i=0; i < p1.size(); i++){
            v.push_back(p1[i].first);
            v.push_back(p1[i].second);
        }
        for (int i=0; i < p2.size(); i++){
            v.push_back(p2[i].first);
        }
        cout << "? " << v.size() << " ";
        for (int j=0; j < v.size(); j++){
            cout << v[j]+1 << " ";
        }
        cout << endl;
        cout.flush();
        cin >> get;
        if (get == 0 || get == x) p = p1;
        else p = p2;
    }
    cout << "! " << p[0].first+1 << " " << p[0].second+1;
    return 0;
}