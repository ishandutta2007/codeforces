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
#include <deque>
#define int long long
using namespace std;
int32_t main(){
    int n, a, b, k, f;
    cin >> n >> a >> b >> k >> f;
    vector<pair<string, string> > v(n);
    string ai, bi;
    for (int i=0; i < n; i++){
        cin >> ai >> bi;
        v[i] = make_pair(ai, bi);
    }
    int money = 0;
    map<pair<string, string>, int> mm;
    for (int i=0; i < n; i++){
        string s1 = v[i].first;
        string s2 = v[i].second;
        if (s2 > s1) swap(s1, s2);
        if (i > 0 && v[i-1].second == v[i].first){
            mm[make_pair(s1, s2)] += b;
            money += b;
        }
        else {
            mm[make_pair(s1, s2)] += a;
            money += a;
        }
    }
    vector<int> vv;
    while (mm.size() > 0){
        map<pair<string, string>, int>::iterator it = mm.begin();
        int vq = (*it).second;
        mm.erase(it);
        vv.push_back(vq);
    }
    sort(vv.begin(), vv.end(), greater<int>());
    int ii = 0;
    while (ii < vv.size() && vv[ii] > f && k > 0){
        money -= vv[ii] - f;
        ii++;
        k--;
    }
    cout << money << endl;
    return 0;
}