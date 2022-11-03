#include <cstdio>
#include <cstring>

#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <map>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;

const int max_int = (1LL << 31) - 1;

//#define LOCAL

#ifdef LOCAL
#include <fstream>
ifstream cin("input.txt");
ofstream cout("output.txt");
#else
#include <iostream>
#endif

const int max_n = 1e3 + 100;

struct point {
    int x, y, t;
    double p;
};

int n;
point a[max_n];
double c[max_n];

bool cmp(const point& a, const point& b) {
    return (a.t < b.t);
}

bool may(int s, int f) {
    return ((a[s].x - a[f].x) * (a[s].x - a[f].x) + (a[s].y - a[f].y) * (a[s].y - a[f].y)
             <= 1LL * (a[s].t - a[f].t) * (a[s].t - a[f].t));
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin >> n;
    for (int i = 0; i < n; ++i) 
        cin >> a[i].x >> a[i].y >> a[i].t >> a[i].p;
    sort(a, a + n, cmp);
    for (int i = 0; i < n; ++i) {
        c[i] = a[i].p;
        for (int j = 0; j < i; ++j)
            if (may(j, i) && c[j] + a[i].p > c[i]) {
                c[i] = c[j] + a[i].p;
            }
    }
    double ans = 0.0;
    for (int i = 0; i < n; ++i)
        ans = max(ans, c[i]);
    cout << fixed << setprecision(15) << ans << endl;
    return 0;
}