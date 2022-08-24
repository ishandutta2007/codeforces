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
#define int long long
using namespace std;
int32_t main() {
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    int v[n][k];
    for (int i=0; i < n; i++){
        for (int j=0; j < k; j++){
            cin >> v[i][j];
        }
    }
    for (int i=0; i < n; i++){
        bool notq = false;
        for (int j=0; j < k; j++){
            if (v[i][j] == 1) notq = true;
        }
        if (!notq){
            cout << "YES" << endl;
            return 0;
        }
    }
    for (int j=0;j < k; j++){
        bool f = false;
        bool s = false;
        for (int i=0; i < n; i++){
            int counts = 0;
            for (int m=0; m < k; m++){
                if (m == j) continue;
                counts += v[i][m];
            }
            if (v[i][j] == 0) s = true;
            if (v[i][j] == 1 && counts == 0){
                f = true;
            }
        }
        if (f && s){
            cout << "YES" << endl;
            return 0;
        }
    }
    if (k < 4){
        cout << "NO" << endl;
        return 0;
    }
    bool pp[4][4];
    for (int i=0; i < 4; i++){
        for (int j=0; j < 4; j++){
            pp[i][j] = false;
        }
    }
    for (int i=0; i < n; i++){
        int a = -1, b = -1;
        bool per = false;
        for (int j=0; j < k; j++){
            if (v[i][j] == 0) continue;
            if (a == -1){
                a = j;
            }
            else if (b == -1) b = j;
            else per = true;
        }
        if (!per && b != -1) pp[a][b] = true;
    }
    for (int i=0; i < 4; i++){
        for (int j=0; j < 4; j++){
            if (j == i) continue;
            for (int q=0; q < 4; q++){
                if (q == i || q == j) continue;
                for (int r=0; r < 4; r++){
                    if (q == r || r == j || r == i) continue;
                    if (pp[min(i, j)][max(i, j)] && pp[min(r, q)][max(r, q)]){
                        cout << "YES" << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}