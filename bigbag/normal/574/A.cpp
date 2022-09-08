#include <map>
#include <set>
#include <stack>
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

const int max_n = 1111;

int n, a[max_n];
multiset<int> q;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i) {
            q.insert(a[i]);
        }
    }
    int ans = 0;
    while (a[0] <= *q.rbegin()) {
        int x = *q.rbegin();
        q.erase(q.find(x));
        if (x) {
            q.insert(x - 1);
        }
        ++a[0];
        ++ans;
    }
    cout << ans << endl;
    return 0;
}