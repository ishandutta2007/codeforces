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
#define int long long
using namespace std;
int n, xi, yi, ci;
vector<vector<int> > data;
vector<vector<int> > money;
int dfs(int vertex, int last){
    int answer = 0;
    for (int i=0;i<data[vertex].size();i++){
        int to = data[vertex][i];
        if (to == last) continue;
        answer = max(answer, dfs(to, vertex) + money[vertex][i]);
    }
    return answer;
}
int32_t main(){
    cin >> n;
    for (int i=0;i<n;i++){
        vector<int> help, h;
        data.push_back(help);
        money.push_back(h);
    }
    for (int i=0;i<n-1;i++){
        cin >> xi >> yi >> ci;
        data[xi].push_back(yi);
        data[yi].push_back(xi);
        money[xi].push_back(ci);
        money[yi].push_back(ci);
    }
    cout << dfs(0, -1);
    return 0;
}