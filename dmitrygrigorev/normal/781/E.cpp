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
int h, w, n;
int u, ll, rr, s;
long long summ;
int CONST = 1000000007;
int MK = 2000000000;
vector<int> rmq;
vector<int> rmq2;
vector<vector<pair<int, int> > > place;
void create(int i, int l, int r){
    if (l >= r) return;
    if (r - l == 1) {rmq[i] = h + 1; rmq2[i] = l; return;}
    int m = (l + r) / 2; create(2*i+1, l, m);create(2*i+2, m, r);rmq[i] = h + 1; rmq2[i] = l;
}
int mr(int i, int l, int r, int l1, int r1){
    if (l1 >= r1) {return MK;}
    if (l == l1 && r == r1){
        return rmq[i];
    }
    int m = (l + r) / 2;
    return min(mr(2*i+1, l, m, l1, min(r1, m)), mr(2*i+2, m, r, max(l1, m), r1));
}
int mr2(int i, int l, int r, int l1, int r1, int cc){
    if (l1 >= r1) {return -1;}
    if (l1 == l && r1 == r && rmq[i] == cc){
        return rmq2[i];
    }
    if (l1 == l && r1 == r) return -1;
    int m = (l + r) / 2;
    int res1 = mr2(2*i+1, l, m, l1, min(r1, m), cc);
    if (res1 != -1) return res1;
    return mr2(2*i+2, m, r, max(l1, m), r1, cc);
}
int del(int vertex, int kraj){
    while (place[vertex].size() > 0 && place[vertex].back().first <= kraj){
        summ += place[vertex].back().second;
        summ %= CONST;
        place[vertex].pop_back();
    }
    if (place[vertex].size() == 0) return MK;
    return place[vertex].back().first;
}
void change(int i, int l, int r, int ind, int counts){
    if (r - l == 1) {rmq[i] = counts; return;}
    int m = (l + r) / 2;
    if (ind < m){
    change(2*i+1, l, m, ind, counts);
    }
    else{
        change(2*i+2, m, r, ind, counts);
    }
    rmq[i] = min(rmq[2*i+1], rmq[2*i+2]);
    if (rmq[2*i+1] < rmq[2*i+2]){
        rmq2[i] = rmq2[2*i+1];
    }
    else rmq2[i] = rmq2[2*i+2];
}
int main(){
    std::ios::sync_with_stdio(false);
    cin >> h >> w >> n;
    for (int i=0;i<4*w;i++){
        rmq.push_back(0);
        rmq2.push_back(0);
    }
    create(0, 0, w);
    for (int i=0;i<w;i++){
        vector<pair<int, int> > pl;
        pair<int, int> p;
        p.first = h + 1;
        p.second = 1;
        pl.push_back(p);
        place.push_back(pl);
    }
    vector<vector<int> > ask;
    for (int i=0;i<n;i++){
        cin >> u >> ll >> rr >> s;
        vector<int> help;
        help.push_back(u);
        help.push_back(ll);
        help.push_back(rr);
        help.push_back(s);
        ask.push_back(help);
    }
    sort(ask.begin(), ask.end());
    for (int i=n-1;i>=0;i--){
        u = ask[i][0];
        ll = ask[i][1] - 1;
        rr = ask[i][2];
        s = ask[i][3];
        summ = 0;
        while (true){
            int mz = mr(0, 0, w, ll, rr);
            int mv = mr2(0, 0, w, ll, rr, mz);
            if (mz > u + s) break;
            int rr = del(mv, u + s);
            change(0, 0, w, mv, rr);
        }
        if (ll == 0){
            change(0, 0, w, rr, u);
            pair<int, int> p;
            p.first = u;
            p.second = 2*summ;
            place[rr].push_back(p);
        }
        else if (rr == w){
            change(0, 0, w, ll-1, u);
            pair<int, int> p;
            p.first = u;
            p.second = (2*summ) % CONST;
            place[ll-1].push_back(p);
        }
        else{
            change(0, 0, w, ll-1, u);
            pair<int, int> p;
            p.first = u;
            p.second = summ % CONST;
            place[ll-1].push_back(p);
            change(0, 0, w, rr, u);
            pair<int, int> p1;
            p1.first = u;
            p1.second = summ % CONST;
            place[rr].push_back(p1);
        }
    }
    long long ans = 0;
    for (int i=0;i<w;i++){
        while (place[i].size() > 0){
            ans += place[i].back().second;
            ans %= CONST;
            place[i].pop_back();
        }
    }
    ans = (ans + CONST) % CONST;
    cout << ans << endl;
    return 0;
}