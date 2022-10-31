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

int* fp;
int* sp;

int main() {
    sciid(n, q);
    int n2 = n / 2;
    fp = new int[n2];
    sp = new int[n2];
    for (int i = 0; i < n2; i++) {
        fp[i] = i * 2;
        sp[i] = i * 2 + 1;
    }

    int fc = 0, sc = 0;

    for (int i = 0; i < q; i++) {
        scid(t);
        if (t == 1) {
            scid(x);
            x = -x;
            if (x < 0) {
                x += n;
            }
            if (x & 1) {
                int df = (x + 1) / 2;
                int ds = x - df;
                fc = (fc + df) % n2;
                sc = (sc + ds) % n2;
                swap(fp, sp);
                swap(fc, sc);
            } else {
                int df = x / 2;
                int ds = x - df;
                fc = (fc + df) % n2;
                sc = (sc + ds) % n2;
            }

        } else {
            swap(fp, sp);
            swap(fc, sc);
        }
    }
//    if (ff) {
//        for (int i = 0; i < n2; i++) {
//            printf("%d %d ", fp[(cp + i) % n2] + 1, sp[(cp + i) % n2] + 1);
//        }
//    } else {
//        printf("%d ", sp[cp] + 1);
//        for (int i = 1; i < n2; i++) {
//            printf("%d %d ", fp[(cp + i) % n2] + 1, sp[(cp + i) % n2] + 1);
//        }
//        printf("%d ", fp[cp] + 1);
//    }

    for (int i = 0; i < n; i++) {
        if (i & 1) {
            printf("%d ", sp[(sc + i / 2) % n2] + 1);
        } else {
            printf("%d ", fp[(fc + i / 2) % n2] + 1);
        }
    }


    return 0;
}