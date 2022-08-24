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
#include <deque>
#define int long long
#define D long double
using namespace std;
bool who(int f, int s){
    if (f == 0 && s == 2) return true;
    if (f == 1 && s == 0) return true;
    if (f == 2 && s == 1) return true;
    return false;
}
int32_t main(){
    int k, a, b;
    cin >> k >> a >> b;
    a--;
    b--;
    int al[3][3], bob[3][3];
    for (int i=0; i < 3; i++){
        for (int j=0; j < 3; j++){
            cin >> al[i][j];
            al[i][j]--;
        }
    }
    for (int i=0; i < 3; i++){
        for (int j=0; j < 3; j++){
            cin >> bob[i][j];
            bob[i][j]--;
        }
    }
    int ap = 0, bp=0;
    map<pair<int, int>, int > mm;
    int mv = 0, diff, w1, w2;
    int win[1000];
    while (true){
        if (mv == k) break;
        if (mm.count(make_pair(a, b))){
            diff = mv - mm[make_pair(a, b)];
            break;
        }
        else{
            bool ww = who(a, b);
            if (ww) ap++;
            else if (a != b) bp++;
            int la = a, ba = b;
            mm[make_pair(a, b)] = mv;
            if (ww) win[mv] = 2;
            else if (a != b) win[mv] = 1;
            else win[mv] = 0;
            a = al[la][ba];
            b = bob[la][ba];
            mv++;
        }
    }
    if (mv == k){
        cout << ap << " " << bp << endl;
    }
    else{
        int www = 0, wb = 0;
        for (int i=0; i < diff; i++){
            www += (win[mv-i-1] == 2);
            wb += (win[mv-i-1] == 1);
        }
        int ost = (k - mv) / diff;
        ap += ost * www;
        bp += ost * wb;
        int has = (k-mv) % diff;
        for (int i=0; i < has; i++){
            ap += (win[mv-diff+i] == 2);
            bp += (win[mv-diff+i] == 1);
        }
        cout << ap << " " << bp << endl;
    }
    return 0;
}