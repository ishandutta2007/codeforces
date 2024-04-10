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
vector<vector<long long > > moneys;
vector<int> sp;
vector<int> positions;
set <int> myset;
vector<vector<int> > ans;
int peoples, ai, bi, ki, vi;
int n, q;
int bs(int elem, int minimum){
    int l = -1;
    int r = moneys[elem].size() - 1;
    while (r - l > 1){
        int m = (r + l) / 2;
        if (moneys[elem][m] > minimum){
            r = m;
        }
        else{
            l = m;
        }
    }
    return moneys[elem][r];
}
int main(){
    peoples = 0;
    std::ios::sync_with_stdio(false);
    cin >> n;
    for (int i=0;i<n;i++){
        vector<long long> help;
        moneys.push_back(help);
    }
    for (int i=0;i<n;i++){
        cin >> ai >> bi;
        moneys[ai - 1].push_back(bi);
        sp.push_back(ai - 1);
    }
    for (int i=n-1;i>=0;i--){
        if (!myset.count(sp[i])){
            positions.push_back(sp[i]);
            peoples ++;
            myset.insert(sp[i]);
        }
    }
    cin >> q;
    for (int i=0;i<q;i++){
        vector<int> help;
        cin >> ki;
        set <int> mset;
        for (int j=0;j<ki;j++){
            cin >> vi;
            if (myset.count(vi-1)){
            mset.insert(vi - 1);
            }
        }
        if (mset.size() == peoples){
            help.push_back(0);
            help.push_back(0);
        }
        if (mset.size() + 1 == peoples){
            for (int p = 0;p<positions.size();p++){
                if (!mset.count(positions[p])){
                    help.push_back(positions[p] + 1);
                    help.push_back(moneys[positions[p]][0]);
                }
            }
        }
        if (mset.size() + 1 < peoples){
            bool go = false;
            int poisk, poisk2;
            for (int p = 0;p<positions.size();p++){
                if (!mset.count(positions[p])){
                    if (!go){
                        go = true;
                        poisk = positions[p];
                    }
                    else{
                        poisk2 = moneys[positions[p]][moneys[positions[p]].size()-1];
                        break;
                    }
                }
            }
            help.push_back(poisk+1);
            help.push_back(bs(poisk, poisk2));
        }
        ans.push_back(help);
    }
    for (int i=0;i<q;i++){
        cout << ans[i][0] << " " << ans[i][1] << endl;
    }
    return 0 ;
}