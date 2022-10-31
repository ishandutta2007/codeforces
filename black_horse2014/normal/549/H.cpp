#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <iostream>
#include <cassert>

using namespace std;

typedef long long LL;
typedef double DB;
typedef pair<int, int> PII;
typedef vector<int> VI;

#define X first
#define Y second
#define pb push_back
#define EPS 1e-9
#define eps 1e-20
#define INF 1e300

typedef long double LD;
double a, b, c, d;

bool can(long double mid) {
    LD a = ::a, b = ::b, c = ::c, d = ::d;
    long double M1, m1, M2, m2;
    M1 = M2 = -INF;
    m1 = m2 = INF;
    M1 = max(M1, LD(a - mid) * (d - mid));
    M1 = max(M1, LD(a - mid) * (d + mid));
    M1 = max(M1, LD(a + mid) * (d - mid));
    M1 = max(M1, LD(a + mid) * (d + mid));

    m1 = min(m1, LD(a - mid) * (d - mid));
    m1 = min(m1, LD(a - mid) * (d + mid));
    m1 = min(m1, LD(a + mid) * (d - mid));
    m1 = min(m1, LD(a + mid) * (d + mid));
    
    M2 = max(M2, LD(b - mid) * (c - mid));
    M2 = max(M2, LD(b - mid) * (c + mid));
    M2 = max(M2, LD(b + mid) * (c - mid));
    M2 = max(M2, LD(b + mid) * (c + mid));

    m2 = min(m2, LD(b - mid) * (c - mid));
    m2 = min(m2, LD(b - mid) * (c + mid));
    m2 = min(m2, LD(b + mid) * (c - mid));
    m2 = min(m2, LD(b + mid) * (c + mid));
    
    if (M2 + eps < m1) return 0;
    if (M1 + eps < m2) return 0; 
    return 1;
}

int main() {
    
    int i, j, k;
    long double st, en, mid;
    
    scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
    st = 0.0; en = 1e10;
    while (fabs(st - en) > EPS) {
        mid = (st + en) * 0.5;
        if (can(mid)) en = mid;
        else st = mid;
    }
    printf("%.10lf\n", DB(en));
    
    return 0;   
}