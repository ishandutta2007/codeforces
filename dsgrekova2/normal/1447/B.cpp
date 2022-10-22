#include "list"
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>
#define int long long
using namespace std;

void PolnalyubviTop(){
    int n, m;
    int res = 0;
    int mn = 1000;
    cin >> n >> m;
    int mz = 0;
    for (int i = 0; i < n * m; ++i) {
        int k;
        cin >> k;
        if(k < 0)
            mz++;
        k = abs(k);
        mn = min(mn, k);
        res += k;
    }
    if(mz % 2 == 0)
        cout << res << endl;
    else
        cout << res - mn * 2 << endl;
}


signed main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        PolnalyubviTop();
    }
}