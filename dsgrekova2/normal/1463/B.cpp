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
    vector<int> a(n);
    for(auto &i : a)
        cin >> i;
    int s1=0, s2 = 0;
    for (int i = 0; i < n; ++i) {
        if(i % 2)
            s1 += a[i];
        else
            s2 += a[i];
    }
    int t;
    if(s1 < s2)
        t = 0;
    else
        t = 1;
    for (int i = 0; i < n; ++i) {
        if(i % 2 == t)
            cout << a[i] << ' ';
        else
            cout << 1 << ' ';
    }
    cout << '\n';
}


signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        PolnalyubviTop();
    }
}