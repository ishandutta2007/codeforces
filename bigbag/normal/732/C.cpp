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

const int max_n = 1, inf = 1111111111;

long long a, b, c, ans = -1;

bool get_bit(int x, int poz) {
    return (bool) (x & (1 << poz));
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> a >> b >> c;
    for (int q = 0; q < 4; ++q) {
        for (int w = 0; w < 4; ++w) {
            for (int mask1 = 0; mask1 < (1 << 3); ++mask1) {
                for (int mask2 = 0; mask2 < (1 << 3); ++mask2) {
                    long long res = 0;
                    for (int i = 0; i < 3; ++i) {
                        if (get_bit(mask1, i) && i < q) {
                            res = -1;
                            break;
                        }
                        if (get_bit(mask2, i) && i >= w) {
                            res = -1;
                            break;
                        }
                    }
                    if (res == -1) {
                        continue;
                    }
                    long long aa[3];
                    aa[0] = a;
                    aa[1] = b;
                    aa[2] = c;
                    for (int i = q; i < 3; ++i) {
                        aa[i] -= get_bit(mask1, i);
                        res += 1 - get_bit(mask1, i);
                    }
                    for (int i = 0; i < w; ++i) {
                        aa[i] -= get_bit(mask2, i);
                        res += 1 - get_bit(mask2, i);
                    }
                    long long cnt = max({aa[0], aa[1], aa[2]});
                    res += 3 * cnt - aa[0] - aa[1] - aa[2];
                    //cout << q << " " << w << " " << mask1 << " " << mask2 << " : " << cnt << "  res = " << res << endl;
                    if (ans == -1) {
                        ans = res;
                    } else {
                        ans = min(ans, res);
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}