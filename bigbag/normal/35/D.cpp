#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 111, inf = 111111111;

int n, x, a[max_n];
multiset <int> s;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> x;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        s.insert(a[i] * (n - i));
    }
    int ans = 0, sum = 0;
    while (s.size() != 0) {
        int q = *s.begin();
        s.erase(s.find(q));
        if (sum + q <= x) {
            sum += q;
            ++ans;
        } else {
            break;
        }
    }
    cout << ans << endl;
    return 0;
}