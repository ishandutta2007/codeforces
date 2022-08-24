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
int n, a, b, c, d, pi;
set<int> cant;
vector<vector<int> > data;
vector<int> graf, can;
vector<int> sons;
int otdel;
void get(int vertex, int son){
    if (vertex == 0) {cant.insert(son); return;}
    for (int i=0;i<data[vertex].size();i++){
        int to = data[vertex].size();
        if (to == son) continue;
        can.push_back(sons[to]);
    }
    get(graf[vertex], vertex);
}
void dfs(int vertex){
    int summ = 0;
    for (int i=0;i<data[vertex].size();i++){
        int to = data[vertex][i];
        dfs(to);
        summ += sons[to];
    }
    if (summ == 0) {summ = 1; otdel ++;}
    sons[vertex] = summ;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin >> n >> a >> b >> c >> d;
    for (int i=0;i<n;i++){
        vector<int> help;
        data.push_back(help);
        sons.push_back(0);
    }
    graf.push_back(-1);
    for (int i=0;i<n-1;i++){
        cin >> pi;
        data[pi-1].push_back(i+1);
        graf.push_back(pi-1);
    }
    otdel = 0;
    dfs(0);
    if (otdel % 2 != 0){
        cout << "NO" << endl;
        return 0;
    }
    int sz = otdel / 2 - 1;
    get(graf[a - 1], a - 1);
    get(graf[b-1], b-1);
    for (int i=0;i<data[0].size();i++){
        int to = data[0][i];
        if (cant.count(to)) continue;
        can.push_back(sons[to]);
    }
    int ssz = can.size();
    bool dp[ssz + 1][sz+1];
    for (int i=0;i<=ssz;i++){
        dp[i][0] = true;
        for (int j=1;j<=sz;j++){
            dp[i][j] = false;
        }
    }
    for (int i=1;i<=ssz;i++){
        for (int j=1;j<=sz;j++){
            if (dp[i-1][j]) dp[i][j] = true;
            if (j - can[i-1] >= 0){
                if (dp[i-1][j - can[i-1]]){
                    dp[i][j] = true;
                }
            }
        }
    }
    bool yes = false;
    for (int i=0;i<=ssz;i++){
        if (dp[i][sz]) yes = true;
    }
    if (!yes) {cout << "NO" << endl; return 0;}
    can.clear();
    cant.clear();
    get(graf[c - 1], c - 1);
    get(graf[d-1], d-1);
    for (int i=0;i<data[0].size();i++){
        int to = data[0][i];
        if (cant.count(to)) continue;
        can.push_back(sons[to]);
    }
    ssz = can.size();
    bool dp2[ssz + 1][sz+1];
    for (int i=0;i<=ssz;i++){
        dp2[i][0] = true;
        for (int j=1;j<=sz;j++){
            dp2[i][j] = false;
        }
    }
    for (int i=1;i<=ssz;i++){
        for (int j=1;j<=sz;j++){
            if (dp2[i-1][j]) dp2[i][j] = true;
            if (j - can[i-1] >= 0){
                if (dp2[i-1][j - can[i-1]]){
                    dp2[i][j] = true;
                }
            }
        }
    }
    yes = false;
    for (int i=0;i<=ssz;i++){
        if (dp2[i][sz]) yes = true;
    }
    if (!yes) {cout << "NO" << endl; return 0;}
    cout << "YES" << endl;
    return 0;
}