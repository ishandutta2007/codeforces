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
int n, m, q, ai, bi;
vector<vector<int> > data;
vector<int> comp, lengths;
vector<vector<int> > ask;
vector<bool> used;
vector<vector<int> > lines;
map<pair<int, int>, long double > has;
int bs(int nn, int counts){
    int l = -1;
    int r = lines[nn].size();
    while (r - l > 1){
        int md = (l + r) / 2;
        if (lines[nn][md] >= counts) r = md;
        else l = md;
    }
    return r;
}
void dfs(int vertex, int last){
    comp[vertex] = lines.size();
    used[vertex] = true;
    int mm = -1;
    for (int i=0;i<data[vertex].size();i++){
        int to = data[vertex][i];
        if (last == to) continue;
        dfs(to, vertex);
        mm = max(mm, lengths[to]);
    }
    lengths[vertex] = mm + 1;
}
void dfs1(int vertex, int last, int our){
    lengths[vertex] = max(our, lengths[vertex]);
    lines.back().push_back(lengths[vertex]);
    int max1 = -1000000000;
    int max2 = -1000000000;
    for (int i=0;i<data[vertex].size();i++){
        int to = data[vertex][i];
        if (to == last) continue;
        if (lengths[to] <= max2) continue;
        if (lengths[to] <= max1) max2 = lengths[to];
        else{
            max2 = max1;
            max1 = lengths[to];
        }
    }
    for (int i=0;i<data[vertex].size();i++){
        int to = data[vertex][i];
        if (to == last) continue;
        if (lengths[to] == max1){
            dfs1(to, vertex, max(our + 1, max2 + 2));
        }
        else dfs1(to, vertex, max(our + 1, max1 + 2));
    }
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> q;
    for (int i=0;i<n;i++){
        vector<int> help;
        data.push_back(help);
        used.push_back(false);
        comp.push_back(0);
        lengths.push_back(0);
    }
    for (int i=0;i<m;i++){
        cin >> ai >> bi;
        data[ai-1].push_back(bi - 1);
        data[bi - 1].push_back(ai - 1);
    }
    for (int i=0;i<q;i++){
        cin >> ai >> bi;
        vector<int> help;
        help.push_back(ai - 1);
        help.push_back(bi - 1);
        ask.push_back(help);
    }
    for (int i=0;i<n;i++){
        if (used[i]) continue;
        dfs(i, -1);
        vector<int> help;
        lines.push_back(help);
        dfs1(i, -1, 0);
    }
    for (int i=0;i<lines.size();i++){
        sort(lines[i].begin(), lines[i].end());
    }
    vector<vector<int> > ps;
    for (int i=0;i<lines.size();i++){
        vector<int> help;
        help.push_back(0);
        int ss = 0;
        for (int j=0;j<lines[i].size();j++){
            ss += lines[i][j];
            help.push_back(ss);
        }
        ps.push_back(help);
    }
    cout.precision(30);
    for (int i=0;i<q;i++){
        int c1 = comp[ask[i][1]];
        int c2 = comp[ask[i][0]];
        if (c1 > c2) swap(c1, c2);
        if (c1 == c2){
            cout << -1 << endl;
            continue;
        }
        pair<int, int> p;
        p.first = c1;
        p.second = c2;
        if (has.count(p)){
            cout << has[p] << endl;
            continue;
        }
        if (lines[c1].size() > lines[c2].size()) swap(c1, c2);
        int summ = 0;
        for (int j=0;j<lines[c1].size();j++){
            int ff = lines[c1][j];
            int ind = bs(c2, max(lines[c2].back(), lines[c1].back()) - 1 - ff);
            summ += ind * max(lines[c1].back(), lines[c2].back());
            summ += ps[c2][lines[c2].size()] - ps[c2][ind] + (ff + 1) * (lines[c2].size() - ind);
        }
        long double dd = summ;
        long double ddd = lines[c1].size() * lines[c2].size();
        cout << dd / ddd << endl;
        has[p] = dd / ddd;
    }
    return 0;
}