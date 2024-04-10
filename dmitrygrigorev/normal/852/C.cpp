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
    int n, ai;
    vector<int> data;
    cin >> n;
    for (int i=0; i < n; i++){
        cin >> ai;
        data.push_back(ai);
    }
    vector<vector<int> > v;
    for (int i=0; i < n; i++){
        int z = n - data[i];
        int diff = data[(i+1) % n] - z;
        vector<int> help;
        help.push_back(diff);
        help.push_back(i);
        v.push_back(help);
    }
    sort(v.begin(), v.end());
    vector<int> answer(n);
    for (int i=0; i < n; i++){
        int b = v[i][1];
        answer[b] = i;
    }
    for (int i=0; i < n; i++){
        cout << answer[i] << " ";
    }
    return 0;
}