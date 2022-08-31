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
int32_t main(){
    int n, m;
    cin >> n >> m;
    char matrix[n][m];
    for (int i=0; i < n; i++){
        for (int j=0; j < m; j++){
            cin >> matrix[i][j];
        }
    }
    if (n % 3 == 0){
        set<int> only;
        bool sc = true;
        for (int i=0; i < 3; i++){
            char that = matrix[i * (n / 3)][0];
            for (int j= i * (n / 3); j < (i + 1) * (n / 3); j++){
                for (int k=0; k < m; k++){
                    if (matrix[j][k] != that){
                        sc = false;
                    }
                }
            }
            only.insert(that);
        }
        if (sc && only.size() == 3){
            cout << "YES" << endl;
            return 0;
        }
    }
    if (m % 3 == 0){
        set<int> only;
        bool sc = true;
        for (int i=0; i < 3; i++){
            char that = matrix[0][i * (m / 3)];
            for (int j= i * (m / 3); j < (i + 1) * (m / 3); j++){
                for (int k=0; k < n; k++){
                    if (matrix[k][j] != that){
                        sc = false;
                    }
                }
            }
            only.insert(that);
        }
        if (sc && only.size() == 3){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}