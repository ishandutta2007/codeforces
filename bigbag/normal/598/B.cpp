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

const int max_n = 11111, inf = 1111111111;

int n, l, r, k;
string s, q;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> s >> n;
    while (n--) {
        cin >> l >> r >> k;
        --l;
        --r;
        k %= (r - l + 1);
        q = s.substr(0, l) + s.substr(r - k + 1, k) + s.substr(l, r - k + 1 - l);
        if (r < s.length()) {
            q += s.substr(r + 1);
        }
        s = q;
    }
    cout << s << endl;
    return 0;
}