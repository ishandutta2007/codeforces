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
int n, m, xi, yi;
vector<vector<int> > data;
vector<bool> used;
vector<int> number;
int lb(int number, vector<int> &v){
    int left = -1;
    int right = v.size() - 1;
    while (right - left > 1){
        int mid = (left + right) / 2;
        if (v[mid] >= number) right = mid;
        else left = mid;
    }
    return right;
}
int rb(int number, vector<int> &v){
    int left = 0;
    int right = v.size();
    while (right - left > 1){
        int mid = (left + right) / 2;
        if (v[mid] <= number) left = mid;
        else right = mid;
    }
    return left;
}
void dfs(int vertex, int d){
    used[vertex] = true;
    for (int i=0;i<data[vertex].size();i++){
        int to = data[vertex][i];
        if (number[to] != -1) continue;
        number[to] = number[vertex] + d;
    }
    for (int i=0;i<data[vertex].size();i++){
        int to = data[vertex][i];
        if (used[to]) continue;
        dfs(to, d);
    }
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=0;i<n;i++){
        vector<int> help;
        data.push_back(help);
        used.push_back(false);
        number.push_back(-1);
    }
    for (int i=0;i<m;i++){
        cin >> xi >> yi;
        data[xi-1].push_back(yi-1);
        data[yi-1].push_back(xi - 1);
    }
    int start = 1000000;
    number[0] = start;
    vector<int> sos;
    for (int i=0;i<data[0].size();i++){
        used[data[0][i]] = true;
        sos.push_back(data[0][i]);
    }
    for (int i=0;i<sos.size();i++){
        int r = 0;
        int good = 0;
        for (int j=0;j<data[sos[i]].size();j++){
            if (data[sos[i]][j] == 0) continue;
            r ++;
            if (used[data[sos[i]][j]]){
                good ++;
            }
        }
        if (r == good && good == sos.size() - 1){
            number[sos[i]] = start;
        }
    }
    for (int i=0;i<n;i++){
        used[i] = false;
    }
    int ff = 0;
    int ss = 0;
    for (int i=0;i<sos.size();i++){
        if (number[sos[i]] == start) continue;
        int nn = 0;
        int tt = 0;
        for (int j=0;j<data[sos[i]].size();j++){
            int to = data[sos[i]][j];
            if (to == 0) continue;
            if (used[to]){
                if (number[to] == start - 1) nn ++;
                else tt ++;
            }
        }
        if (nn == 0 && ss == tt) {number[sos[i]] = start + 1; ss++;}
        else if (tt == 0 && nn == ff) {number[sos[i]] = start - 1; ff++;}
        else{
            cout << "NO" << endl;
            return 0;
        }
        used[sos[i]] = true;
    }
    for (int i=0;i<n;i++){
        if (number[i] != -1) used[i] = true;
    }
    for (int i=0;i<data[0].size();i++){
        if (number[data[0][i]] == start){
            dfs(data[0][i], 0);
        }
        if (number[data[0][i]] == start-1){
            dfs(data[0][i], -1);
        }
        if (number[data[0][i]] == start+1){
            dfs(data[0][i], +1);
        }
    }
    vector<int> bp;
    for (int i=0;i<number.size();i++){
        bp.push_back(number[i]);
    }
    sort(bp.begin(), bp.end());
    for (int i=0;i<n;i++){
        int left = lb(number[i] - 1, bp);
        int right = rb(number[i] + 1, bp);
        for (int j=0;j<data[i].size();j++){
            int to = data[i][j];
            if (abs(number[to] - number[i]) > 1){
                cout << "NO" << endl;
                return 0;
            }
        }
        if (right - left != data[i].size()){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    for (int i=0;i<n;i++){
        cout << number[i] << " ";
    }
    return 0;
}