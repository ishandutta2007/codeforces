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
#define int long long
using namespace std;
vector<string> stv;
bool cmp(int first, int second){
    if (stv[first].size() > stv[second].size()) return true;
    return false;
}
signed main()
{
    int n;
    vector<vector<int> > where;
    for (int i=0; i < 1e6; i++){
        vector<int> help;
        where.push_back(help);
    }
    cin >> n;
    for (int i=0; i < n; i++){
        int m;
        string s;
        cin >> s;
        stv.push_back(s);
        cin >> m;
        for (int j=0; j < m; j++){
            int ai;
            cin >> ai;
            where[ai-1].push_back(i);
        }
    }
    for (int i=0; i < 1e6; i++){
        sort(where[i].begin(), where[i].end(), cmp);
    }
    string ans = "";
    for (int i=0; i < 2e6; i++){
        ans += "a";
    }
    int last = -1;
    int nole = 0;
    for (int i=0; i < 1e6; i++){
        if (where[i].size() == 0) continue;
        if (last < i - 1) last = i - 1;
        int uk = where[i][0];
        for (int j=max(nole, last-i+1); j < stv[uk].size(); j++){
            char ch = stv[uk][j];
            ans[last+1] = ch;
            last++;
        }
    }
    string aa = "";
    for (int i=0; i <= last;i++){
        aa += ans[i];
    }
    cout << aa << endl;
    return 0;
}