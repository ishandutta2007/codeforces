#include <bits/stdc++.h>

using namespace std;

map<int, int> X, Y;
map<pair<int, int>, int> XY;

int main() {
    int n;
    cin >> n;
    while(n--) {
        int x, y;
        cin >> x >> y;
        X[x] += 1;
        Y[y] += 1;
        XY[{x, y}] += 1;
    }

    long long cnt = 0;
    for(auto x : X) {cnt += 1LL * x.second * (x.second - 1);}
    for(auto x : Y) {cnt += 1LL * x.second * (x.second - 1);}
    for(auto x : XY) {cnt -= 1LL * x.second * (x.second - 1);}
    cout << cnt / 2;
    return 0;

}