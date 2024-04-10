#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAXN = 100100;
const int MAXM = 1100;
const int INF = 2000000000;

int x[MAXN], y[MAXN], z[MAXN];

bool check(int xx, int yy, int zz) {
    if (xx == yy && xx == zz) {
        return true;
    } else
    if (xx == yy + 1 && yy == zz) {
        return true;
    } else 
    if (xx == yy && yy == zz + 1) {
        return true;
    } 
    return false;
}


int main() {
    string s;
    cin >> s;
    int m = s.size();
    for (int i = 1; i <= m; ++i) {
        x[i] = x[i-1];
        y[i] = y[i-1];
        z[i] = z[i-1];
        if (s[i-1] == 'x') ++x[i];
        if (s[i-1] == 'y') ++y[i];
        if (s[i-1] == 'z') ++z[i];
    }
    
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        int xx = x[b] - x[a-1];
        int yy = y[b] - y[a-1];
        int zz = z[b] - z[a-1];
        if (a + 2 > b || check(zz, yy, xx) || check(xx, zz, yy) || check(yy, xx, zz)) {
            cout << "YES" << endl;
        } else
            cout << "NO" << endl;
        
    }
    
    
    return 0;
}