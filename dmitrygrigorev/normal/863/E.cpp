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
#define D long double
using namespace std;
int32_t main(){
    int n, ai, bi;
    set<int> bad;
    cin >> n;
    vector<pair<int, int> > events;
    for (int i=0; i < n; i++){
        cin >> ai >> bi;
        events.push_back(make_pair(ai, i));
        events.push_back(make_pair(bi, i));
    }
    sort(events.begin(), events.end());
    int lev = -1;
    set<int> opens;
    bool close = false;
    for (int i=0; i < events.size(); i++){
        int date = events[i].first;
        if (date != lev){
            bool copen = false;
            set<int> counters;
            int u = i;
            while (u < 2*n && events[u].first == date){
                counters.insert(events[u].second);
                if (!opens.count(events[u].second)){
                    copen = true;
                }
                u++;
            }
            if ((!copen || !close || date-lev > 1) && opens.size() == 1){
                int vv = *(opens.begin());
                bad.insert(vv);
            }
            if (counters.size() == 1 && opens.size() == 0){
                int vv = *(counters.begin());
                bad.insert(vv);
            }
            lev = date;
            close = false;
        }
        int el = events[i].second;
        if (opens.count(el)){
            set<int>::iterator it = opens.upper_bound(el-1);
            opens.erase(it);
            close = true;
        }
        else{
            opens.insert(el);
        }
    }
    if (bad.size() == n){
        cout << -1 << endl;
    }
    else{
        for (int i=0; i < n; i++){
            if (!bad.count(i)){
                cout << i+1 << endl;
                return 0;
            }
        }
    }
    return 0;
}