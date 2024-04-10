#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>

using namespace std;

typedef long long ll;

const int max_n = 2e6 + 10;
const int max_log = 20;

int n;
int a[max_n];
ll imax[max_log], icur[max_log];

pair<int, int> b[max_n];
int k;

void build()
{
    for (int i = 0; i < n; ++i) {
        imax[i] = icur[i] = 0;
        for (int spos = 0; spos < (1 << n); spos += (1 << (i + 1))) {
            k = (1 << (i + 1));
            for (int pos = spos; pos < spos + k; ++pos) {
                b[pos - spos].first = a[pos];
                b[pos - spos].second = (pos < spos + (1 << i) ? 0 : 1);
            }
            sort(b, b + k);
            int t = 0;
            ll inv1 = 0;
            for (int pos = 0; pos < k; ++pos)
                if (b[pos].second == 1)
                    ++t;
                else
                    inv1 += t;
            ll inv2 = 0;
            for (int pos = 0; pos < k; ++pos) {
                int ps1 = pos;
                int ps2 = pos;
                while (ps2 + 1 < k && b[ps2 + 1].first == b[ps2].first) ++ps2;
                reverse(b + ps1, b + ps2 + 1);
            }
            t = 0;
            for (int pos = 0; pos < k; ++pos)
                if (b[pos].second == 0) 
                    ++t;
                else
                    inv2 += t;
            imax[i] += inv1 + inv2;
            icur[i] += inv1;
        }
    }
}

void query(int q) 
{
    for (int i = 0; i <= q; ++i) {
        icur[i] = imax[i] - icur[i];
    }
}

int main()
{
 //   freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);
 
    scanf("%d", &n);
    for (int i = 0; i < (1 << n); ++i) scanf("%d", a + i);
    
    build();
    
    int m;
    for (scanf("%d", &m); m; --m) {
        int q;
        scanf("%d", &q);
        if (q != 0) {
            --q;
            query(q);
        }
        ll all = 0;
        for (int i = 0; i < n; ++i)
            all += icur[i];
        printf("%I64d\n", all);
    }
    return 0;
}