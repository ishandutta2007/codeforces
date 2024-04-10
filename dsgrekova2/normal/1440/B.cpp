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
    vector<int> a(n * k, 0);
    for(auto &i : a)
        cin >> i;
    sort(a.rbegin(), a.rend());
    int colv = 0;
    int res = 0;
    for (int i = n / 2; colv < k; i += n - (n - 1) / 2) {
        //cout << a[i] << ' ';
        res += a[i];
        colv += 1;
    }
    cout << res << '\n';
}


signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        PolnalyubviTop();
    }
}