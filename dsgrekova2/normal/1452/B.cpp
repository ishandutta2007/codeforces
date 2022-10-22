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
    int maxelem = 0;
    vector<int> a(n);
    int sum = 0;
    for(auto &i : a) {
        cin >> i;
        maxelem = max(maxelem, i);
        sum += i;
    }
    int t1 = maxelem * (n - 1);
    int t2 = (sum + n - 2) / (n - 1);
    t2 *= n - 1;
    cout << max(t1, t2) - sum << '\n';
}


signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        PolnalyubviTop();
    }
}