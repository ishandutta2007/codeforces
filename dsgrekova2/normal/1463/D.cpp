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

int solve(vector<int> a){
    int res = 0;
    for (int i = 0; i < a.size(); ++i) {
        res = max(res, (i + 1) * 2 - a[i]);
    }
    return res;
}
int solve2(vector<int> a, int n){
    int res = 0;
    for (int i = 0; i < a.size(); ++i) {
        res = max(res, (i + 1) * 2 - (n * 2 - a[i] + 1));
    }
    return res;
}
void PolnalyubviTop(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &i : a)
        cin >> i;
    int r1 = solve(a);
    reverse(a.begin(), a.end());
    int r2 = n - solve2(a, n);
    cout << max(r2 - r1 + 1, 0ll) << endl;
}


signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        PolnalyubviTop();
    }
}