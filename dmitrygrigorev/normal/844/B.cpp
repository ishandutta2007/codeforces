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
#include <queue>
#include <ctime>
#define int long long
using namespace std;
int32_t main(){
    int n, m;
    cin >> n >> m;
    int matrix[n][m];
    for (int i=0; i < n; i++){
        for (int j=0; j < m; j++){
            cin >> matrix[i][j];
        }
    }
    int ans = 0;
    for (int i=0; i < n; i++){
        int wh = 0;
        int bl = 0;
        for (int j=0; j < m; j++){
            wh += (matrix[i][j] == 0);
            bl += (matrix[i][j] == 1);
        }
        ans += (1LL << wh) - 1;
        ans += (1LL << bl) - 1;
    }
    for (int i=0; i < m; i++){
        int wh = 0;
        int bl = 0;
        for (int j=0; j < n; j++){
            wh += (matrix[j][i] == 0);
            bl += (matrix[j][i] == 1);
        }
        ans += (1LL << wh) - 1;
        ans += (1LL << bl) - 1;
    }
    cout << ans - n*m << endl;
}