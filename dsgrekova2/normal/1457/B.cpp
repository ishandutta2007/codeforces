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
    int n, k;
    cin >> n >> k;
    vector<int> a(n, 0);
    for(auto &i : a)
        cin >> i;
    int res = INT_MAX;
    for (int num = 1; num < 101; ++num) {
        int kn = 0, resn = 0;
        for (int i = 0; i < n; ++i) {
            if(kn == 0 and a[i] == num)
                continue;
            kn++;
            if(kn == k){
                kn = 0;
                resn++;
            }
        }
        if(kn != 0)
            resn++;
        res = min(resn, res);
    }
    cout << res << endl;
}


signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        PolnalyubviTop();
    }
}