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



int main() {
    int n, k;
    cin >> n >> k;
    if ((n - 1) * n / 2 <= k) {
        cout << "no solution" << endl;
        return 0;
    }
    for (int i = 0; i < n; ++i) cout << "0 " << i << endl;
    
    return 0;
}