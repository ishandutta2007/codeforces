#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

const int MAXN = 110000;
const int MAXM = 1100;
const int INF = 2000000000;

int x[MAXN], y[MAXN];


int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> x[i];
    set<int> what;
    for (int i = n-1; i >= 0; --i) {
        what.insert(x[i]);
        y[i] = what.size();
    }
    
    for (int i = 0; i < m; ++i) {
        int a;
        cin >> a;
        cout << y[a-1] << endl;
    }
    
    return 0;
}