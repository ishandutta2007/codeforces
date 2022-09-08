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

const int max_n = 101111;
const long long inf = 1011111111111111111LL;

int n;
long long s, f, t, a[max_n];

void check() {
    long long tm = s;
    for (int i = 0; i < n; ++i) {
        if (tm + t > f) {
            break;
        }
        if (a[i] - 1 >= tm) {
            printf("%I64d\n", tm);
            exit(0);
        } else {
            tm += t;
        }
    }
    if (tm + t <= f) {
        printf("%I64d\n", tm);
        exit(0);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%I64d%I64d%I64d", &s, &f, &t);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%I64d", &a[i]);
    }
    check();
    pair<long long, long long> ans = make_pair(inf, inf);
    for (int i = 0; i < n; ++i) {
        long long tm = a[i] - 1;
        long long cnt = i;
        if (tm >= s) {
            cnt -= (tm - s) / t;
        }
        long long res = 0;
        if (i) {
            res = (cnt - 1) * t;
            if (tm >= s) {
                res += t - (tm - s) % t;
            } else {
                res += t;
            }
        }
        if (tm < s) {
            res += s - tm;
        }
        //cout << tm << " " << res << endl;
        if (tm + res + t <= f) {
            ans = min(ans, make_pair(res, tm));
        }
        while (i + 1 < n && a[i] == a[i + 1]) {
            ++i;
        }
    }
    printf("%I64d\n", ans.second);
    //printf("%I64d\n", ans.first);
    return 0;
}