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
using namespace std;
int n, m, ai, bi;
vector<vector<int> > data;
vector<int> colour;
vector<vector<int> > cc;
set<int> ms;
void dfs(int vertex, int last){
    if (last != -1){
        ms.clear();
        for (int i=0;i<cc[vertex].size();i++){
            int col = colour[cc[vertex][i]];
            if (col == -1) continue;
            ms.insert(col);
        }
        int nc = 1;
        for (int i=0;i<cc[vertex].size();i++){
            int col = colour[cc[vertex][i]];
            if (col != -1) continue;
            while(ms.count(nc)) nc ++;
            colour[cc[vertex][i]] = nc;
            nc ++;
        }
    }
    for (int i=0;i<data[vertex].size();i++){
        int to = data[vertex][i];
        if (to == last) continue;
        dfs(to, vertex);
    }
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    int mxs = 0;
    int ind;
    for (int i=0;i<n;i++){
        vector<int> help;
        data.push_back(help);
    }
    for (int i=0;i<m;i++){
        colour.push_back(-1);
    }
    for (int i=0;i<n;i++){
        cin >> ai;
        vector<int> help;
        cc.push_back(help);
        for (int j=0;j<ai;j++){
            cin >> bi;
            cc[i].push_back(bi - 1);
        }
        if (ai > mxs){
            mxs = ai;
            ind = i;
        }
    }
    for (int i=0;i<n-1;i++){
        cin >> ai >> bi;
        data[ai-1].push_back(bi-1);
        data[bi-1].push_back(ai-1);
    }
    if (mxs == 0){
        cout << 1 << endl;
        for (int i=0;i<m;i++){
            cout << 1 << " ";
        }
        return 0;
    }
    cout << mxs << endl;
    for (int i=0;i<cc[ind].size();i++){
        colour[cc[ind][i]] = i + 1;
    }
    dfs(ind, -1);
    for (int i=0;i<m;i++){
        if (colour[i] == -1) colour[i] = 1;
        cout << colour[i] << " ";
    }
    return 0;
}