#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <math.h>
#include <cstdlib>
#include <fstream>
using namespace std;
int n, ai, bi;
map<int, int> mm;
vector<vector<int> > data;
int md, nd;
int noow;
bool flag;
vector<int> put;
vector<int> dist1, dist2;
void dfs1(int vertex, int last, int d){
    dist1[vertex] = d;
    for (int i=0;i<data[vertex].size();i++){
        int to = data[vertex][i];
        if (last == to) continue;
        dfs1(to, vertex, d + 1);
    }
}
void dfs2(int vertex, int last, int d){
    dist2[vertex] = d;
    for (int i=0;i<data[vertex].size();i++){
        int to = data[vertex][i];
        if (last == to) continue;
        dfs2(to, vertex, d + 1);
    }
}
bool go(int vertex, int last){
    if (vertex == md){
        put.push_back(vertex);
        return true;
    }
    for (int i=0;i<data[vertex].size();i++){
        int to = data[vertex][i];
        if (last == to) continue;
        if (go(to, vertex)){
            put.push_back(vertex);
            return true;
        }
    }
    return false;
}
void res(int vertex, int last, int d){
    if (last == -1){
        for (int i=0;i<data[vertex].size();i++){
            int to = data[vertex][i];
            res(to, vertex, d + 1);
            noow ++;
        }
    }
    else{
        bool go = false;
        for (int i=0;i<data[vertex].size();i++){
            int to = data[vertex][i];
            if (to == last) continue;
            res(to, vertex, d + 1);
        go = true;
        }
        if (!go){
            if (mm.count(noow) && mm[noow] != d){
                flag = false;
            }
            else{
                mm[noow] = d;
            }
        }
    }
}
int main(){
    std::ios::sync_with_stdio(false);
    cin >> n;
    for (int i=0;i<n;i++){
        dist1.push_back(0);
        dist2.push_back(0);
        vector<int> help;
        data.push_back(help);
    }
    for (int i=0;i<n-1;i++){
        cin >> ai >> bi;
        data[ai - 1].push_back(bi - 1);
        data[bi - 1].push_back(ai - 1);
    }
    dfs1(0, -1, 0);
    int maximum = 0;
    for (int i=0;i<n;i++){
        if (dist1[i] > maximum){
            maximum = dist1[i];
            md = i;
        }
    }
    dfs2(md, -1, 0);
    maximum = 0;
    for (int i=0;i<n;i++){
        if (dist2[i] > maximum){
            maximum = dist2[i];
            nd = i;
        }
    }
    go(nd, -1);
    int ov = put[maximum / 2];
    flag = true;
    noow = 0;
    res(ov, -1, 0);
    if (!flag){
        cout << -1 << endl;
    }
    else{
        set<int> ss;
        int anss = 0;
        for (int i=0;i<noow;i++){
            int mmm = mm[i];
            if (!ss.count(mmm)){
                anss += mmm;
                ss.insert(mmm);
            }
        }
        if (ss.size() == 0 || ss.size() > 2){
            cout << -1 << endl;
        }
        else{
            while (anss % 2==0){
                anss = anss / 2;
            }
            cout <<anss << endl;
        }
        }
    return 0;
}