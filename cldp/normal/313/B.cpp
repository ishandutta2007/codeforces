#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAXN = 1000;
const int MAXM = 1100;
const int INF = 2000000000;


int f[110000];


int main() {
    string p;
    cin >> p;
    int m = p.size();
    for (int i = 1; i < m; ++i) 
     if (p[i] == p[i-1]) 
         f[i] = f[i-1] + 1;
     else
         f[i] = f[i-1];
    
    cin >> m;
    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        cout << f[b-1] - f[a-1] << endl;
    }
    
    
    
    return 0;
}