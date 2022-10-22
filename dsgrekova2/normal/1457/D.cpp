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
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for(auto &i : a)
        cin >> i;
    if(n > 70) {
        cout << 1 << endl;
        return;
    }
    int ans = 179;
    for (int c = 0; c < n - 1; ++c) {
        for (int l = c; l >= 0; --l) {
            for (int r = c+1; r < n; ++r) {
                int lnum = 0, rnum = 0;
                for (int i = l; i <= c; ++i) {
                    lnum ^= a[i];
                }
                for (int i = c + 1; i <= r; ++i) {
                    rnum ^= a[i];
                }
                if(lnum > rnum){
                    ans = min(ans, r - l - 1);
                }
            }
        }
    }
    if(ans == 179){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }
}


signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    PolnalyubviTop();
}