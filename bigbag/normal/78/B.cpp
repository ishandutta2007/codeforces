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

const int max_n = 111, inf = 1111111111;
const char c[] = {'R', 'O', 'Y', 'G', 'B', 'I', 'V'};

int n;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i + n % 7 < n; ++i) {
        printf("%c", c[i % 7]);
    }
    if (n % 7 == 1) {
        printf("%c", c[3]);
    }
    if (n % 7 == 2) {
        printf("%c%c", c[3], c[4]);
    }
    if (n % 7 == 3) {
        printf("%c%c%c", c[3], c[4], c[5]);
    }
    if (n % 7 == 4) {
        printf("%c%c%c%c", c[3], c[4], c[5], c[6]);
    }
    if (n % 7 == 5) {
        printf("%c%c%c%c%c", c[0], c[3], c[4], c[5], c[6]);
    }
    if (n % 7 == 6) {
        printf("%c%c%c%c%c%c", c[0], c[1], c[3], c[4], c[5], c[6]);
    }
    return 0;
}