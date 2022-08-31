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
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n, q, m;
    cin >> n >> q >> m;
    int v[n];
    for (int i=0; i < n; i++){
        cin >> v[i];
    }
    int z[q][3];
    for (int i=0; i < q; i++){
        for (int j=0; j < 3; j++){
            cin >> z[i][j];
        }
    }
    int p[m];
    for (int i=0; i < m; i++){
        cin >> p[i];
    }
    for (int i=0; i < m; i++){
        int pos = p[i];
        for (int j=q-1; j >= 0; j--){
            int type = z[j][0];
            int ll = z[j][1];
            int rr = z[j][2];
            if (pos < ll || pos > rr) continue;
            if (type == 1){
                pos--;
                if (pos < ll) pos = rr;
            }
            else{
                int summ = ll + rr;
                pos = summ - pos;
            }
        }
        cout << v[pos-1] << " ";
    }
    return 0;
}