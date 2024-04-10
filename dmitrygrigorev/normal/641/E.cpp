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
int n, a, t, x;
int ans;
vector<map<int, int> > rmq;
vector<vector<int> > data;
vector<int> num;
void change(int i, int l, int r, int ind, int ch, int d){
    if (r - l == 1){
        if (rmq[i].count(ch)){
            rmq[i][ch] += d;
        }
        else{
            rmq[i][ch] = d;
        }
    }
    else{
        int m = (l + r) / 2;
        if (ind < m){
            change(2*i+1, l, m, ind, ch, d);
        }
        else change(2*i+2, m, r, ind, ch, d);
        if (rmq[i].count(ch)){
            rmq[i][ch] += d;
        }
        else{
            rmq[i][ch] = d;
        }
    }
}
void result(int i, int l, int r, int l1, int r1, int ch){
    if (l1 >= r1) return;
    if (l == l1 && r == r1){
        if (rmq[i].count(ch)){
            ans += rmq[i][ch];
        }
        return;
    }
    int m = (l + r) / 2;
    result(2*i+1, l, m, l1, min(r1, m), ch);
    result(2*i+2, m, r, max(l1, m), r1, ch);
}
int main(){
    std::ios::sync_with_stdio(false);
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> a >> t >> x;
        vector<int> help;
        num.push_back(-1);
        help.push_back(t);
        help.push_back(a);
        help.push_back(x);
        help.push_back(i);
        data.push_back(help);
    }
    vector<vector<int> > d = data;
    sort(d.begin(), d.end());
    for (int i=0;i<n;i++){
        num[d[i][3]] = i;
    }
    for (int i=0;i<4*n;i++){
        map<int, int> mm;
        rmq.push_back(mm);
    }
    for (int i=0;i<n;i++){
        vector<int> zapros = data[i];
        int number = num[i];
        x = zapros[2];
        a = zapros[1];
        if (a == 1){
            change(0, 0, n, number, x, 1);
        }
        else if (a == 2){
            change(0, 0, n, number, x, -1);
        }
        else{
            ans = 0;
            result(0, 0, n, 0, number, x);
            cout << ans << endl;
        }
    }
    return 0;
}