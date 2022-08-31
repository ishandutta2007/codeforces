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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, w, h;
    cin >> n >> w >> h;
    vector<vector<int> > vert, hor;
    map<int, deque<int > > mm;
    map<int, vector<int> > ww;
    for (int i=0;i < n; i++){
        int gi, pi, ti;
        cin >> gi >> pi >> ti;
        vector<int> help;
        help.push_back(pi);
        help.push_back(ti);
        help.push_back(i);
        if (gi == 1){
            vert.push_back(help);
        }
        else{
            hor.push_back(help);
        }
    }
    sort(vert.begin(), vert.end());
    sort(hor.begin(), hor.end());
    vector<int> values;
    for (int i=0; i < hor.size(); i++){
        int diff = hor[i][1] - hor[i][0];
        if (mm.count(diff)){
            mm[diff].push_back(hor[i][2]);
            ww[diff].push_back(hor[i][0]);
        }
        else{
            values.push_back(diff);
            deque<int> dd;
            dd.push_back(hor[i][2]);
            mm[diff] = dd;
            vector<int> ws;
            ws.push_back(hor[i][0]);
            ww[diff] = ws;
        }
    }
    sort(values.begin(), values.end());
    vector<pair<int, int> > ans(n);
    for (int i=0; i < vert.size(); i++){
        int wd = vert[i][1] - vert[i][0];
        if (!mm.count(wd)){
            ans[vert[i][2]] = make_pair(vert[i][0], h);
        }
        else{
            int ind = mm[wd].back();
            ans[ind] = make_pair(vert[i][0], h);
            mm[wd].pop_back();
            mm[wd].push_front(vert[i][2]);
        }
    }
    for (int i=0; i < values.size(); i++){
        int el = values[i];
        vector<int> v = ww[el];
        deque<int> de = mm[el];
        for (int j=0; j < v.size(); j++){
            int hn = v[j];
            int what = de[j];
            ans[what] = make_pair(w, hn);
        }
    }
    for (int i=0; i < n; i++){
        cout << ans[i].first << " " << ans[i].second << endl;
    }
    return 0;
}