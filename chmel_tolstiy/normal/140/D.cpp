#include <iostream>
#include <cstdio>
#include <cmath>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;


pair<int, int> solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    int cnt = 0;
    int cost = 0;

    int rem = 710;

    for (int i = 0; i < n; i++) if (a[i] <= rem) {
        cnt += 1;
        rem -= a[i];
        cost -= -max(0, 360 - rem);
    }

    return make_pair(cnt, cost);
}

int main() {

    pair<int, int> r = solve();
    
    cout << r.first << ' ' << r.second << endl;

    return 0;
}