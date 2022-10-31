#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cctype>
#include <utility>
#include <queue>
#include <cmath>
using namespace std;

typedef pair<int, int> pii;
typedef long long LL;
typedef vector<int> vi;
typedef vector<pii> vpii;

#define pb push_back

#define X first
#define Y second
int n, k;

int main() {

    scanf("%d%d", &n, &k);
    int a, i, x(0), st(0), en(0), y(0);
    for (i = 0; i < n; i++) {
        scanf("%d", &a);
        if (a % 2 == 0) x++;
    }
    y = n - x;
    if (n == k) {
        if (y % 2 == 1) {
            puts("Stannis");
        } else {
            puts("Daenerys");
        }
        return 0;
    }
    for (i = k + 1; i <= n; i++) {
        if ((n - i) % 2 == 0) st++;
        else en++;
    }
    if ((n - k - 1) % 2 == 0) {
        if (k % 2 == 1) {
            if (en >= y) {
                puts("Daenerys");
            } else {
                puts("Stannis");
            }
        } else {
            for (i = n; i >= k + 1; i--) {
                
                if ((n - i) % 2 == 0) {
                    if (y > x) y--;
                    else x--;
                } else {
                    if (y == x) y--;
                    if (y > x) {
                        if (x > 0) x--;
                        else y--;
                    } else {
                        if (y > 0) y--;
                        else x--;
                    }
                }
            }
            if (x == 0 || y == 0) {
                puts("Daenerys");
            } else {
                puts("Stannis");
            }
        }
        return 0;
    } else {
        if (x > st || (x <= st && k % 2 == 0)) {
            puts("Daenerys");
        } else {
            puts("Stannis");
        }
    }
    return 0;
}