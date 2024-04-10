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
int n, ai, bi;
vector<vector<int> > data;
int even, odd;
void dfs(int vertex, int last, bool ev_add){
    if (ev_add) even++;
    else odd++;
    for (int i=0; i < data[vertex].size(); i++){
        int to = data[vertex][i];
        if (to == last) continue;
        dfs(to, vertex, ev_add^1);
    }
}
int32_t main(){
    cin >> n;
    for (int i=0; i < n; i++){
        vector<int> help;
        data.push_back(help);
    }
    for (int i=0; i <n-1; i++){
        cin >> ai >> bi;
        data[ai-1].push_back(bi-1);
        data[bi-1].push_back(ai-1);
    }
    even = 0;
    odd = 0;
    dfs(0, -1, true);
    cout << even*odd - n + 1 << endl;
    return 0;
}