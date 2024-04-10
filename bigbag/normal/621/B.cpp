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

const int max_n = 111111, inf = 1111111111;

int n, x, y;
long long ans = 0;
vector<int> a, b;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    while (n--) {
        scanf("%d%d", &x, &y);
        a.push_back(x + y);
        b.push_back(x - y);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int i = 0; i < a.size(); ++i) {
        int cnt = 1;
        while (i + 1 < a.size() && a[i] == a[i + 1]) {
            ++cnt;
            ++i;
        }
        ans += cnt * (cnt - 1) / 2;
    }
    for (int i = 0; i < b.size(); ++i) {
        int cnt = 1;
        while (i + 1 < b.size() && b[i] == b[i + 1]) {
            ++cnt;
            ++i;
        }
        ans += cnt * (cnt - 1) / 2;
    }
    cout << ans << endl;
    return 0;
}