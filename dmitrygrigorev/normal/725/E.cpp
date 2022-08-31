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
int n, c, ai;
map<int, int> moneys;
vector<int> data;
vector<int> nexts;
int main(){
    std::ios::sync_with_stdio(false);
    cin >> c >> n;
    for (int i=0;i<n;i++){
        cin >> ai;
        if (!moneys.count(ai)){
            moneys[ai] = 1;
            data.push_back(ai);
        }
        else{
            moneys[ai] ++;
        }
    }
    sort(data.begin(), data.end());
    int now = 0;
    nexts.push_back(-1);
    for (int j=1;j<data[0];j++){
        nexts.push_back(-1);
    }
    now = data[0];
    for (int i=1;i<data.size();i++){
        for (int j=now;j<data[i];j++){
            nexts.push_back(now);
        }
        now = data[i];
    }
    for (int i=now;i<=c;i++){
        nexts.push_back(now);
    }
    for (int i=1;i<c;i++){
        int mm = c;
        vector<pair<int, int> > ch;
        bool go = true;
        while (true){
            if (i > nexts[mm] && i <= mm && go){
                mm -= i;
                go = false;
                continue;
            }
            if (nexts[mm] == -1 && mm > 0){
                cout << i << endl;
                return 0;
            }
            int nn = nexts[mm];
            int rr = moneys[nn];
            if (i == nexts[mm] && go){
                rr ++;
                go = false;
            }
            int ber = min(mm / nn, rr);
            mm -= ber * nn;
            if (mm == 0) break;
            if (nexts[mm] >= nn){
                pair<int, int> p;
                p.first = mm;
                p.second = nexts[mm];
                ch.push_back(p);
                nexts[mm] = nexts[nn-1];
            }
        }
        for (int i=0;i<ch.size();i++){
            nexts[ch[i].first] = ch[i].second;
        }
    }
    cout << "Greed is good" << endl;
    return 0;
}