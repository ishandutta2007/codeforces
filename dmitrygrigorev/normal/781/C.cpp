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
using namespace std;
int n, m, k, x, y;
vector<vector<int> > data;
vector<bool> used;
vector<int> answer;
void dfs(int vertex){
    used[vertex] = true;
    answer.push_back(vertex + 1);
    for (int i=0;i<data[vertex].size();i++){
        int to = data[vertex][i];
        if (used[to]) continue;
        dfs(to);
        answer.push_back(vertex + 1);
    }
}
int main(){
    std::ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i=0;i<n;i++){
        vector<int> help;
        used.push_back(false);
        data.push_back(help);
    }
    for (int i=0;i<m;i++){
        cin >> x >> y;
        data[x - 1].push_back(y - 1);
        data[y - 1].push_back(x - 1);
    }
    dfs(0);
    int clone = 2 * n / k;
    if ((2 * n) % k != 0){
        clone ++;
    }
    int now = 0;
    for (int i=0;i<n;i++){
        used[i] = false;
    }
    int ccc = 0;
    int i = 0;
    while(i < k){
        if (now >= answer.size()) now = 0;
        int cc = 0;
        vector<int> pp;
        while (now < answer.size() && cc < clone){
            if (cc == 0 && ccc != n && used[answer[now] - 1]) {now ++;continue;}
            pp.push_back(answer[now]);
            if (!used[answer[now] - 1]){
            ccc ++;
            }
            used[answer[now] - 1] = true;
            now ++;
            cc ++;
        }
        if (pp.size() == 0) continue;
        cout << pp.size() << " ";
        for (int j=0;j<pp.size();j++){
            cout << pp[j] << " ";
        }
        i ++;
cout << endl;
    }
    return 0;
}