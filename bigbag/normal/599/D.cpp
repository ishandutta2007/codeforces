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

const int max_n = 1, inf = 1011111111;

long long x;
vector<pair<long long, long long> > v1, v2;

long long f(long long x) {
    return (x * (x + 1) * (2 * x + 1)) / 6;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%I64d", &x);
    for (long long i = 1; ; ++i) {
        long long res = f(i);
        if (res > x) {
            break;
        }
        res = x - res;
        res *= 2;
        long long d = (i * (i + 1));
        //cout << "     " << i << " " << res << " " << d << " " << sq << endl;
        if (res % d == 0) {
            long long a = res / d;
            v1.push_back(make_pair(i, i + a));
            if (a != 0) {
                v2.push_back(make_pair(a + i, i));
            }
        }
    }
    reverse(v2.begin(), v2.end());
    printf("%d\n", v1.size() + v2.size());
    for (int i = 0; i < v1.size(); ++i) {
        printf("%I64d %I64d\n", v1[i].first, v1[i].second);
    }
    for (int i = 0; i < v2.size(); ++i) {
        printf("%I64d %I64d\n", v2[i].first, v2[i].second);
    }
    return 0;
}