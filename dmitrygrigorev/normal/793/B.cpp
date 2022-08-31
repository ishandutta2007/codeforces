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
#define int long long
using namespace std;
int n, m, x, y, fx, fy;
char matrix[1000][1000];
char s;
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cin >> s;
            matrix[i][j] = s;
            if (s == 'S'){
                x = i;
                y = j;
            }
            if (s == 'T'){
                fx = i;
                fy = j;
            }
        }
    }
    for (int vert=0;vert<m;vert++){
        bool yes = true;
        for (int p=min(vert, y);p<=max(vert, y);p++){
            if (matrix[x][p] == '*') yes=false;
        }
        for (int p=min(fx, x);p<=max(fx, x);p++){
            if (matrix[p][vert] == '*') yes=false;
        }
        for (int p=min(vert, fy);p<=max(vert, fy);p++){
            if (matrix[fx][p] == '*') yes=false;
        }
        if (!yes) continue;
        cout << "YES" << endl;
        return 0;
    }
    for (int vert=0;vert<n;vert++){
        bool yes = true;
        for (int p=min(vert, x);p<=max(vert, x);p++){
            if (matrix[p][y] == '*') yes=false;
        }
        for (int p=min(fy, y);p<=max(fy, y);p++){
            if (matrix[vert][p] == '*') yes=false;
        }
        for (int p=min(vert, fx);p<=max(vert, fx);p++){
            if (matrix[p][fy] == '*') yes=false;
        }
        if (!yes) continue;
        cout << "YES" << endl;
        return 0;
    }
    cout << "NO" << endl;
    return 0;
}