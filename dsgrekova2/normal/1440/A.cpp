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
    int n, c0, c1, h;
    cin >> n >> c0 >> c1 >> h;
    c0 = min(c0, c1 + h);
    c1 = min(c1, c0 + h);
    string s;
    cin >> s;
    int a0 = 0, a1 = 0;
    for(auto &i : s){
        if(i == '0')
            a0++;
        else
            a1++;
    }
    cout << a0 * c0 + a1 * c1 << '\n';

}


signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        PolnalyubviTop();
    }
}