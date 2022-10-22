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
    vector<int> p(n, 0);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a[x - 1]++;
        p[x - 1] = i + 1;
    }
    for (int i = 0; i < n; ++i) {
        if(a[i] == 1){
            cout << p[i] << endl;
            return;
        }
    }
    cout << -1 << endl;
}


signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        PolnalyubviTop();
    }
}