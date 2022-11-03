#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

const int max_s = 20;

char s[max_s];
int a, d;
int n;

int get_int(char* s) {
    int ans = 0;
    int i = 0;
    int len = strlen(s);
    while (i < len && s[i] != '.') {
        ans = ans * 10 + s[i] - '0';
        ++i;
    }
    ans *= 10000;
    if (i < len && s[i] == '.') {
        if (i + 1 < len) ans += (s[i + 1] - '0') * 1000;
        if (i + 2 < len) ans += (s[i + 2] - '0') * 100;
        if (i + 3 < len) ans += (s[i + 3] - '0') * 10;
        if (i + 4 < len) ans += (s[i + 4] - '0');
    }
    return ans;
}

int main() {
   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
    
    while (scanf("%s", s) != EOF) {
        a = get_int(s);
        scanf("%s\n", s);
        d = get_int(s);
        scanf("%d\n", &n);
        if (4LL * a <= d) {
            d %= 4 * a;
        }
        int y = 0, x = 0;
        for (int i = 0; i < n; ++i) {
            int od = d;
            for (int j = 0; j < 10; ++j) {
                if (y == 0 && x < a) {
                    if (a - x <= od) {
                        od -= a - x;
                        x = a;
                    } else {
                        x += od;
                        od = 0;
                    }
                } else if (x == a && y < a) {
                    if (a - y <= od) {
                        od -= a - y;
                        y = a; 
                    } else {
                        y += od;
                        od = 0;
                    }
                } else if (y == a && x > 0) {
                    if (x <= od) {
                        od -= x;
                        x = 0;
                    } else {
                        x -= od;
                        od = 0;
                    }
                } else {
                    if (y <= od) {
                        od -= y;
                        y = 0;
                    } else {
                        y -= od;
                        od = 0;
                    }
                }
            }
            printf("%d.%04d %d.%04d\n", x / 10000, x % 10000, y / 10000, y % 10000);
        }
    }

    return 0;
}