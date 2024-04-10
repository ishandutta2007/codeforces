//*
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <map>
#include <set>
#include <time.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#pragma warning(disable:4996)
using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <char, char> pcc;
typedef pair <int, char> pic;
typedef pair <int, ll> pil;
typedef pair <ll, int> pli;

const int IT_MAX = 32768;
const int MOD = 1000000007;
const int INF = 1234567891;
const ll LL_INF = 1234567890123456789ll;

bool isEqual(double x, double y) {
    if (abs(x - y) <= (1E-12)*max(max(abs(x), abs(y)), 1.0)) return true;
    else return false;
}

bool isPositive(double x) {
    if (x >= -1E-8) return true;
    else return false;
}
int main() {
    double a, b, c, d;
    scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
    if (isEqual(a*d, b*c)) {
        printf("0");
        return 0;
    }

    if (isPositive(a*d) ^ isPositive(b*c)) {
        a = abs(a);
        b = abs(b);
        c = abs(c);
        d = abs(d);
        double mn = min(min(a, d), min(b, c));
        if (isEqual(mn,min(b, c))) {
            swap(a, b);
            swap(c, d);
        }
        b -= mn;
        c -= mn;
        if (isEqual(a, mn)) {
            a = 0;
            d += mn;
        }
        else {
            d = 0;
            a += mn;
        }
        printf("%.20lf", mn + abs(a*d - b*c) / (a + b + c + d));
    }
    else {
        a = abs(a);
        b = abs(b);
        c = abs(c);
        d = abs(d);
        printf("%.20lf", abs(a*d - b*c) / (a + b + c + d));
    }
    return 0;
}

//*/