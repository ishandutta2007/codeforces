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

const int max_n = 5, inf = 111111111;

int a, b, p[4];

int f(int x) {
    return (((x % p[0]) % p[1]) % p[2]) % p[3];
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> p[0] >> p[1] >> p[2] >> p[3] >> a >> b;
    int ans = 0;
    for (int i = a; i <= b; ++i) {
        sort(p, p + 4);
        int cnt = 0;
        do {
            if (f(i) == i) {
                ++cnt;
            }
        } while (next_permutation(p, p + 4));
        if (cnt >= 7) {
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}