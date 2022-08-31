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
int n, m, t, ai, bi, ci, minim, wanted, counter;
vector<int> data;
vector<int> steps;
int CONST = 1000000005;
vector<int> rmq, mins;
vector<vector<int> > ask;
vector<bool> ch, bits;
set<int> cans;
map<int, int> can;
void new_element(int i, int l, int r, int x, int d){
    if (r - l == 1) {rmq[i] = d; mins[i] = 1;}
    else{
        int m = (l + r) / 2;
        if (x < m) new_element(2*i+1, l, m, x, d);
        else new_element(2*i+2, m, r, x, d);
        rmq[i] = max(rmq[2*i+1], rmq[2*i+2]);
        if (rmq[2*i+1] > rmq[2*i+2]){
            mins[i] = mins[2*i+1];
        }
        else if (rmq[2*i+1] < rmq[2*i+2]){
            mins[i] = mins[2*i+2];
        }
        else mins[i] = mins[2*i+1] + mins[2*i+2];
    }
}
void get_result(int i, int l, int r, int l1, int r1){
    if (l1 >= r1) return;
    if (l == l1 && r == r1){
        if (rmq[i] == wanted){
            counter += mins[i];
        }
        minim = max(minim, rmq[i]);
        return;
    }
    int m = (l + r) / 2;
    get_result(2*i+1, l, m, l1, min(r1, m));
    get_result(2*i+2, m, r, max(l1, m), r1);
}
void create(int i, int l, int r){
    if (r - l == 1){
        rmq[i] = data[l];
        mins[i] = 1;
    }
    else{
        int m = (l + r) / 2;
        create(2*i+1, l, m);
        create(2*i+2, m, r);
        rmq[i] = max(rmq[2*i+1], rmq[2*i+2]);
        if (rmq[2*i+1] > rmq[2*i+2]){
            mins[i] = mins[2*i+1];
        }
        else if (rmq[2*i+1] < rmq[2*i+2]){
            mins[i] = mins[2*i+2];
        }
        else mins[i] = mins[2*i+1] + mins[2*i+2];
    }
}
void result(int i, int l, int r, int x){
    if (r - l == 1){
        minim = min(minim, rmq[i]);
        return;
    }
    int m = (l + r) / 2;
    if (x < m) result(2*i+1, l, m, x);
    else result(2*i+2, m, r, x);
    minim = min(minim, rmq[i]);
}
void change(int i, int l, int r, int l1, int r1, int d){
    if (l1 >= r1) return;
    if (l == l1 && r == r1){
        rmq[i] = min(rmq[i], d);
        return;
    }
    int m = (l + r) / 2;
    change(2*i+1, l, m, l1, min(r1, m), d);
    change(2*i+2, m, r, max(l1, m), r1, d);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=0;i<m;i++){
        cin >> t;
        vector<int> help;
        help.push_back(t);
        if (t == 1){
            cin >> ai >> bi >> ci;
            help.push_back(ai);
            help.push_back(bi);
            help.push_back(ci);
        }
        else{
            cin >> ai >> bi;
            help.push_back(ai);
            help.push_back(bi);
        }
        ask.push_back(help);
    }
    for (int i=0;i<4*n;i++){
        rmq.push_back(CONST);
        mins.push_back(0);
    }
    for (int i=0;i<n;i++){
        data.push_back(CONST);
        ch.push_back(false);
    }
    for (int i=0;i<m;i++){
        if (ask[i][0] == 1){
            change(0, 0, n, ask[i][1] - 1, ask[i][2], ask[i][3]);
        }
        else{
            minim = CONST;
            if (!ch[ask[i][1] - 1]){
                result(0, 0, n, ask[i][1] - 1);
                data[ask[i][1] - 1] = minim;
                ch[ask[i][1] - 1] = true;
            }
        }
    }
    for (int i=0;i<n;i++){
        if (!ch[i]){
            minim = CONST;
            result(0, 0, n, i);
            data[i] = minim;
        }
    }
    create(0, 0, n);
    for (int i=0;i<m;i++){
        if (ask[i][0] == 1){
            minim = -CONST;
            wanted = ask[i][3];
            counter = 0;
            get_result(0, 0, n, ask[i][1] - 1, ask[i][2]);
            if (minim != wanted) {cout << "NO" << endl; return 0;}
            if (counter > 1){
                cans.insert(ask[i][3]);
            }
        }
        else{
            new_element(0, 0, n, ask[i][1] - 1, ask[i][2]);
        }
    }
    for (int i=0;i<n;i++){
        if (!cans.count(data[i])) continue;
        if (!can.count(data[i])){
            can[data[i]] = 1;
        }
        else can[data[i]] ++;
    }
    int cc = 1;
    for (int i=0;i<30;i++){
        steps.push_back(cc);
        bits.push_back(false);
        cc *= 2;
    }
    for (int i=0;i<n;i++){
        if (data[i] == CONST) continue;
        if (cans.count(data[i])){
            if (can[data[i]] >= 2){
                int old = data[i];
                for (int j=29;j>=0;j--){
                    int ba = steps[j] & data[i];
                    if (ba != 0){
                        data[i] = steps[j] - 1;
                        for (int k=j;k>=0;k--){
                            bits[k] = true;
                        }
                        break;
                    }
                }
                cans.erase(old);
                can.erase(old);
            }
            else{
                int new_el = 0;
                for (int j=29;j>=0;j--){
                    int ba = steps[j];
                    if (ba + new_el <= data[i] && !bits[j]){
                        bits[j] = true;
                        new_el += ba;
                    }
                }
                data[i] = new_el;
            }
        }
        else{
            for (int j=29;j>=0;j--){
                int ba = steps[j] & data[i];
                if (ba != 0){
                    bits[j] = true;
                }
            }
        }
    }
    for (int i=0;i<n;i++){
        if (data[i] != CONST) continue;
        data[i] -= 5;
        int na = 0;
        for (int j=29;j>=0;j--){
            int pa = steps[j];
            if (pa + na <= data[i] && !bits[j]){
                na += pa;
                bits[j] = true;
            }
        }
        data[i] = na;
    }
    cout << "YES" << endl;
    for (int i=0;i<n;i++){
        cout << data[i] << " ";
    }
    return 0;
}