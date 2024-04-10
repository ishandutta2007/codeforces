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
int n, m, l, r;
vector<int> lg, rg;
vector<vector<int> > data;
int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> l >> r;
        vector<int> help;
        help.push_back(l);
        help.push_back(r);
        data.push_back(help);
    }
    cin >> m;
    for (int i=0;i<m;i++){
        cin >> l >> r;
        lg.push_back(l);
        rg.push_back(r);
    }
    sort(lg.begin(), lg.end());
    sort(rg.begin(), rg.end());
    int ans = 0;
    for (int i=0;i<n;i++){
        if (lg[lg.size() - 1] > data[i][1]){
            ans = max(ans, lg[lg.size() - 1] - data[i][1]);
        }
        if (rg[0] < data[i][0]){
            ans = max(ans, data[i][0] - rg[0]);
        }
    }
    cout << ans << endl;
    return 0;
}