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
    int n;
    cin >> n;
    if (n >= 0) {
        cout << n << endl;
    } else {
        int a = n / 10;
        int b = n / 100 * 10 - (-n) % 10;
        cout << (a > b ? a : b) << endl;
    }
    
    
    
    return 0;
}