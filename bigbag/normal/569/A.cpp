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

int t, q, s;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t >> s >> q;
    int ans = 0;
    while (s < t) {
        s += s * (q - 1);
        ++ans;
    }
    cout << ans << endl;
    return 0;
}