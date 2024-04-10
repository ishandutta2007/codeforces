#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }
    v.push_back(1000000000);
    map<int, int> h;
    int sum = 0;
    for (int i=0; i<m; i++) {
        int x1, x2, y;
        cin >> x1 >> x2 >> y;
        if (x1 == 1) {
            h[x2]++;
            sum++;
        }
    }
    sort(v.begin() , v.end());
    int ans = INT_MAX;
    for (int i=0; i<=n; i++) {
        while (! h.empty() && h.begin()->first < v[i]) {
            sum -= h.begin()->second;
            h.erase(h.begin());
        }
        if (i + sum < ans)
            ans = i + sum;
    }
    cout << ans;
}