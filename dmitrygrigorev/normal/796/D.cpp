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
int n, k, d, ai, bi;
set<int> police;
vector<int> mp, mn;
vector<vector<int> > data;
vector<bool> used;
map<pair<int, int>, int> mym;
void dfs(int vertex){
    int max_no = 0;
    int max_v = 10000000;
    int ind;
    used[vertex] = true;
    vector<int> vvs;
    for (int i=0;i<data[vertex].size();i++){
        int to = data[vertex][i];
        if (used[to]) continue;
        dfs(to);
        max_no = max(max_no, mn[to]);
        if (mp[to] != -1){
            vvs.push_back(to);
            if (mp[to] < max_v){
                max_v = mp[to];
                ind = vvs.size() - 1;
            }
        }
    }
    if (vvs.size() == 0){
        if (police.count(vertex)){
            mn[vertex] = 0;
            mp[vertex] = 0;
        }
        else{
            mn[vertex] = max_no + 1;
        }
    }
    else{
        if (police.count(vertex)){
            for (int i=0;i<vvs.size();i++){
                int c = vvs[i];
                int e = vertex;
                if (c > e) swap(c, e);
                pair<int, int> pp;
                pp.first = c;
                pp.second = e;
                cout << mym[pp] << " ";
            }
            mp[vertex] = 0;
        }
        else{
            for (int i=0;i<vvs.size();i++){
                if (i != ind){
                    int c = vvs[i];
                    int e = vertex;
                    if (c > e) swap(c, e);
                    pair<int, int> pp;
                    pp.first = c;
                    pp.second = e;
                    cout << mym[pp] << " ";
                }
                else{
                    if (max_v + max_no + 1 > d){
                        int c = vvs[i];
                        int e = vertex;
                        if (c > e) swap(c, e);
                        pair<int, int> pp;
                        pp.first = c;
                        pp.second = e;
                        cout << mym[pp] << " ";
                        mn[vertex] = max_no + 1;
                        mp[vertex] = -1;
                    }
                    else{
                        mp[vertex] = max_v + 1;
                    }
                }
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin >> n >> k >> d;
    for (int i=0;i<n;i++){
        vector<int> help;
        data.push_back(help);
        used.push_back(false);
        mp.push_back(-1);
        mn.push_back(0);
    }
    for (int i=0;i<k;i++){
        cin >> ai;
        police.insert(ai - 1);
    }
    for (int i=0;i<n-1;i++){
        cin >> ai >> bi;
        if (ai > bi) swap(ai, bi);
        pair<int, int> pp;
        pp.first = ai - 1;
        pp.second = bi - 1;
        mym[pp] = i + 1;
        data[ai - 1].push_back(bi - 1);
        data[bi - 1].push_back(ai - 1);
    }
    cout << police.size() - 1 << endl;
    dfs(0);
    return 0;
}