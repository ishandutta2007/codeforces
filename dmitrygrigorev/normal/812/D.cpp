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
int n, m, k, q, ai, bi;
vector<vector<int> > data;
vector<int> summ, tin, tout;
int timer;
map<int, int> go;
vector<bool> tr;
void dfs(int vertex){
    int ss = 1;
    tin[vertex] = timer;
    timer ++;
    for (int i=0;i<data[vertex].size();i++){
        int to = data[vertex][i];
        dfs(to);
        ss += summ[to];
    }
    summ[vertex] = ss;
    tout[vertex] = timer;
    timer++;
}
int32_t main(){
    cin >> n >> m >> k >> q;
    for (int i=0;i<n;i++){
        tr.push_back(false);
        vector<int> help;
        data.push_back(help);
        tin.push_back(-1);
        tout.push_back(-1);
        summ.push_back(-1);
    }
    for (int i=0;i<k;i++){
        cin >> ai >> bi;
        if (!go.count(bi)){
            go[bi] = ai-1;
        }
        else{
            int v = go[bi];
            data[v].push_back(ai-1);
            go[bi] =  ai - 1;
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<data[i].size();j++){
            int v = data[i][j];
            tr[v] = true;
        }
    }
    timer = 0;
    for (int i=0;i<n;i++){
        if (!tr[i]) dfs(i);
    }
    for (int i=0;i<q;i++){
        cin >> ai >> bi;
        if (!go.count(bi)){
            cout << 0 << endl;
        }
        else{
            int v = go[bi];
            if (tin[v] > tin[ai-1] && tin[v] < tout[ai-1]){
                cout << summ[ai-1] << endl;
            }
            else cout << 0 << endl;
        }
    }
    return 0;
}