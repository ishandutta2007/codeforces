#include <algorithm>
#include <cmath>
#include <complex>
#include <cstdio>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define MOD 1000000007
#define MOD2 998244353
#define PRIM 3
#define INF (1 << 29)
#define LINF (1LL << 60)
#define EPS (1e-10)
#define PI 3.1415926535897932384626433832795028
typedef long long Int;
typedef pair<Int, Int> P;
typedef long double Real;
typedef complex<Real> CP;

int main()
{
    Int sgn = 1;
    Int n;
    vector<P> terms;
    while (true) {
        scanf(" %*c");
        terms.push_back(P(sgn, 0));
        char c;
        scanf(" %c", &c);
        if (c == '+') {
            sgn = 1;
        }
        else if (c == '-') {
            sgn = -1;
        }
        else {
            scanf(" %lld", &n);
            break;
        }
    }
    Int now = 0;
    for (auto &p : terms) {
        if (p.first == 1)
            p.second = 1;
        else
            p.second = n;
        now += p.first * p.second;
    }
    for (auto &p : terms) {
        Int x = min(n - now, n - 1);
        if (x < 0)
            goto ng;
        if (p.first == 1)
            p.second += x;
        else
            p.second -= x;
        now += x;
    }
    if (n != now) {
    ng:
        puts("Impossible");
    }
    else {
        puts("Possible");
        bool first = true;
        for (auto p : terms) {
            if (first) {
                printf("%lld ", p.second);
                first = false;
            }
            else {
                if (p.first == 1)
                    printf("+ ");
                if (p.first == -1)
                    printf("- ");
                printf("%lld ", p.second);
            }
        }
        printf("= %lld\n", n);
    }
    return 0;
}