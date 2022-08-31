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
int n, ai, bi, ci;
vector<vector<int> > data;
vector<int> mon;
vector<bool> used;
vector<int> dp;
int mm;
int answer;
int CONST = 1000000005;
multiset<int> ms;
void dfs(int vertex, int d){
    used[vertex] = true;
    if (d <= 1){
        answer = max(answer, mon[vertex] + d);
    }
    else answer = max(answer, mon[vertex] + 2);
    for (int i=0;i<data[vertex].size();i++){
        int to = data[vertex][i];
        if (used[to]) continue;
        dfs(to, d + 1);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=0;i<n;i++){
        dp.push_back(0);
        cin >> ai;
        ms.insert(ai);
        mon.push_back(ai);
        vector<int> help;
        data.push_back(help);
    }
    for (int i=0;i<n-1;i++){
        cin >> bi >> ci;
        data[bi - 1].push_back(ci - 1);
        data[ci - 1].push_back(bi - 1);
    }
    answer = CONST;
    for (int i=0;i<n;i++){
        int aa = -CONST;
        ms.erase(ms.find(mon[i]));
        aa = max(aa, mon[i]);
        for (int j=0;j<data[i].size();j++){
            int to = data[i][j];
            ms.erase(ms.find(mon[to]));
            aa = max(aa, mon[to] + 1);
        }
        if (ms.size() > 0) {int mz = *ms.rbegin();
        aa = max(aa, mz + 2);
        }
        answer = min(answer, aa);
        ms.insert(mon[i]);
        for (int j=0;j<data[i].size();j++){
            int to = data[i][j];
            ms.insert(mon[to]);
        }
    }
    cout << answer << endl;
    return 0;
}