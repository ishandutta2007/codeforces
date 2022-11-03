#include <cstdio>

#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <map>
using namespace std;

#ifndef ONLINE_JUDGE
ifstream cin("input.txt");
ofstream cout("output.txt");
#else
#include <iostream>
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;

const int max_n = 2e5 + 100;

int n, s;
ll a[max_n], t[max_n];
ll sum;

int main() {
    sum = 0;
    s = 1;
    for (scanf("%d", &n); n; --n) {
        int tp;
        scanf("%d", &tp);
        if (tp == 1) {
            int xi, ai;
            scanf("%d%d", &ai, &xi);
            t[ai - 1] += xi;
            sum += xi * ai;
        } else if (tp == 2) {
            int ki;
            scanf("%d", &ki);
            a[s] = ki;
            t[s] = 0;
            ++s;
            sum += ki;
        } else {
            sum -= t[s - 1];
            sum -= a[s - 1];
            --s;
            t[s - 1] += t[s];
        }
        printf("%.6lf\n", 1.0 * sum / s);
    }
    
    return 0;
}