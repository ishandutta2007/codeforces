#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <string>
#include <memory.h>
#include <bitset>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rea(a, n) for (int i = 0; i < n; i++) sci(a[i])

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;
typedef long double ldouble;

using namespace std;

int df(string &a, string &b) {
    int res = 0;
    for (int i = 0; i < 6; i++) {
        if (a[i] != b[i]) {
            res++;
        }
    }
    return res;
}

string a[1111];

int main() {
    init_cin
    int n;
    cin >> n;
    if (n == 1) {
        cout << 6;
        return 0;
    }
    int mdf = 1e9;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int j = 0; j < i; j++) {
            mdf = min(mdf, df(a[i], a[j]));
        }
    }
    cout << (mdf - 1) / 2;

    return 0;
}