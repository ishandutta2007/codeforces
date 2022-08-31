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
using namespace std;
int t[1000][5];
bool checker(int p1, int p2, int p3){
    int v1[5], v2[5];
    for (int i=0; i < 5; i++){
        v1[i] = t[p2][i] - t[p1][i];
        v2[i] = t[p3][i] - t[p1][i];
    }
    int sc = 0;
    for (int i=0; i < 5; i++){
        sc += v1[i] * v2[i];
    }
    if (sc <= 0) return true;
    return false;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i=0; i < n; i++){
        for (int j=0; j < 5; j++){
            cin >> t[i][j];
        }
    }
    if (n == 1){
        cout << 1 << endl;
        cout << 1 << endl;
        return 0;
    }
    if (n == 2){
        cout << 2 << endl;
        cout << 1 << " " << 2 << endl;
        return 0;
    }
    int vars[n];
    for (int i=0; i < n; i++){
        vars[i] = 0;
    }
    for (int i=0; i < n; i++){
        int a = i;
        int b = (i+1) % n;
        int c = (i+2) % n;
        bool r1 = checker(a, b, c);
        bool r2 = checker(b, a, c);
        bool r3 = checker(c, b, a);
        if (r1) vars[a]++;
        if (r2) vars[b]++;
        if (r3) vars[c]++;
    }
    int cand = -1;
    for (int i=0; i < n; i++){
        if (vars[i] == 3) cand = i;
    }
    if (cand == -1){
        cout << 0 << endl;
        return 0;
    }
    for (int i=0; i < n; i++){
        for (int j=0; j < n; j++){
            if (i == cand || j == cand || i == j) continue;
            if (!checker(cand, i, j)){
                cout << 0 << endl;
                return 0;
            }
        }
    }
    cout << 1 << endl;
    cout << cand+1 << endl;
    return 0;
}