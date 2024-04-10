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
    int a, b, c;
    cin >> a >> b >> c;
    int t = (a + b + c) / 9;
    if((a + b + c) % 9 != 0){
        cout << "NO\n";
        return;
    }
    if(min(a,min(b, c)) >= t)
        cout << "YES\n";
    else
        cout << "NO\n";
}


signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        PolnalyubviTop();
    }
}