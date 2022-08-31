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
int n, k, xi, yi, pi;
vector<vector<int> > data;
vector<vector<int> > money;
vector<int> first, second;
void dfs(int vertex, int last, int edge){
    int counter = 0;
    for (int i=0;i<data[vertex].size();i++){
        int to = data[vertex][i];
        if (to == last) continue;
        dfs(to, vertex, money[vertex][i]);
        counter++;
    }
    if (counter == 0){
        first[vertex] = edge;
        second[vertex] = edge;
        return;
    }
    vector<pair<int, int> > v;
    for (int i=0;i<data[vertex].size();i++){
        int to = data[vertex][i];
        if (to == last) continue;
        pair<int, int> p;
        p.first = first[to];
        p.second = second[to];
        v.push_back(p);
    }
    sort(v.begin(), v.end(), greater<pair<int, int> > ());
    int summ = 0;
    int sz = v.size();
    for (int i=0;i<min(k-1, sz);i++){
        summ += v[i].first;
    }
    first[vertex] = summ;
    for (int i=0;i<min(k-1, sz);i++){
        int summ1 = summ;
        summ1 -= v[i].first;
        summ1 += v[i].second;
        if (k-1 < sz){
            summ1 += v[k-1].first;
        }
        second[vertex] = max(summ1, second[vertex]);
    }
    for (int i=k-1;i<v.size();i++){
        int summ1 = summ + v[i].second;
        second[vertex] = max(summ1, second[vertex]);
    }
    first[vertex] += edge;
    second[vertex] += edge;
}
int32_t main(){
    cin >> n >> k;
    for (int i=0;i<n;i++){
        vector<int> h1, h2;
        data.push_back(h1);
        money.push_back(h2);
        first.push_back(0);
        second.push_back(0);
    }
    for (int i=0;i<n-1;i++){
        cin >> xi >> yi >> pi;
        data[xi].push_back(yi);
        data[yi].push_back(xi);
        money[xi].push_back(pi);
        money[yi].push_back(pi);
    }
    dfs(0, -1, 0);
    cout << second[0] << endl;
    return 0;
}