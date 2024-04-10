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

const int max_n = 111, inf = 111111111;

int n;
vector<int> v1;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (a % 2 == 0) {
            ans += a;
        } else {
            v1.push_back(a);
        }
    }
    sort(v1.begin(), v1.end());
    reverse(v1.begin(), v1.end());
    if (v1.size() == 0) {
        cout << 0 << endl;
        return 0;
    }
    int l = v1.size();
    if (l % 2 == 0) {
        --l;
    }
    for (int i = 0; i < l; ++i) {
        ans += v1[i];
    }
    cout << ans << endl;
    return 0;
}