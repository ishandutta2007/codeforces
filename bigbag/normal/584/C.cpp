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

int n, t, a, b;
char s1[max_n], s2[max_n], s3[max_n];

char no(char a, char b) {
    for (char c = 'a'; c <= 'z'; ++c) {
        if (c != a && c != b) {
            return c;
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%s%s", &n, &t, s1, s2);
    for (int i = 0; i < n; ++i) {
        if (s1[i] == s2[i]) {
            ++a;
        } else {
            ++b;
        }
    }
    //cout << a << " " << b << endl;
    for (int y = 0; 2 * y <= b; ++y) {
        int z = n - t - y;
        int x = t - y;
        if (x >= 0 && y >= 0 && z >= 0) {
            if (x + y == t && x + 2 * y + z == n && y + y <= b && z <= a) {
                int y1 = 0, y2 = 0, zz = 0;
                for (int i = 0; i < n; ++i) {
                    if (s1[i] == s2[i]) {
                        if (zz < z) {
                            ++zz;
                            s3[i] = s1[i];
                        } else {
                            s3[i] = no(s1[i], s2[i]);
                        }
                    } else {
                        if (y1 < y) {
                            ++y1;
                            s3[i] = s1[i];
                        } else if (y2 < y) {
                            ++y2;
                            s3[i] = s2[i];
                        } else {
                            s3[i] = no(s1[i], s2[i]);
                        }
                    }
                }
                printf("%s\n", s3);
                return 0;
            }
        }
    }
    printf("-1\n");
    return 0;
}