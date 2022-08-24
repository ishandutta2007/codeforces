#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <bits/stdc++.h>
#include <math.h>
#include <fstream>
using namespace std;
vector<vector<int> > data;
vector<bool> used;
int comp;
void dfs(int vertex, int last){
    used[vertex] = true;
    for (int i=0;i<data[vertex].size();i++){
        int to = data[vertex][i];
        if (to != last){
            if (!used[to]){
                dfs(to, vertex);
            }
        }
    }
}
int main(){
    std::ios::sync_with_stdio(false);
    int n, ai;
    cin >> n;
    for (int i=0;i<n;i++){
        used.push_back(false);
        vector<int> help;
        data.push_back(help);
    }
    for (int i=0;i<n;i++){
        cin >> ai;
        if (ai-1 != i){
        data[ai - 1].push_back(i);
        data[i].push_back(ai - 1);
        }
    }
    comp = 0;
    for (int i=0;i<n;i++){
        if (!used[i]){
        comp ++;
        dfs(i, -1);
        }
    }
    cout << comp << endl;
    return 0;
}