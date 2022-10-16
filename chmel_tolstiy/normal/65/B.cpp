#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <set>
#include <vector>
#include <cstdio>
#include <memory.h>
#include <map>
#include <cmath>

using namespace std;

int n;
int a[1<<10];
int b[1<<10][1<<12];
int f[1<<10][1<<12];

const int nn = 2011;

vector<int> g[10000];

bool solve() {
    
    for (int i = 1000; i < 10000; i++) {
        int P = 1;
        for (int j = 0; j < 4; j++, P *=10) {
            for (int k = 0; k < 10; k++) {
                int x = i / 10 / P;
                int y = i / P % 10;
                int z = i % P;
                int T = x * 10 * P + k * P + z;
                if (1000 <= T && T <= nn && T != i) {
                    g[i].push_back(T);
                }
            }
        }
    }
    
    cin >> n;
    
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    memset(b, -1, sizeof b);
    for (int i = 1000; i <= nn; i++) b[0][i] = 0;
    
    for (int i = 1; i <= n; i++) {
        int x = a[i];
        if (x <= nn) for (int j = 1000; j <= x; j++) if (b[i-1][j] >= 0) {
            if (b[i][x] < 0 || b[i][x] > b[i-1][j]) {
                b[i][x] = b[i-1][j];
                f[i][x] = j;
            }
        }
        
        for (int k = 0; k < g[a[i]].size(); k++) {
            int x = g[a[i]][k];
            for (int j = 1000; j <= x; j++)  if (b[i-1][j] >= 0) {
                if (b[i][x] < 0 || b[i][x] > b[i-1][j]+1) {
                    b[i][x] = b[i-1][j]+1;
                    f[i][x] = j;
                }
            }
        }
    }
    
    int res = 1<<30;
    int x = 0;
    for (int i = 1000; i <= nn; i++) if (b[n][i] >= 0 && b[n][i] < res) {
        res = b[n][i];
        x = i;
    }
    
    if (!x) {
        cout << "No solution" << endl;
    } else {
        vector<int> res;
        for (int i = n; i > 0; i--) {
            res.push_back(x);
            x = f[i][x];
        }
        reverse(res.begin(), res.end());
        for (int i = 0; i < res.size(); i++) cout << res[i] << endl;
    }
    
    return false;
}

int main() {

    solve() ;
    
    return 0;
}