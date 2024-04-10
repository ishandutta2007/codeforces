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
#include <queue>
using namespace std;
struct Vertex{int mas[4][5][10];};
int q, type, ll, rr, x, mod, out;
string s, str;
Vertex rmq[400000];
int ost[5];
string id = "ATGC";
void create(int i, int l, int r){
    if (r - l == 1){
        int nid;
        for (int j=0; j < 4; j++){
            if (str[l] == id[j]){
                nid = j;
            }
        }
        for (int ost=0;ost<5;ost++){
            mod = ost+6;
            out = l%mod;
            rmq[i].mas[nid][ost][out]++;
        }
    }
    else{
        int mid = (l + r) / 2;
        create(2*i+1, l, mid);
        create(2*i+2, mid, r);
        for (int j=0; j < 4;j++){
            for (int k=0; k < 5; k++){
                for (int p=0;p<10;p++){
                    rmq[i].mas[j][k][p] = rmq[2*i+1].mas[j][k][p] + rmq[2*i+2].mas[j][k][p];
                }
            }
        }
    }
}
void change(int i, int l, int r, int ind, int newn, int number){
    for (int j=0;j<5;j++){
        mod = j + 6;
        out = ind % mod;
        rmq[i].mas[number][j][out]--;
        rmq[i].mas[newn][j][out]++;
    }
    if (r - l == 1) return;
    int mid = (l + r) / 2;
    if (ind < mid) change(2*i+1, l, mid, ind, newn, number);
    else change(2*i+2, mid, r, ind, newn, number);
}
int get(int i, int l, int r, int l1, int r1){
    if (l1 >= r1) return 0;
    if (l == l1 && r == r1){
        int sz = s.size();
        int ret = 0;
        int number = s.size() - 6;
        for (int j=0; j < s.size(); j++){
            int nid = 0;
            int st = (l + j - ll) % sz;
            out = (l + j) % sz;
            for (int k=0; k < 4; k++){
                if (id[k] == s[st]) nid = k;
            }
            ret += rmq[i].mas[nid][number][out];
        }
        return ret;
    }
    int mid = (l + r) / 2;
    return get(2*i+1, l, mid, l1, min(r1, mid)) + get(2*i+2, mid, r, max(l1, mid), r1);
}
signed main()
{
    cin >> str;
    for (int i=0; i < 4 * str.size(); i++){
        Vertex v;
        for (int p=0; p < 4; p++){
            for (int j=0; j < 5;j++){
                for (int k=0; k < 10; k++){
                    v.mas[p][j][k] = 0;
                }
            }
        }
        rmq[i] = v;
    }
    create(0, 0, str.size());
    cin >> q;
    for (int i=0;i<q;i++){
        cin >> type;
        char ch;
        if (type == 1){
            cin >> x >> ch;
            char last = str[x-1];
            int index = 0;
            int index1 = 0;
            for (int i=0;i<4;i++){
                if (last == id[i]){
                    index = i;
                }
                if (ch == id[i]){
                    index1 = i;
                }
            }
            str[x-1] = ch;
            change(0, 0, str.size(), x-1, index1, index);
        }
        else{
            cin >> ll >> rr >> s;
            if (s.size() == 1){
                s = s+s+s+s+s+s;
            }
            else if (s.size() == 2){
                s = s + s + s;
            }
            else if (s.size() <= 5){
                s = s + s;
            }
            ll--;
            cout << get(0, 0, str.size(), ll, rr) << endl;
        }
    }
    return 0;
}