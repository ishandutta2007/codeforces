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
vector<vector<int> > data;
int n, q, ai;
vector<int> asks, sizes, answers;
void dfs2(int vertex, vector<pair<int, int> > &wanted, int stc){
    int maximum = 0;
    for (int i=0;i<data[vertex].size();i++){
        int to = data[vertex][i];
        maximum = max(sizes[to], maximum);
    }
    while (stc < wanted.size()){
        if (wanted[stc].second >= maximum){
            answers[wanted[stc].first] = vertex;
            stc ++;
        }
        else break;
    }
    bool yes = false;
    if (2 * maximum <= sizes[vertex]){
        answers[vertex] = vertex;
    }
    else{
        yes = true;
        pair<int, int> p;
        p.first = vertex;
        p.second = sizes[vertex] / 2;
        wanted.push_back(p);
    }
    for (int i=0;i<data[vertex].size();i++){
        int to = data[vertex][i];
        if (sizes[to] == maximum && yes) dfs2(to, wanted, stc);
        else{
            vector<pair<int , int> > nlo;
            dfs2(to, nlo, 0);
        }
    }
}
void dfs(int vertex){
    int summ = 0;
    for (int i=0;i<data[vertex].size();i++){
        int to = data[vertex][i];
        dfs(to);
        summ += sizes[to];
    }
    sizes[vertex] = summ + 1;
}
int main(){
    cin >> n >> q;
    for (int i=0;i<n;i++){
        vector<int> help;
        data.push_back(help);
        sizes.push_back(0);
        answers.push_back(0);
    }
    for (int i=0;i<n-1;i++){
        cin >> ai;
        data[ai-1].push_back(i+1);
    }
    for (int i=0;i<q;i++){
        cin >> ai;
        asks.push_back(ai - 1);
    }
    dfs(0);
    vector<pair<int, int> > nl;
    dfs2(0, nl, 0);
    for (int i=0;i<q;i++){
        cout << answers[asks[i]] + 1 << endl;
    }
    return 0;
}