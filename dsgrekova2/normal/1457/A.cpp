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
int dst(pair<int, int> a, pair<int, int> b){
    return abs(a.first - b.first) + abs(a.second - b.second);
}
void PolnalyubviTop(){
    int n, m;
    pair<int, int> crd;
    cin >> n >> m >> crd.first >> crd.second;
    cout << max(max(dst(crd, {n,m}), dst(crd, {1,m})), max(dst(crd, {n,1}), dst(crd, {1,1}))) << endl;
}


signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        PolnalyubviTop();
    }
}