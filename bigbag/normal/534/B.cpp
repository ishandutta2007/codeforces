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

int ans, a, b, t, d;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> a >> b >> t >> d;
    for (int i = 0; i < t; ++i) {
        //cout << a << endl;
        ans += a;
        if (i + 2 == t) {
            a = b;
        } else {
            int o = (t - i - 2) * d;
            //cout << i << "  " << o << endl;
            for (int k = d; k >= -d; --k) {
                if (a + k - o <= b) {
                    a += k;
                    break;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}